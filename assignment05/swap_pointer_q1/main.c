void swap_pointer(int** x,int** y);

void main(void)
{
  int x = 20000000;
  int y = 10000000;
  
  int* xPtr=&x;
  int* yPtr=&y;
  
  int** xPtrPtr=&xPtr;
  int** yPtrPtr=&yPtr;
  
  swap_pointer(xPtrPtr,yPtrPtr);
}

void swap_pointer(int** x, int** y)
{
  int* tempPtr = *x;
  
  *x=*y;
  
  *y=tempPtr;
}