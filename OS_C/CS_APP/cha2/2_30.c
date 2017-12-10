#include <stdio.h>

// if x + y will not overflow return 1
int tadd_ok(int x, int y) {
    int sum = x + y;
    int p_o = x >= 0 && y >= 0 && sum <  0;
    int n_o = x <  0 && y <  0 && sum >= 0;

    return !p_o && !n_o;
}
int main()
{
    int a = 0x7fffffff;
    int b = 0x7fffffff;
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",a+b);
    printf("%s\n",tadd_ok(a, b)==0?"overflowed":"not overflow");
}
