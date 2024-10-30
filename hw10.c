// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include "hw10.h"

// DO NOT MODIFY this function --->>>
void printListNode(ListNode* head, int* threshold)
{
  ListNode* p = head;
  printf("printListNode: ");
  while (p != NULL)
  {
    if (p->value >= *threshold){
      printf("%7d ", p->value);
    }
    p = p->next;
  }
  printf("\n");
}
// <<<--- until here

// create a linked list storing values 0, 1, 2, ... valn - 1
ListNode* createList(int valn)
{
  ListNode* head = NULL;
  ListNode* tail = NULL;

  for (int i = 0; i < valn; i++) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
      perror("Failed to allocate memory");
      exit(EXIT_FAILURE);
    }
    newNode->value = i;
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
    } else {
      tail->next = newNode;
    }
    tail = newNode;
  }
  return head;
}

// delete the specified node
ListNode* deleteNode(ListNode* head, ListNode* toDelete)
{
  if (head == NULL || toDelete == NULL) {
    return head;
  }

  if (head == toDelete) {
    ListNode* newHead = head->next;
    free(head);
    return newHead;
  }

  ListNode* current = head;
  while (current->next && current->next != toDelete) {
    current = current->next;
  }

  if (current->next == toDelete) {
    current->next = toDelete->next;
    free(toDelete);
  }
  return head;
}

// eliminate nodes in the linked list based on the elimination count valk
// eliminate nodes in the linked list based on the elimination count valk
void eliminate(ListNode* head, int valk, int valn)
{
    int k = valn;
    if (!head || valk < 1) return;

    ListNode* current = head;
    ListNode* prev = NULL;

    while (head && head->next != head) { // Continue until one node remains
        // Traverse `valk - 1` steps to find the node to delete
        for (int i = 0; i < valk - 1; ++i) {
            prev = current;
            current = current->next ? current->next : head; // Wrap around if needed
        }
        int threshold_value = current->value;
        int* threshold = &threshold_value;
        // Print the current state of the list before deletion

        if (k > (valn + 1) - valn)
        {
          printListNode(head, threshold);
          k--;
        }
        // Print the value of the node to delete
        printf("%d\n", current->value);

        // Delete the node and update the list
        if (current == head) {
            head = head->next;  // Update head if deleting it
        } else {
            prev->next = current->next; // Link previous to next node
        }
        free(current); // Free the deleted node

        // Move to the next node after deletion
        current = prev->next ? prev->next : head;
    }

    // Print the final remaining node and free it
    free(head);
}








































































