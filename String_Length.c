//String Length

#include<stdio.h>

int main()
{
  char str[100];
  int i;

  printf("Enter the string.\n");
  scanf("%s",&str);

  i=0;
  while(str[i]!='\0')
  {
    i++;
  }

  printf("The length of the string is %d.\n",i);
 
  return 0;
}

