#include<iostream>
using namespace std;

int main()
{

  int i = 37;
  float f = *(float *)&i;
  cout<< f <<endl;
  float ff = 7.111;
  short s = *(short *)&ff;
  cout<< s <<endl;
  
}
