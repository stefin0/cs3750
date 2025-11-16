#include <stdio.h>
#include <stdlib.h>

typedef struct FreeBlock {
  int start_address;
  int size;
  struct FreeBlock *next;
} FreeBlock;

typedef struct FreeList {
  FreeBlock *head;
} FreeList;

void initialize_free_list(FreeList *free_list, int total_size) {
  FreeBlock *head = (FreeBlock *)malloc(sizeof(FreeBlock));
  head->start_address = 0;
  head->size = total_size;
  head->next = NULL;
  free_list->head = head;
}

void print_free_list(FreeList *free_list) {
  FreeBlock *temp = free_list->head;
  while (temp != NULL) {
    printf(" [ %d (%d) ]", temp->start_address, temp->size);
    temp = temp->next;
    if (temp != NULL)
      printf(" ->");
  }
  printf("\n");
}

int allocate(FreeList *free_list, int requested_size) {
  FreeBlock *temp = free_list->head, *prev = NULL;

  // Find the first block that is large enough
  while (temp != NULL && temp->size < requested_size) {
    prev = temp;
    temp = temp->next;
  }

  // Case 1: No block found (or list is empty)
  if (temp == NULL) {
    return -1;
  }

  int allocated_address = temp->start_address;

  // Case 2: Block is exactly the right size
  if (temp->size == requested_size) {
    if (prev == NULL) {
      free_list->head = temp->next;
    } else {
      prev->next = temp->next;
    }
    free(temp);
  }
  // Case 3: Block is larger, so we split it
  else {
    temp->start_address += requested_size;
    temp->size -= requested_size;
  }

  return allocated_address;
}

void deallocate(FreeList *free_list, int start_address, int size) {
  FreeBlock *new_block = (FreeBlock *)malloc(sizeof(FreeBlock));
  new_block->start_address = start_address;
  new_block->size = size;

  FreeBlock *temp = free_list->head, *prev = NULL;

  // Find correct position to insert (sorted by address)
  while (temp != NULL && temp->start_address < new_block->start_address) {
    prev = temp;
    temp = temp->next;
  }

  // Insert the new block
  if (prev == NULL) {
    new_block->next = free_list->head;
    free_list->head = new_block;
  } else {
    new_block->next = temp;
    prev->next = new_block;
  }
}

void cleanup(FreeList *list) {
  FreeBlock *temp = list->head;
  FreeBlock *next = NULL;
  while (temp != NULL) {
    next = temp->next;
    free(temp);
    temp = next;
  }
  list->head = NULL;
}

int main() {
  FreeList free_list;
  initialize_free_list(&free_list, 1000);
  print_free_list(&free_list);

  int block1_address = allocate(&free_list, 100);
  int block2_address = allocate(&free_list, 200);
  int block3_address = allocate(&free_list, 150);
  print_free_list(&free_list);

  deallocate(&free_list, block2_address, 200);
  deallocate(&free_list, block1_address, 100);
  deallocate(&free_list, block3_address, 150);
  print_free_list(&free_list);

  cleanup(&free_list);

  return 0;
}
