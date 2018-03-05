#ifndef _Stack_h
#define _Stack_h
struct StackRecod;
typedef struct StackRecod *Stack;
int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(Stack S, int X);
int Top(Stack S);
void Pop(Stack S);
int TopAndPop(Stack S);
#define EmptyTOS (-1)
#define MinStackSize (5)

#endif
struct StackRecod
{
    int TopOfStack;
    int Capacity;
    int* Array;
};
