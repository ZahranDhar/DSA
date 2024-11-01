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
 
  return 0;
}

