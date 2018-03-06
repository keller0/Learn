#include <stdio.h>

typedef  unsigned int Index;

Index Hash1(const char *Key, int TableSize)
{
  unsigned int HashVal = 0;

  while(*Key != '\0')
	HashVal += *Key++;

  return HashVal%TableSize;
}
Index Hash2(const char *Key, int TableSize)
{
  unsigned int HashVal = 0;
  while(*Key != '\0')
	HashVal = (HashVal << 5) + *Key++;
  return HashVal%TableSize;
}
int main()
{


  int ts = 500;
  printf("%u\n",Hash2("1a",ts));
  printf("%u\n",Hash2("2",ts));
  printf("%u\n",Hash2("3s",ts));
  printf("%u\n",Hash2("4dasdjaodjiia",ts));
  printf("%u\n",Hash2("5",ts));
  printf("%u\n",Hash2("6",ts));
}
