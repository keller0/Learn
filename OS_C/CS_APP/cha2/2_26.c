#include<stdio.h>
#include<string.h>

int strlonger(char *s, char *t) {
    /* return strlen(s) - strlen(t) > 0; */
    /* strlen return unsigned */
    return strlen(s) > strlen(t);
}
int main() {
    char *s = "aaa";
    char *t = "bbbb";
    printf("%d\n",strlonger(s,t));
}
