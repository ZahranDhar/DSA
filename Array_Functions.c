//Array functions

#include<stdio.h>

void create(int a[], int n);
void display(int a[], int n);
void search(int a[], int n, int t);

int main()
{

  int a[10],t;

  create(a,10);
  display(a,10);

  printf("\nEnter the element to search for.\n");
  scanf("%d\n",&t);

  search(a,10,t);

  return 0;
}

void create(int a[], int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    printf("Enter the element %d\n",i+1);
    scanf("%d\n",&a[i]);
  }
}

void display(int a[], int n)
{
  int i;
  printf("The elements are:\n");
  for(i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
}

void search(int a[], int n, int t)
{
  int i,flag=0;
  for(i=0;i<n;i++)
  {
    if(a[i]==t)
    {
      printf("The elemtnt was found at position %d",i++);
      flag=1;
      break;
    }
  }
  
  if(flag==0)
  {
    printf("The element was not found.");
  }
}