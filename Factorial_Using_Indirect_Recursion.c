#include<stdio.h>
int fact(int x);
int callfact(int x);

int main()
{
  int x;

  printf("Enter the number for factorial.\n");
  scanf("%d",&x);

  x=fact(x);

  printf("The factorial is %d",x);

  return 0;
}

int fact(int x)
{
  if(x>1) return x*callfact(x-1);
  else return x;

}

int callfact(int x)
{
  return fact(x);
































































  
}