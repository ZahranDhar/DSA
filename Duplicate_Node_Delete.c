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
void callelements();

int main()
{
  create();
  read();
  display(0);
  callelements();
  printf("\n//Duplicate Nodes deleted//\n");
  display(0);

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
    printf("Enter the Data for Node %d:",i);
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

void deleteduplicate(int x)
{
  struct Node *temp=Head;
  int flag=0;

  while(temp!=NULL)
  {
    if((flag==1)&&(temp->Data==x))
    {
      if(temp->Link_n!=NULL)
      {
        struct Node *prev=malloc(sizeof(struct Node));
        struct Node *next=malloc(sizeof(struct Node));

        prev=temp->Link_p;
        next=temp->Link_n;

        prev->Link_n=next;
        next->Link_p=prev;

        free(temp);
      }
      else
      {
        struct Node *prev=malloc(sizeof(struct Node));

        prev=temp->Link_p;
        prev->Link_n=NULL;
        free(temp);
      }
    }
    if(temp->Data==x)
    {
      flag=1;
    }

    temp=temp->Link_n;
  }

}

void callelements()
{
  struct Node *temp=Head;
  int x;
  while(temp!=NULL)
  {
    x=temp->Data;
    deleteduplicate(x);
    temp=temp->Link_n;
  }

}