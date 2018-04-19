#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "sha1.h"

int checkFile(char* filename) {

    FILE *inFile = fopen (filename, "rb");
    if (inFile == NULL) {
        printf ("%s can't be opened.\n", filename);
        return 0;
    }
    SHA1Context sha;
    uint8_t Message_Digest[20];
    int bytes;
    unsigned char data[1024];
    SHA1Reset(&sha);
    while ((bytes = fread (data, 1, 1024, inFile)) != 0)
        SHA1Input(&sha, (const unsigned char *) data,bytes);
    
    SHA1Result(&sha, Message_Digest);
    fclose (inFile);

    int i;
    for( i=0; i<20; i++)
	    printf("%02x",Message_Digest[i]);
    printf("\n");

    return 0;
}
int main(int argc, char** argv)
{
    
    checkFile(argv[1]);

    return 0;
}
