#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char a[999];

  printf("Send a number: ");
  scanf("%s", a);

  for (int i = 0; i < strlen(a); i++) {
    if (isdigit(a[i]) == 0) {
      return 1;
    }
  }

  if (atoi(a) % 2 == 0)
    printf("Even.");
  else
    printf("Odd");

  return 0;
}
