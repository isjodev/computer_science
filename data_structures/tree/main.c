/* Thing... */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  struct node *left; 
  struct node *right; 
  char *string; 
} node; 

node *root; 

int insert(const char* string, node* root) {
  int num = strcmp(root->string, string); 
  node *temp; 

  for (;;) {
    if (0 == num) 
      return 1; 
    else if (-1 == num) {
      if (NULL == root->right) {
        temp = malloc(sizeof(node)); 
        temp->left = NULL; 
        temp->right = NULL; 
        temp->string = strdup(string); 
        return 2;
      } else 
        root = root->right; 
    } else if (NULL == root->left) {
      temp = malloc(sizeof(node)); 
      temp->left = NULL; 
      temp->right = NULL; 
      temp->string = strdup(string);
      return 2; 
    } else 
      root = root->left; 
  }
}

void print(node *root) {
  if (root->left != NULL) 
    print(root->left); 

  fputs(root->string, stdout); 
}


int main(void) {
  // Implementing a treeeeeeee...
  printf("Hello trees!\n");
  exit(EXIT_SUCCESS);
}
