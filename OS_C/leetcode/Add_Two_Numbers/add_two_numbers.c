#include<stdio.h>
#include<stdlib.h>


typedef struct ListNode {
     int val;
     struct ListNode *next;
}lnode;

struct ListNode* addTwoNumbers(struct ListNode* l1,
							   struct ListNode* l2) {
  if(l1 == NULL) return l2;
  if(l2 == NULL) return l1;
  struct ListNode* head = l1;

  int d = 0;
  while(l1->next && l2->next){
	d = l1->val + l2->val + d;
	l1->val = d%10;
	d = (d >= 10) ? 1 : 0;
	l1 = l1->next;
	l2 = l2->next;
  }
  if(!l1->next)
	l1->next = l2->next;
	
  d = l1->val + l2->val + d;
  l1->val = d%10;
  d = (d >= 10) ? 1 : 0;

  while(l1){
	d = l1->val + d;
	l1->val = d%10;
	d = (d >= 10) ? 1 : 0;
	l1 = l1->next;
  }
  
  return head;
}


void print_list(lnode *n) {

  do{
	if(n->next)
	  printf("%d -> ",n->val);
	else
	  printf("%d -> NULL\n",n->val);
	n = n->next;
  }while(n);
}

void make_nnode_list(lnode* head, int n) {
  int s = head->val;
  while(n){
	head->next = malloc(sizeof(lnode));	
	head->next->val = s+n;
	head->next->next = NULL;
	head = head->next;
	n--;
  }

}
int main()
{
  lnode l1 = {1,NULL};
  lnode l2 = {4,NULL};
  lnode* l3 = NULL;
  make_nnode_list(&l1, 0);
  make_nnode_list(&l2, 3);
  print_list(&l1);
  print_list(&l2);
  l3 = addTwoNumbers(&l1, &l2);
  print_list(l3);

  
  return 0;
}
