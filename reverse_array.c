#include <stdio.h>
#include <string.h>

void reverse_array(int *array, size_t size) {
  int copy[size];
  memcpy(copy, array, size * sizeof(int));

  for (int i = size - 1; i >= 0; i--) {
    array[size - i - 1] = copy[i];
  }
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  size_t size = sizeof(arr) / sizeof(int);

  reverse_array(arr, size);
  for (int i = 0; i < size; i++) {
    printf("%d", arr[i]);
  }
  return 0;
}
