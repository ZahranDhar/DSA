//Array size

#include<stdio.h>

int main()
{
  int arr[2],i;

  printf("The size of the array is %d\n",sizeof(arr));
  
  for(i=0;i<5;i++)
  {
    printf("Enter the element %d\n",i+1);
    scanf("%d",&arr[i]);
  }

  printf("The elements are:\n");
  for(i=0;i<5;i++)
  {
    printf("%d\n",arr[i]);
  }

  printf("The size of the array is %d\n",sizeof(arr));

  return 0;
}