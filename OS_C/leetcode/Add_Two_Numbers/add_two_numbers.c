#include<stdio.h>
#include<stdlib.h>


typedef struct ListNode {
     int val;
     struct ListNode *next;
}lnode;

void print_list(lnode *n) { 
  while(n){
	printf("%d -> ",n->val);
	n = n->next;
  }
  printf("NULL\n");
}

struct ListNode* addTwoNumbers(struct ListNode* l1,
							   struct ListNode* l2) {
  struct ListNode* head = l1 ? l1 : l2;
  struct ListNode res = { .next = head};
  int carrier = 0;

  while(l1 || l2) {
	carrier = ((l1?l1->val:0) + (l2?l2->val:0) + carrier);
    head->val = carrier%10;
	carrier /= 10;
	l1 = l1?l1->next:l1;
	l2 = l2?l2->next:l2;
  	head = head->next = l1?l1:(l2?l2:(carrier?(struct ListNode *)malloc(sizeof(struct ListNode)):NULL));
  }
  if(carrier){
  	head->val = carrier;
  	head->next = NULL;
  }
  return res.next;
}
struct ListNode *makeListFromChars(const char *array, int size){
  struct ListNode anchor  = { .next = NULL }, *curr = &anchor;
  int i = 0;
  for(; i < size; i++) {
	curr = curr->next = malloc(sizeof(struct ListNode));
	curr->val = array[i];
	curr->next = NULL;
  }
  return anchor.next;
}

int main()
{
  char lista1[] = {5,2,9};
  char lista2[] = {5,7};

  struct ListNode *l1 = makeListFromChars(lista1, sizeof(lista1));
  struct ListNode *l2 = makeListFromChars(lista2, sizeof(lista2));
  print_list(l1);
  print_list(l2);
  struct ListNode *l3 = addTwoNumbers(l1, l2);
  print_list(l3);
  return 0;
}
