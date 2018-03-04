#include <stdio.h>
#include <errno.h>
#include <math.h>
  
int main () {
   double val;

   errno = 0;
   val = sqrt(-100); // compile failed, use gcc -lm
   
   if(errno == EDOM) {
      printf("Invalid value \n");
   } else {
	 printf("Valid value sqrt:%f\n",val);
   }
   
   errno = 0;
   val = sqrt(10);
   
   if(errno == EDOM) {
      printf("Invalid value\n");
   } else {
	 printf("Valid value sqrt:%f\n",val);
   }
   
   return(0);
}
