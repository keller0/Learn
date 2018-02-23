#include<stdio.h>

typedef struct ListNode {
  int val;
  struct ListNode *next;
} lnode;

struct ListNode* mergeTwoLists(
		struct ListNode* l1, struct ListNode* l2)
{
  if(l1 == NULL) return l2;
  if(l2 == NULL) return l1;
  
  lnode* head;
  if(l1->val < l2->val)     {head = l1; l1 = l1->next;}
  else                  	{head = l2; l2 = l2->next;}
  
  lnode* p = head;
  while(l1 && l2){
	if(l1->val < l2->val)	  { p->next = l1; l1 = l1->next;}
	else                	  { p->next = l2; l2 = l2->next;}
	p = p->next;
  }
  
  if(l1)	p->next = l1;
  else  	p->next = l2;

  return head;
}
 /* recursion one  */
struct ListNode* RmergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
void print_list(lnode *n) {

  do{
	if(n->next)
	  printf("%d -> ",n->val);
	else
	  printf("%d \n",n->val);
	n = n->next;
  }while(n);
}


int main()
{
  
  lnode l5 = { 9, NULL };
  lnode l4 = { 7, &l5 };
  lnode l3 = { 5, &l4 };
  lnode l2 = { 3, &l3 };
  lnode l1 = { 1, &l2 };

  lnode ll5 = {10, NULL};
  lnode ll4 = { 8, &ll5};
  lnode ll3 = { 6, &ll4};
  lnode ll2 = { 4, &ll3};
  lnode ll1 = { 2, &ll2};
  
  print_list(&l1);  
  print_list(&ll1);

  lnode* list;
  /* list = mergeTwoLists(&l1, &ll1); */
  /* print_list(list); */
  list = RmergeTwoLists(&l1, &ll1);
  print_list(list);
  return 0;
}
