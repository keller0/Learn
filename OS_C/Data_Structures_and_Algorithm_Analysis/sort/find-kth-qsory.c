/*
 *  print the time finding k when k = N / 2 
 *  first sort then find 
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define MAX 2000000
#define Cutoff (3)


void swap(int *, int*);
void InsertionSort(int *, int );
void quick(int *,int, int);

void makeList (int *pl, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        pl[i] = rand()%(10000000-0+1);
    }
}

void test(int n,FILE *fp)
{
    int a[n];
    int *plist = &a[0];
    clock_t s;
    double time1, time2;

    makeList(plist, n);
    s = clock();
    quick(plist, 0, n);
    time2 = (double)(clock()-s)/CLOCKS_PER_SEC;
    
    printf("N = %d N/2th is %d ", n, a[n/2]);
    printf("use qsort is %f s\n", time2);
    //save to file time is ms
    fprintf(fp,"%d,%f\n", n,  time2*1000);

}



int median3(int A[], int Left, int Right)
{
    int Center = (Left + Right) / 2;

    if( A[ Left ] > A[ Center ] )
        swap( &A[ Left ], &A[ Center ] );
    if( A[ Left ] > A[ Right ] )
        swap( &A[ Left ], &A[ Right ]);
    if( A[ Center ] > A[ Right ] )
        swap( &A[ Center ], &A[ Right ] );
    
    swap( &A[ Center ], &A[ Right - 1 ]);

    return A[ Right - 1];
}

void quick(int A[],int Left, int Right)
{

    int i, j, Pivot;
    if ( Left + Cutoff <= Right) {
        Pivot = median3( A, Left, Right);
        i = Left; j = Right -1;
        for(;;) {
            while( A[++i] < Pivot ){}
            while( A[--j] > Pivot ){}
            if( i < j )
                swap( &A[i], &A[j]);
            else
                break;
        }
        swap( &A[i], &A[Right - 1]);
        quick( A, Left, i - 1);
        quick( A, i + 1, Right);
    }
    else
        InsertionSort( A + Left, Right - Left + 1 );
}

void InsertionSort(int A[], int N)
{
    int j, P;

    int Tmp;
    for( P = 1; P < N; P++) {
        Tmp = A[P];
        for ( j = P; j > 0 && A[j - 1] > Tmp; j--)
            A[j] = A[j - 1];
        A[j] = Tmp;
    }
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    clock_t s, e;
    FILE *fp;
    fp = fopen("qsort-speed-200w.csv","w");
    s = clock();
    for (int i = 1; i <= MAX; i++) {
        test(i, fp);
    }

    e = clock();
    printf("All done in %f s\n",(double)(e-s)/CLOCKS_PER_SEC);
    
    fclose(fp);

  
    return 0;
}
