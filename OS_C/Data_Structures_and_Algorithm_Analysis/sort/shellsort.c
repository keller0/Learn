#include <stdio.h>

void printArray(int A[], int n)
{
  int i = 0;
  for(;i < n;i++)
	printf("%d\t",A[i]);
  printf("\n");
}

void ShellSort( int A[], int N)
{
  int i,j,Increment;
  int Tmp;

  for(Increment = N/2; Increment > 0; Increment /= 2){
	for(i = Increment; i < N; i++)
	  {
		Tmp = A[i];
		for(j = i; j >= Increment; j-= Increment)
		  if(Tmp < A[j-Increment])
			A[j] = A[j-Increment];
		  else
			break;
		A[j] = Tmp;
	  }
  }

}

int main()
{

  int A[] = {8,4,2,6,1,64,23,73,573,234,72};
  printArray(A, 11);
  ShellSort(A, 11);
  printArray(A, 11);
}
