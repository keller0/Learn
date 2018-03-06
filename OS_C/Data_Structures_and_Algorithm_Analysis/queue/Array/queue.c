#include <stdio.h>
#include "queue.h"
#include <assert.h>
#include <stdlib.h>

#define MiniQueueSize (5)
struct QueueRecord
{
  int Capacity;
  int Front;
  int Rear;
  int Size;
  int *Array;
};

static int Succ(int Value, Queue Q) {
  if( ++Value == Q->Capacity)
	Value = 0;
  return Value;
}

int main() {
  Queue Q = CreatQueue(10);
  int i = 0;
  for (i; !IsFull(Q); i++){
      EnQueue(Q,i);
  }
  printf("Front element is %d\n",Front(Q));
  while(!IsEmpty(Q))
      printf("front is %d than dequeue\n",FrontAndDequeue(Q));
}

Queue CreatQueue(int MaxElements) {
  Queue Q;
  Q = (Queue)malloc(sizeof(struct QueueRecord));
  assert(Q != NULL);
  Q->Array = malloc(sizeof(int) * MaxElements);
  assert(Q->Array != NULL);
  Q->Capacity = MaxElements;
  Q->Front = 0;
  Q->Rear = -1;
  Q->Size = 0;
  return Q;
}

int IsEmpty(Queue Q) {
  return Q->Size == 0;
}
int IsFull(Queue Q) {
  return Q->Size >= Q->Capacity;
}
void MakeEmpty(Queue Q) {
  Q->Size = 0;
  Q->Front = 1;
  Q->Rear = 0;
}
int Front(Queue Q) {
  if(IsEmpty(Q)){
	printf("empty queue");
	exit(0);
  }
  return Q->Array[Q->Front];
}

void EnQueue(Queue Q, int X) {
  if(IsFull(Q)){
	printf("Full queue");
	exit(0);
  }
  Q->Size++;
  Q->Rear = Succ( Q->Rear,  Q);
  Q->Array[Q->Rear] = X;
}

void Dequeue(Queue Q) {
  if(IsEmpty(Q)){
	printf("Empty queue");
	exit(0);
  }
  Q->Size--;
  Q->Front++;// may
}
void DisposeQueue(Queue Q) {
  free(Q->Array);
  free(Q);
}
int FrontAndDequeue(Queue Q) {
  if(IsEmpty(Q)){
	printf("Empty queue");
	exit(0);
  }
  Q->Size--;
  return Q->Array[Q->Front++];
}
