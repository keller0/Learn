#include<stdio.h>

int hailstone( int n ) {

    int length = 1;
    while ( 1 < n ) {
        ( n % 2 ) ? ( n = 3 * n + 1 ) : ( n /= 2 );
        printf( "%4d", n );
        length++;
    }
    printf("\n");
    return length;
}


int main() {
    int l;
    int n;
    printf("Inputer a integer：");
    scanf("%d",&n);
    
    l = hailstone( n );
    printf("%d\n",l);
    
    return 0;
}
