// 2.25
#include <stdio.h>

float sum_elements(float a[], unsigned length) {
    /* (unsigned 0) - 1 = 0xffffffff */
    int i;
    float result = 0;
    for (i = 0; i <= length-1; i++) {
        result += a[i];
        /* printf("%d\n",i); */
    }
    return result;
}

int main() {
    float arr[3] = {1.0,2.2,3};
    float sum = sum_elements( arr, 3);
    printf("%f\n", sum);
}
