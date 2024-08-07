#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long fibonacci_rec(int n) {
  if (n <= 1)
    return n;
  return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}

long long fibonacci_it(int n) {
  if (n <= 1)
    return n;
  long long a = 0, b = 1, c;
  for (int i = 2; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
  }

  return b;
}

int validate_methods(char *method) {
  if (strcmp(method, "recursive") == 0 || strcmp(method, "iterator") == 0)
    return 0;
  else
    return 1;
}

int main(int argc, char *argv[]) {
  char method[99];
  int n;

  if (argc >= 3) {
    snprintf(method, sizeof(method), "%s", argv[1]);
    n = atoi(argv[2]);
  } else {
    printf("Choose a method (recursive, iterator): ");
    scanf("%s", method);

    printf("Send a number: ");
    scanf("%d", &n);
  }

  if (validate_methods(method) == 1) {
    printf("Invalid method, choose either 'recursive' or 'iterator'");
    return 1;
  }

  long long result;
  if (strcmp(method, "recursive") == 0) {
    result = fibonacci_rec(n);
  } else {
    result = fibonacci_it(n);
  }

  printf("Result: %lld", result);
  return 0;
}
