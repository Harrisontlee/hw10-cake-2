// ***
// *** You may modify this file but don't submit it.
// ***

#ifndef HW10_H
#define HW10_H
#include <stdlib.h>

typedef struct node {
  int value;
  struct node* next;
} ListNode;

void printListNode(ListNode* head, int* threshold);
ListNode* createList(int valn);
void eliminate(ListNode* head, int valk, int valn);
ListNode* deleteNode(ListNode* head, ListNode* todelete);
#endif
