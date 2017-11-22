#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NOFA 1000000000

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main()
{
    float size = sizeof(int) * NOFA, s_t;

    srand(time(NULL));
    s_t = clock();
    int * ap = malloc(size);
    for(int i = 0 ; i < NOFA; i++ ) {
        ap[i] = rand();
    }
    printf("%f minuts to make array\n",(clock() - s_t)/CLOCKS_PER_SEC/60);
    
    s_t = clock();
    qsort(ap, NOFA, sizeof(int), cmpfunc);
    printf("%f minuts to sort array\n",(clock() - s_t)/CLOCKS_PER_SEC/60);

    getchar();
    free(ap);
    return 0;
}