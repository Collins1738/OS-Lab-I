#include <stdio.h>

#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  list_t *l1 = list_alloc();
	list_add_to_back(l1, 2);
	list_add_to_back(l1, 3);
	list_add_to_back(l1, 87);
  printf("a %d \n", list_get_elem_at(l1, 0));
  printf("a %d \n", list_get_elem_at(l1, 1));
  printf("a %d \n", list_get_elem_at(l1, 2));
  printf("a %d \n", list_get_elem_at(l1, 3));
  list_remove_at_index(l1, 3);printf("   ha ");list_print(l1);
  return 0;
}