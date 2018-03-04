#include <stdio.h>
#include <ctype.h>

int main()
{
  int n = '1';
  char c = 'c';
  char b = ' ';
  char t = '\t';
  char p = '#';
  printf("-->|%d,%c,%c,%c,%c|<--\n",n,c,b,t,p);
  printf("isalnum(n) %d\n",isalnum(n));
  printf("isalnum(c) %d\n",isalnum(c));
  printf("isalnum(b) %d\n",isalnum(b));
  printf("isalnum(t) %d\n\n",isalnum(t));

  printf("isalpha(n) %d\n",isalpha(n));
  printf("isalpha(c) %d\n",isalpha(c));
  printf("isalpha(b) %d\n",isalpha(b));
  printf("isalpha(t) %d\n\n",isalpha(t));

  printf("iscntrl(n) %d\n",iscntrl(n));
  printf("iscntrl(c) %d\n",iscntrl(c));
  printf("iscntrl(b) %d\n",iscntrl(b));
  printf("iscntrl(t) %d\n\n",iscntrl(t));

  printf("isdigit(n) %d\n",isdigit(n));
  printf("isdigit(c) %d\n",isdigit(c));
  printf("isdigit(b) %d\n",isdigit(b));
  printf("isdigit(t) %d\n\n",isdigit(t));

  printf("isgraph(n) %d\n",isgraph(n));
  printf("isgraph(c) %d\n",isgraph(c));
  printf("isgraph(b) %d\n",isgraph(b));
  printf("isgraph(t) %d\n\n",isgraph(t));

  printf("islower(n) %d\n",islower(n));
  printf("islower(c) %d\n",islower(c));
  printf("islower(b) %d\n",islower(b));
  printf("islower(t) %d\n\n",islower(t));

  printf("isprint(n) %d\n",isprint(n));
  printf("isprint(c) %d\n",isprint(c));
  printf("isprint(b) %d\n",isprint(b));
  printf("isprint(p) %d\n",isprint(p));
  printf("isprint(t) %d\n\n",isprint(t));

  printf("ispunct(n) %d\n",ispunct(n));
  printf("ispunct(c) %d\n",ispunct(c));
  printf("ispunct(b) %d\n",ispunct(b));
  printf("ispunct(p) %d\n",ispunct(p));
  printf("ispunct(t) %d\n\n",ispunct(t));

  printf("isspace(n) %d\n",isspace(n));
  printf("isspace(c) %d\n",isspace(c));
  printf("isspace(b) %d\n",isspace(b));
  printf("isspace(p) %d\n",isspace(p));
  printf("isspace(t) %d\n\n",isspace(t));

  printf("isupper(n) %d\n",isupper(n));
  printf("isupper(c) %d\n",isupper(c));
  printf("isupper(b) %d\n",isupper(b));
  printf("isupper(p) %d\n",isupper(p));
  printf("isupper(t) %d\n\n",isupper(t));

  printf("isxdigit(n) %d\n",isxdigit(n));
  printf("isxdigit(c) %d\n",isxdigit(c));
  printf("isxdigit(b) %d\n",isxdigit(b));
  printf("isxdigit(p) %d\n",isxdigit(p));
  printf("isxdigit(t) %d\n\n",isxdigit(t));

  printf("tolower A %c\n\n",tolower('A'));
  printf("toupper a %c\n\n",toupper('a'));

  return 0;
}
