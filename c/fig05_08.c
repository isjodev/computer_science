// Scoping.
#include <stdio.h>

// Function prototypes.
void useLocal(void);
void useStaticLocal(void);
void useGlobal(void);

int x = 1;

int main(void) {
  int x = 5;

  printf("local x in outer scope of main is %d\n", x);

  {            // Start new scope.
    int x = 7; // Variable local to new scope.
    printf("local x in inner scope of main is %d\n", x);
  } // End new scope.

  printf("local x in outer scope of main is %d\n", x);

  useLocal();       // Automatic local x.
  useStaticLocal(); // Static local x.
  useGlobal();      // Global x.
  useLocal();       // Reinitializes automatic local x.
  useStaticLocal(); // Static local x retains its prior value.
  useGlobal();      // Global x also retains its value.

  printf("\nLocal x in main is %d\n", x);
  return 0;
}

// useLocal reinitializes local variable x during each call.
void useLocal(void) {
  // Initialized each time useLocal is called.
  int x = 25;

  printf("\nLocal x in useLocal is %d after entering useLocal\n", x);
  ++x;
  printf("local x in useLocal is %d before exiting useLocal\n", x);
}

/* useStaticLocal initializes static local variable x the first
 * time the function is called; the value of x is saved between
 * calls to this function. */
void useStaticLocal(void) {
  static int x = 50;

  printf("\nLocal static x is %d on entering useStaticLocal\n", x);
  ++x;
  printf("local static x is %d on exiting useStaticLocal\n", x);
}

void useGlobal(void) {
  printf("\nglobal x is %d on entering useGlobal\n", x);
  x *= 10;
  printf("global x is %d on exiting useGlobal\n", x);
}
