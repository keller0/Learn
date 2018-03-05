#include <stdarg.h>
#include <stdio.h>

int sum(int, ...);
double mul(int, ...);

int main () {
  printf("Sum of 15 and 56 = %d\n",  sum(3, 15, 56, 90));
  printf("15 * 12 = %f\n",  mul(2, 15.9, 12.9) );
  return 0;
}

int sum(int num_args, ...) {
   int val = 0;
   va_list ap;
   int i;
   printf("%d\n",num_args);
   va_start(ap, num_args);
   for(i = 0; i < num_args; i++) {
      val += va_arg(ap, int);
   }
   va_end(ap);
 
   return val;
}

double mul(int num_args, ...) {
   double val = 1;
   va_list ap;
   int i;

   va_start(ap, num_args);
   for(i = 0; i < num_args; i++) {
      val *= va_arg(ap, double);
   }
   va_end(ap);
 
   return val;
}
