#include <stdio.h>
#include <errno.h>
#include <string.h>

/**
   1. extern int errno
   2. EDOM Domain Error
   3. ERANGE Range Error
**/

extern int errno ;

int main () {
   FILE *fp;

   fp = fopen("file.txt", "r");
   if( fp == NULL ) {
      fprintf(stderr, "Value of errno: %d\n", errno);
      fprintf(stderr, "Error opening file: %s\n", strerror(errno));
   } else {
      fclose(fp);
   }
   
   return(0);
}
