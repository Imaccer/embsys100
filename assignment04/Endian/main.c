#include<assert.h>

int Endian(void)
{
  int myInt=0x11111111;
  char* pChar=(char*)&myInt;
  *pChar=0x00;
  
  if (myInt==0x11111100)
  {
    return 1;
  }
  
  return 0;
}

//Will return error if big endian. Will not return error if little endian.
int main(void)
{
  assert(1 == Endian());
  
  return 0;
}
