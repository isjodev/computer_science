#include <stdio.h>
#include <stdlib.h>

// Function pointers
int addInt(int n, int m) { return n + m; }

int add2to3(int (*)(int, int));

typedef int (*myFuncDef)(int, int);

myFuncDef functionFactory(int n) {
  printf("Got parameter %d\n", n);
  myFuncDef functionPtr = &addInt;
  return functionPtr;
}

int add2to3(int (*functionPtr)(int, int)) { return (*functionPtr)(2, 3); }

// Data Structures
typedef struct String_Struct *String;

struct String_Struct {
  char *(*get)(const void *self);
  void (*set)(const void *self, char *value);
  int (*length)(const void *self);
};

// Prototypes
char *getString(const void *self);
void setString(const void *self, char *value);
int lengthString(const void *self);
String newString();

String newString() {
  String self = (String)malloc(sizeof(struct String_Struct));

  self->get = &getString;
  self->set = &setString;
  self->length = &lengthString;

  self->set(self, "");

  return self;
}

int main(void) {
  int (*functionPtr)(int, int);
  functionPtr = &addInt;
  int sum = (*functionPtr)(2, 3);
}
