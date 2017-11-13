#include<stdio.h>
#define R 1
#define B 2
#define G 3
int printRBG(int,int);

int main() {

    int Bit;
    scanf("%d",&Bit);
    printf("%d\n\n",Bit);
    printRBG(Bit,R);
    printRBG(Bit,G);
    printRBG(Bit,B);
    return 0;
}

int printRBG(int Bit,int x){
    switch(x){
    case(R):
        printf("%d\n",Bit>>8);break;
    case(G):
        printf("%d\n",(Bit&240)>>4);break;
    case(B):
        printf("%d\n",Bit&15);break;
    default:
        printf("Wrong color type");
    }
}

