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
void display(int rev);
void search();
void insertion();

int main()
{
  create();
  read();
  display(1);
  search();
  insertion();

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
  
}

void display(int rev)
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

  if(rev==1)
  {
  //Display Reverse
  printf("\nThe Linked List Data Reversed is:\n");
  while(Temp!=NULL)
  {
    printf("%d ",Temp->Data);
    Temp=Temp->Link_p;
  }  
  }
  
  
}

void search()
{
  int i=1,x;

  printf("\nEnter the data to search for.\n");
  scanf("%d",&x);

  struct Node *temp=Head;
  while(temp!=NULL)
  {
    if(temp->Data==x)
    {
      printf("The data was found in Node %d\n",i);

    }

    temp=temp->Link_n;
    i++;
  }

}

void insertion()
{
  struct Node *temp=malloc(sizeof(struct Node));

  //Insertion at start
  printf("Enter the data for new first Node.\n");
  scanf("%d",&temp->Data);

  temp->Link_n=Head;
  Head->Link_p=temp;
  temp->Link_p=NULL;

  //Head pointer updated
  Head=temp;

  display(1);

  //Insertion at end
  struct Node *temp_n=malloc(sizeof(struct Node));
  printf("\nEnter the data for new last Node.\n");
  scanf("%d",&temp_n->Data);

  temp=Head;
  while(temp->Link_n!=NULL)
  {
    temp=temp->Link_n;
  }
  temp->Link_n=temp_n;
  temp_n->Link_p=temp;
  temp_n->Link_n=NULL;

  display(1);

  //Insertion at n
  int n;

  printf("Enter the position where you want to add the node.\n");
  scanf("%d",&n);
  




}
