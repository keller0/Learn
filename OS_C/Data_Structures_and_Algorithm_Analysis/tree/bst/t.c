#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "t.h"

struct TreeNode
{
  int Element;
  SearchTree Left;
  SearchTree Right;
};

int main()
{
  SearchTree T = NULL;
  Position P;
  T = MakeEmpty(T);
  int i = 0;
  for(;i <10; i++) {
	  T = Insert( T, i);
  }
  T = Delete( T, 9);
  T = Delete( T, 0);
  P = FindMin(T);
  printf("min is %d\n", P->Element);
  P = FindMax(T);
  printf("max is %d\n", P->Element);
  return 0;
}
SearchTree Delete( SearchTree T, int X) {
  Position TmpCell;

  assert(T != NULL);
  if(X < T->Element) {
	T->Left = Delete(T->Left, X);
  }else if(X > T->Element) {
	T->Right = Delete(T->Right, X);
  }else if(T->Left && T->Right) {
	  TmpCell = FindMin(T->Right);
	  T->Element = TmpCell->Element;
	  T->Right = Delete(T->Right, T->Element);
  }else {
	TmpCell = T;
	if( T->Left == NULL)
	  T = T->Right;
	else if( T->Right == NULL )
	  T = T->Left;
	free(TmpCell);
  }

  return T;
}

SearchTree Insert( SearchTree T, int X) {
  if(T == NULL){
	  T = malloc(sizeof(struct TreeNode));
	  assert(T != NULL);
	  T->Element = X;
	  T->Left = T->Right = NULL;
  }
  else if( X < T->Element){
	T->Left = Insert(T->Left, X);
  }
  else if( X > T->Element){
	T->Right = Insert(T->Right, X);
  }	  
  return T;
}

Position FindMin( SearchTree T) {
  if(T == NULL)
	return NULL;
  else if(T->Left == NULL)
	return T;
  else
	return FindMin(T->Left);
}
Position FindMax( SearchTree T) {
  if(T != NULL)
	while(T->Right != NULL)
	  T = T->Right;

  return T;
}
Position Find( SearchTree T, int X) {
  if(T == NULL)
	return NULL;
  if(X < T->Element) {
	Find(T->Left, X);
  }else if(X > T->Element) {
	Find(T->Right, X);
  }else{
	return T;
  }
  return T;
}
SearchTree MakeEmpty( SearchTree T) {
  if( T != NULL)
	{
	  MakeEmpty(T->Left);
	  MakeEmpty(T->Right);
	  free(T);
	}
  return NULL;
}
