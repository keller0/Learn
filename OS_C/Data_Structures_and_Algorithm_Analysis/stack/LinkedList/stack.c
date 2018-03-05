#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct Node
{
  int Element;
  PtrToNode Next;
};

void Error(char *s){
  printf("%s\n",s);
  exit(2);
}

int main()
{

  Stack S = CreateStack();
  int i = 4;
  while(i){
	Push(S,i);
	printf("top is %d\n",Top(S));
	i--;
  }
  i = 4;
  while(i){
	printf("top is %d\n",Top(S));
	Pop(S);
	i--;
  }
  return 0;
}


int IsEmpty(Stack S) {
  return S->Next == NULL;
}
Stack CreateStack(void) {
  Stack S;
  S = malloc(sizeof(struct Node));
  assert(S != NULL);
  S->Next = NULL;
  MakeEmpty(S);
  return S;
}

void MakeEmpty(Stack S) {
  assert(S != NULL);
  while(!IsEmpty(S))
	Pop(S);
}
void Push(Stack S, int X) {
  PtrToNode Ptmp;
  Ptmp = malloc(sizeof(struct Node));
  assert(Ptmp != NULL);

  Ptmp->Element = X;
  Ptmp->Next = S->Next;
  S->Next = Ptmp;
}
int Top(Stack S) {
  if(!IsEmpty(S))
	return S->Next->Element;
  Error(" Empty Stack");
  return 0;
}
void Pop(Stack S) {

  PtrToNode FirstCell;
  if(IsEmpty(S))
	Error(" Empty Stack");
  else{
	FirstCell = S->Next;
	S->Next = S->Next->Next;
	free(FirstCell);
  }
}
void DisposeStack(Stack S);
