/*
 *  Quick sort 
 * 
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define AR_LEN 33
#define MAX_RANDOM 100
#define Cutoff (3)


void swap(int *, int*);
void InsertionSort(int *, int );
void quick(int *,int, int, int);
void printArr ( char *,int *, int);
void printQsSteps(int *, int, int, int ,int, char*, int);

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

void makeArr (int *pl, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        pl[i] = rand()%(MAX_RANDOM-0+1);
    }
}

int median3(int A[], int Left, int Right)
{
    int Center = (Left + Right) / 2;
    char *str1 = "Change piv:";
    char *str2 = "pivChanged:";
    if( A[ Left ] > A[ Center ] ){
        swap( &A[ Left ], &A[ Center ] );
        printQsSteps( A, AR_LEN , 0, Left, Right+1, str1, Center);
    }
    if( A[ Left ] > A[ Right ] ){
        swap( &A[ Left ], &A[ Right ]);
        printQsSteps( A, AR_LEN , 0, Left, Right+1, str1, Center);
    }
    if( A[ Center ] > A[ Right ] ){
        swap( &A[ Center ], &A[ Right ] );
        printQsSteps( A, AR_LEN , 0, Left, Right+1, str1, Center);
    }
    swap( &A[ Center ], &A[ Right - 1 ]);
    
    printQsSteps( A, AR_LEN , 0, Left, Right+1, str2, Right -1);

    return A[ Right - 1];
}

void printArr (char *str,int *pl, int n)
{
    int i;
    int mid = n / 2;
    printf("%s",str);
    for (i = 0; i < n; i++) {
        if ( i == mid )
            printf("|%2d|",pl[i]);
        else
            printf("%3d ",pl[i]);
    }    
    printf("\n");
}

void printQsSteps (int *pl, int n, int Level, int Left, int Right,char *world, int pv)
{
    int i;
    int mid = (Right + Left) / 2;
    if( world == NULL)
        printf("%2dth level:", Level);
    else
        printf("%s",world);
    
    for (i = 0; i < n; i++) {
        if ( i == pv )
            printf("{%2d}",pl[i]);
        else if ( i == mid && i != ( Right -1))
            printf("|%2d|",pl[i]);
        else if ( i == Left )
            printf("|%3d ",pl[i]);
        else if ( i == (Right - 1) )
            printf("%3d|",pl[i]);
        else if ( i> Left  && i < (Right - 1))
            printf("%3d ",pl[i]);
        else
            printf("____");
    }
    
    printf("\n");
}

void quick(int A[],int Left, int Right, int Level)
{

    int i, j, Pivot;
    if ( Left + Cutoff <= Right) {
        Pivot = median3( A, Left, Right);

        i = Left; j = Right -1;
        for(;;) {
            while( A[++i] < Pivot ){}
            while( A[--j] > Pivot ){}
            if( i < j ){
                swap( &A[i], &A[j] );
                printQsSteps( A, AR_LEN , Level, Left, Right+1,  NULL, -1);
            }
            else
                break;
        }
        swap( &A[i], &A[Right - 1] );

        printQsSteps( A, AR_LEN , Level, Left, Right+1, NULL, Right -1);

        quick( A, Left, i - 1, Level + 1);
        quick( A, i + 1, Right, Level + 1);
    }
    else{
        InsertionSort( A + Left, Right - Left + 1 );
    }
}


int main()
{

    
    int a[AR_LEN];
    char *str = " Now Array: ";
    makeArr( a, AR_LEN );

    printArr( str, a, AR_LEN );

    quick( a, 0 , AR_LEN , 1);

    printArr( str, a, AR_LEN );

    return 0;
}
