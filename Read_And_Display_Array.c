//Read and display array

#include<stdio.h>

int main()
{
  int arr[100],i,n;

  printf("Enter the length of the array\n");
  scanf("%d",&n);

  for(i=0;i<n;i++)
  {
    printf("Enter the element %d\n",i+1);
    scanf("%d",&arr[i]);
  }

  printf("The elements of the array are:\n");
  for(i=0;i<n;i++)
  {
    printf("%d\n",arr[i]);
  }

  return 0;
}





