#include<stdio.h>
#include<limits.h>

int test(int a) {
  int b = 0;
  do{
	/* printf("a = %d, b = %d\n",a,b); */
	if((b > (INT_MAX / 10)) || b < (INT_MIN /10))
	  return 0;
	b = b*10 + a % 10;
	a = a / 10;
  }while( a != 0);

  return b;
}

int main()
{
  int a[] = {
	12,
	-738123897,
	142,
	INT_MAX-1,
	INT_MAX,
	INT_MIN
  };
  int i;
  for( i = 0; i < 6; i++) {
	printf("%d\t -> %d\n",a[i],test(a[i]));
  }
  return 0;

}
