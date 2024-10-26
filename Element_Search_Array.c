//Element search array

#include<stdio.h>

int main()
{
  int arr[50],i,n,x,flag=0;

  printf("Enter the length of the array.\n");
  scanf("%d",&n);

  for(i=0;i<n;i++)
  {
    printf("Enter the element %d,\n",i+1);
    scanf("%d",&arr[i]);
  }

  printf("Enter the element you want to search for.\n");
  scanf("%d",&x);

  for(i=0;i<n;i++)
  {
    if(arr[i]==x)
    {
      printf("The element is found at position %d\n",i+1);
    }
    flag=1;
  }

  if(flag==0)
  {
    printf("The element was not found.\n");
  }

  return 0;

}