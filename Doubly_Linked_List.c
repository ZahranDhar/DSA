//Doubly Linked List

#include<stdio.h>
#include<stdlib.h>

struct Node 
{
  int Data;

  struct Node *Link_p;
  struct Node *Link_n;
};

struct Node *Head;

void create();
void read();
void display();


int main()
{
  create();
  read();
  return 0;
}

void create()
{
  int n,i;
  
  //Number of Nodes
  do
  {
    printf("Enter the number of Nodes.\n");
    scanf("%d",&n);

    if(n<2)
    {
      printf("ERROR\n");
    }
  } while (n<2);

  struct Node *Temp_1;
  for(i=1;i<=n;i++)
  {
    if(i==1)
    {
      //Head Node
      Head=(struct Node*)(malloc(sizeof(struct Node)));
      Head->Link_p=NULL;
      Temp_1=Head;
    }
    else
    {
      //Rest of Nodes
      struct Node *Temp_2=(struct Node*)(malloc(sizeof(struct Node)));
      Temp_2->Link_p=Temp_1;
      Temp_1->Link_n=Temp_2;
      Temp_2->Link_n=NULL;

      Temp_1=Temp_2;
    }
  }
}

void read()
{
  struct Node *Temp=Head;
  int i=1;

  while(Temp!=NULL)
  {
    printf("Enter the Data for Node %d\n",i);
    scanf("%d",&Temp->Data);

    Temp=Temp->Link_n;
    i++;
  }

  display();
  
}

void display()
{
  struct Node *Temp=Head;

  //Display Forward
  printf("The Linked List Data is:\n");
  while(Temp->Link_n!=NULL)
  {
    printf("%d ",Temp->Data);
    Temp=Temp->Link_n;
  }
  printf("%d ",Temp->Data);

  //Display Reverse
  printf("\nThe Linked List Data Reversed is:\n");
  while(Temp!=NULL)
  {
    printf("%d ",Temp->Data);
    Temp=Temp->Link_p;
  }
}