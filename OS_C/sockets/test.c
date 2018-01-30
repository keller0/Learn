#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int a;
  short s[2];
} MSG;

int main() {

  MSG *mp, m={4, 1, 0};
  char *fp, *tp;
  mp = (MSG *) malloc(sizeof(MSG));
  /* copy m.s to mp->s */
  for (fp = (char *)m.s, tp = (char *)mp->s; tp < (char *)(mp+1);)
	*tp++ = *fp++;

  printf("%d,%d\n", m.s[0],mp->s[0]);
  printf("%d,%d\n", m.s[1],mp->s[1]);
}
