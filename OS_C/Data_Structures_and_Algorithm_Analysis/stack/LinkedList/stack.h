#ifndef _Stack_h
#define _Stack_h
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(Stack S, int X);
int Top(Stack S);
void Pop(Stack S);

#endif /* _Stack_h */

