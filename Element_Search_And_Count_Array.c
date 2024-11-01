//Element Search And Count Array

#include<stdio.h>

int create(int arr[]);
void searchncount(int arr[],int n);

int main()
{
  int arr[50],n;

  n=create(arr);
  searchncount(arr,n);

  return 0;

}

int create(int arr[])
{
  int i,n;

  printf("Enter the size of the array.\n");
  scanf("%d",&n);

  for(i=0;i<n;i++)
  {
    printf("Enter the element %d.\n",(i+1));
    scanf("%d",&arr[i]);
  }

  return n;
}

void searchncount(int arr[],int n)
{
  int i,x,count=0,flag=0;

  printf("Enter the element to search for.\n");
  scanf("%d",&x);

  for(i=0;i<n;i++)
  {
    if(arr[i]==x)
    {
      printf("The element was found at position %d.\n",(i+1));
      count++;
      flag=1;
    }
  }

  if(flag==0)
  {
    printf("The element was not found.\n");
  }
  else
  {
    printf("The element was found %d times.\n",count);
  }
}