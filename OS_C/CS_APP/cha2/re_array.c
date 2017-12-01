#include<stdio.h>

void inplace_swap(int *x, int *y) {
    if(*x == *y)
        return;
    *y = * x ^ *y;
    *x = * y ^ *x;
    *y = * x ^ *y;
}

void reverse_array(int a[], int cnt) {
    int first, last;
    for (first =0, last = cnt - 1;
         first <= last;
         first++,last--)
        inplace_swap(&a[first], &a[last]);
}

int main() {

    int arr[5] = {1,2,3,4,5};
    reverse_array(arr, 5);
    int i = 0;
    while(i < sizeof(arr)/sizeof(arr[0])){
        printf("%d ",arr[i]);
        i++;
    }
    printf("\n");

    return 0;
}
