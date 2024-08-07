#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool digit_check(char str[]) {
  for (int i = 0; i < strlen(str); i++) {
    if (isdigit(str[i]) == 0) {
      return false;
    }
  }

  return true;
}

int main(int argc, char *argv[]) {
  char a[10], b[10];

  if (argc < 3) {
    printf("Send two numbers: ");
    scanf("%s %s", a, b);
  } else {
    snprintf(a, sizeof(a), "%s", argv[1]);
    snprintf(b, sizeof(b), "%s", argv[2]);
  }

  if (digit_check(a) == false)
    return 1;
  if (digit_check(b) == false)
    return 1;

  printf("%d", atoi(a) + atoi(b));
  return 0;
}
