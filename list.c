// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_alloc() { 
  list_t *l = malloc(sizeof(list_t));
  l->head = NULL;
  return l;
}
void list_free(list_t *l) {
  node_t *current = l->head;
  node_t *next;
  while (current){
    next = current->next;
    free(current);
    current = next;
  }
  free(l);
  return;
}

void list_print(list_t *l) {
	node_t *current = l->head;
	while (current){
		printf(" -> %d", current->value);
		current = current->next;
	}
	printf("\n");
}

int list_length(list_t *l) {
  if (!l) return 0;
  int count = 0;
  node_t *current = l->head;
  while(current){
    current = current->next;
    count+=1;
  }
  return count; 
}

void list_add_to_back(list_t *l, elem value) {
	node_t *previous = NULL;
	node_t *current = l->head;
	while (current){
		previous = current;
		current = current->next;
	}
	node_t *new_node = malloc(sizeof(node_t));
	new_node->value = value;
	new_node->next = NULL;
  if (!l->head){
    l->head = new_node;
  }else{
    previous->next = new_node;
  }
	return;
}
void list_add_to_front(list_t *l, elem value) {
	node_t *new_node = malloc(sizeof(node_t));
	new_node->value = value;
	node_t *temp_head = l->head;
	l->head = new_node;
	new_node->next = temp_head;
	return;
}
void list_add_at_index(list_t *l, elem value, int index) {
  int length = list_length(l);
  // if invalid index, return
  if ((index>length) || (index<0)) return;
  if (index == length) {
    list_add_to_back(l, value);
    return;
  }
  if (index == 0){
    list_add_to_front(l, value);
    return;
  }
  // create the node
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  // mark current
  node_t *current = l->head;
  // loop through till current is the correct index
  while (index!=1){
    current = current->next;
    index-=1;
  }
  // add the node after current
  node_t *next = current->next;
  current->next = new_node;
  new_node->next = next;
  return;
}

elem list_remove_from_back(list_t *l) {
  if (!l || !l->head) return;
  node_t *previous = NULL;
  node_t *current = l->head;
  while(current->next){
    previous = current;
    current = current->next;
  }
  if (!l->head->next){
    l->head = NULL;
  }else{
    previous->next = NULL;
  }
  elem value = current->value;
  free(current);
  return value; 
}

elem list_remove_from_front(list_t *l) {
  if (!l || !l->head) return;
  node_t *temp = l->head;
  l->head = l->head->next;
  elem value = temp->value;
  free(temp);
  return value;
}

elem list_remove_at_index(list_t *l, int index) {
  int length = list_length(l);
  // if invalid index, return
  if ((index>length-1) || (index<0)) return;
  if (index == length-1) {
    list_remove_from_back(l);
    return;
  }
  if (index == 0){
    list_remove_from_front(l);
    return;
  }
  // mark current
  node_t *current = l->head;
  // loop through till current is the correct index
  while (index!=1){
    current = current->next;
    index-=1;
  }
  // remove the node after current
  node_t *temp = current->next;
  node_t *next = temp->next;
  current->next = next;
  elem value = temp->value;
  free(temp);
  return value;
}

bool list_is_in(list_t *l, elem value) {
  if (!l || !l->head) return false;
  node_t *current = l->head;
  while (current){
    if (current->value == value) return true;
    current = current->next;
  }
  return false;
}

elem list_get_elem_at(list_t *l, int index) {
//   if (!l || !l->head) return NULL;
  int length = list_length(l);
//   if ((index>length-1) || (index<0)) return NULL;
  node_t *current = l->head;
  while (index!=0){
    current = current->next;
    index-=1;
  }
  return current->value;
}

int list_get_index_of(list_t *l, elem value) {
  if (!l || !l->head) return -1;
  int index = 0;
  node_t *current = l->head;
  while (current){
    if (current->value == value) return index;
    current = current->next;
    index+=1;
  }
  return -1;
}