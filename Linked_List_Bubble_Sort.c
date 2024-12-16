//Linked List Bubble Sort

#include<stdio.h>
#include<stdlib.h>

struct Node 
{
  int Data;

  struct Node *Link;
};

struct Node *Head;
int size;

void create();
void display();
void sort();

int main()
{
  create();
  display();
  sort();

  return 0;
}

void create()
{
  int i;
  struct Node *temp2;

  printf("Enter the number of Nodes.\n");
  scanf("%d",&size);

  for(i=1;i<=size;i++)
  {
    struct Node *temp1=malloc(sizeof(struct Node));
    printf("Enter the data for Node %d:",i);
    scanf("%d",&temp1->Data);

    if(i==1)
    {
      Head=temp1;
      temp2=temp1;
    }
    else
    {
      temp2->Link=temp1;
      if(i!=size)
      {
        temp2=temp1;
      }
      else
      {
        temp1->Link=NULL;
      }
    }
}
}

void display()
{
  struct Node *temp=Head;

  while(temp!=NULL)
  {
    printf("%d ",temp->Data);
    temp=temp->Link;
  }
}

void sort()
{
  struct Node *temp1;
  struct Node *temp2;
  struct Node *temp3;
  struct Node *temp4;
  int i,j;

  for(i=1;i<size;i++)
  {
    temp1=NULL;
    temp2=Head;
    temp3=Head->Link;
    temp4=Head->Link->Link;
    
    for(j=1;j<size-(i-1);j++)
    {
      if(temp2->Data>temp3->Data)
      {
        if(temp1!=NULL)
        {
          temp1->Link=temp3;
          temp3->Link=temp2;
          temp2->Link=temp4;
        }
        else
        {
          temp3->Link=temp2;
          temp2->Link=temp4;
          Head=temp3;
        }
      }
      temp1=temp2;
      temp2=temp2->Link;
      temp3=temp3->Link;
      temp4=temp4->Link;
    }
  }
  printf("\n");
  display();
}