#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int x;
  struct Node* next;
} Node;

void insert_end(Node** root, int value) {
  Node* new_node = malloc(sizeof(Node));

  if (new_node == NULL) {
    exit(EXIT_FAILURE);
  }

  new_node->next = NULL;
  new_node->x = value;

  if (*root == NULL) {
    *root = new_node;
    return;
  }

  Node* curr = *root;
  while (curr->next != NULL) {
    curr = curr->next;
  }

  curr->next = new_node;
}

void deallocate(Node** root) {
  Node* curr = *root;
  while (curr != NULL) {
    Node* aux = curr;
    curr = curr->next;
    free(aux);
  }

  *root = NULL;
}

void insert_beginning(Node** root, int value) {
  Node* new_node = malloc(sizeof(Node));

  if (new_node == NULL) {
    exit(EXIT_FAILURE);
  }

  new_node->x = value;
  new_node->next = *root;

  *root = new_node;
}

void insert_after(Node* node, int value) {
  Node* new_node = malloc(sizeof(Node));

  if (new_node == NULL) {
    exit(EXIT_FAILURE);
  }

  new_node->x = value;
  new_node->next = node->next;
  node->next = new_node;
}

int main(int argc, char* argv[]) {
  Node* root = NULL;

  insert_end(&root, 2);
  insert_end(&root, 4);
  insert_end(&root, 5);


  insert_after(root, 3);
  insert_after(root->next->next->next, 6);

  for (Node* curr = root; curr != NULL; curr = curr->next) {
    printf("%d\n", curr->x);
  }

  deallocate(&root);

  return 0;
}
