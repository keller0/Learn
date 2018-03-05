#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
void Error(char *s){
  printf("%s\n",s);
  exit(2);
}

int main()
{
  int i = 0;
  Stack s = CreateStack(7);
  while(i < 201){
	Push(s, 100+i++);
	printf("%d\n",Top(s));
  }

}

Stack CreateStack(int MaxElements) {
  Stack S;

  assert(MaxElements >= MinStackSize);

  S = malloc(sizeof(struct StackRecod));
  assert(S != NULL);

  S->Array = malloc(sizeof(int)*MaxElements);
  assert(S->Array);
  S->Capacity = MaxElements;

  MakeEmpty(S);

  return S;
}
void DisposeStack(Stack S) {
  if(S != NULL){
	free(S->Array);
	free(S);
  }
}
int IsEmpty(Stack S) {
  return S->TopOfStack == EmptyTOS;
}

void MakeEmpty(Stack S) {
  S->TopOfStack = -1;
}
int IsFull(Stack S) {
  if(S->TopOfStack < S->Capacity-1)
	return 0;
  else
	return 1;
}
void Push(Stack S, int X) {
  if(IsFull(S))
	Error("Full stack");
  else
	S->Array[++S->TopOfStack] = X;
}
int Top(Stack S) {
  assert(!IsEmpty(S));
  return S->Array[S->TopOfStack];
}
void Pop(Stack S) {
  
 if(IsEmpty(S))
	Error("Empty stack");
  else
	S->TopOfStack--;
}
int TopAndPop(Stack S) {
  assert(!IsEmpty(S));  
  return S->Array[S->TopOfStack--];
}

