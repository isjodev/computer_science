// Searchable sorted sets symbolic strings. 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_CHARS 256

typedef struct trie_node {
	struct trie_node *children[NUM_CHARS]; 
	bool terminal; 
} trie_node;

trie_node *create_node() {
	trie_node *new_node = malloc(sizeof *new_node); 

	for (int i = 0; i < NUM_CHARS; i++) {
		new_node->children[i] = NULL; 
	}
	new_node->terminal = false; 
	return new_node; 
}

bool trie_insert(trie_node **root, char *signed_text) {
	if (*root == NULL) {
		*root = create_node();
	}	

	unsigned char *text = (unsigned char*)signed_text; 
	trie_node *tmp = *root; 
	int length = strlen(signed_text); 
	
	for (int i = 0; i < length; i++) {
		if (tmp->children[text[i]] == NULL) {
			// Create a new node. 
			tmp->children[text[i]] = create_node();
		}
		tmp = tmp->children[text[i]]; 
	}

	if (tmp->terminal) {
		return false; 
	} else {
		tmp->terminal = true; 
		return true; 
	}
}

void print_trie_rec(trie_node* node, unsigned char *prefix, int length) {
	unsigned char new_prefix[length + 2]; 
	memcpy(new_prefix, prefix, length); 
	new_prefix[length + 1] = 0; 

	if (node->terminal) {
		printf("WORD: %s\n", prefix); 
	}

	for (int i = 0; i < NUM_CHARS; i++) {
		if (node->children[i] != NULL) {
			new_prefix[length] = i; 
			print_trie_rec(node->children[i], new_prefix, length+1);
		}
	}
}

void print_trie(trie_node *root) {
	if (root == NULL) {
		printf("Trie empty\n"); 
		return; 
	}
	print_trie_rec(root, NULL, 0); 
}

bool search_trie(trie_node* root, char* signed_text) {
	unsigned char *text = (unsigned char*)signed_text; 
	int length = strlen(signed_text); 
	trie_node* tmp = root; 

	for (int i = 0; i < length; i++) {
		if (tmp->children[text[i]] == NULL) {
			return false; 
		}
		tmp = tmp->children[text[i]]; 
	}
	return tmp->terminal; 
}

bool node_has_children(trie_node* node) {
	if (node == NULL) return false; 

	for (int i = 0; i < NUM_CHARS; i++) {
		if (node->children[i] != NULL) {
			// At least one child. 
			return true; 
		}
	}
	return false; 
}

trie_node* delete_str_rec(trie_node* node, char* text, bool *deleted) {
	if (node == NULL) return node; 

	if (*text == '\0') {
		if (node->terminal) {
			node->terminal = false; 
			*deleted = true; 

			if (node_has_children(node) == false) {
				free(node); 
				node = NULL; 
			}
		}
		return node; 
	}

	node->children[text[0]] = delete_str_rec(node->children[text[0]], text+1, deleted); 
	if (*deleted && node_has_children(node) == false && node->terminal == false) {
		free(node); 
		node = NULL; 
	}

	return node; 
}

bool delete_str(trie_node** root, char *signed_text) {
	unsigned char *text = (unsigned char*)signed_text; 
	bool result = false; 

	if (*root == NULL) return false; 

	*root = delete_str_rec(*root, text, &result); 
	return result; 
}

int main(void) {
	trie_node* root = NULL; 

	trie_insert(&root, "KIT"); 
	trie_insert(&root, "CATTLE"); 
	trie_insert(&root, "KIN"); 
	trie_insert(&root, "CAT"); 
	trie_insert(&root, "HAPPY"); 

	print_trie(root);

	printf("search for CATTLE: %d\n", search_trie(root, "CATTLE"));
	printf("search for CAT: %d\n", search_trie(root, "CAT"));
	printf("search for KITTEN: %d\n", search_trie(root, "KITTEN"));

	delete_str(&root, "KIN"); 
	delete_str(&root, "CAT"); 
	print_trie(root);

	exit(EXIT_SUCCESS); 
}
