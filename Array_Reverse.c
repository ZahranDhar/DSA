//Array Reverse

#include<stdio.h>

int main()
{
  char str[10],strrev[10];
  int i,n=0;

  printf("Enter the string to be reversed.\n");
  scanf("%s",str);

  while(str[n]!='\0')
  {
    n++;
  }

  for(i=0;i<n;i++)
  {
    strrev[i]=str[(n-i-1)];
  }


  printf("The reversed string is %s.\n",strrev);

  return 0;

}