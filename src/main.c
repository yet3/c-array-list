#include "array-list.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(ArrayList *list) {
  for (int i = 0; i < list->len; i++) {
    printf("[%d]: %d\n", i, *(int *)ArrayList_at(list, i));
  }
}

int main() {
  ArrayList *list = ArrayList_init(5, sizeof(int));

  int ints[8] = {42, 12, 13, 14, 32, 75, 59, 91};
  for (int i = 0; i < 5; i++) {
    ArrayList_append(list, &ints[i]);
  }

  printf("\nInitial - cap: %zu, len: %zu\n", list->capicity, list->len);
  print_list(list);

  for (int i = 5; i < 8; i++) {
    ArrayList_append(list, &ints[i]);
  }
  printf("\nAppended 3 items - cap: %zu, len: %zu\n", list->capicity,
         list->len);
  print_list(list);

  ArrayList_remove(list, 4);
  printf("\nRemoved 4th item - cap: %zu, len: %zu\n", list->capicity,
         list->len);
  print_list(list);

  ArrayList_pop(list);
  printf("\nLast item poped - cap: %zu, len: %zu\n", list->capicity, list->len);
  print_list(list);

  int r = 333;
  ArrayList_replace(list, 1, &r);
  printf("\nReplaced 2ed item - cap: %zu, len: %zu\n", list->capicity,
         list->len);
  print_list(list);

  ArrayList_clear(list);
  printf("\nCleared list - cap: %zu, len: %zu\n", list->capicity, list->len);

  ArrayList_free(list);

  return 0;
}
