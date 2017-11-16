#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   char *str;

   str = (char *) malloc(10);
   strcpy(str, "1234567890abcdefg"); //out of  bounds
   printf("String = %s,  Address = %u\n", str, str);

   /* Reallocating memory */
   str = (char *) realloc(str, 25);
   strcat(str, "1234567890");   //out of bounds
   printf("String = %s,  Address = %u\n", str, str);
   free(str);

   return(0);
}