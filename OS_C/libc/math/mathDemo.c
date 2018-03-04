#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main () {
   double x, ret, val;

   x = 0.9;
   val = 180.0 / PI;

   ret = acos(x) * val;
   printf("The arc cosine of %lf is %lf degrees\n", x, ret);

   x = PI/180*45;
   printf("The sin of 45 degrees is %f\n", sin(x));
   int a, b;
   a = 1234;
   b = -344;
  
   printf("The absolute value of %d is %lf\n", a, fabs(a));
   printf("The absolute value of %d is %lf\n", b, fabs(b));

    /* finding log(2.7) */
   printf("log(%lf) = %lf\n", 2.7, log(2.7));
   /* finding value of log10(10000) */
   x = 10000;
   printf("log10(%lf) = %lf\n", x, log10(x));


    float val1, val2, val3, val4;

   val1 = 1.6;
   val2 = 1.2;
   val3 = 2.8;
   val4 = 2.3;
   //ceils floor
   printf ("ceils\n"); 
   printf (" %.1lf = %.1lf\n", val1, ceil(val1));
   printf (" %.1lf = %.1lf\n", val2, ceil(val2));
   printf (" %.1lf = %.1lf\n", val3, ceil(val3));
   printf (" %.1lf = %.1lf\n", val4, ceil(val4));
   printf ("floors\n"); 
   printf (" %.1lf = %.1lf\n", val1, floor(val1));
   printf (" %.1lf = %.1lf\n", val2, floor(val2));
   printf (" %.1lf = %.1lf\n", val3, floor(val3));
   printf (" %.1lf = %.1lf\n", val4, floor(val4));

   return(0);
}
