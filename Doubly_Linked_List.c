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
int size;

void create();
void read();
void display();
void search();
void insertion();
void deletion();
void freespace();

int main()
{
  create();
  read();
  display();
  // search();
  insertion();
  deletion();
  freespace();

  return 0;
}

void create()
{
  int i;
  
  //Number of Nodes
  do
  {
    printf("Enter the number of Nodes.\n");
    scanf("%d",&size);

    if(size<2)
    {
      printf("ERROR\n");
    }
  } while (size<2);

  struct Node *Temp_1;
  for(i=1;i<=size;i++)
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
      
      if(i==size)
      {
        Temp_2->Link_n=NULL;
      }

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
  printf("%d",Temp->Data);

  //Display Reverse
  printf("\nThe Linked List Data Reversed is:\n");
  while(Temp!=NULL)
  {
    printf("%d ",Temp->Data);
    Temp=Temp->Link_p;
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
      printf("The data was found in Node %d.",i);
    }

    temp=temp->Link_n;
    i++;
  }

}

void insertion()
{
 int n;
 do
 {
    printf("\nEnter the position where you want to add a node.\nPRESS 0 FOR EXIT\n");
    scanf("%d",&n);

    if(n==1)
    {

      struct Node *temp=malloc(sizeof(struct Node));
      printf("Enter the data for new first Node.\n");
      scanf("%d",&temp->Data);

      temp->Link_n=Head;
      Head->Link_p=temp;
      temp->Link_p=NULL;

      //Head pointer and size updated
      Head=temp;
      size++;

      display();

    }
    else if(n>1&&(n<=(size+1)))
    {
      int i=1;
      struct Node *temp_1=Head;
      struct Node *temp_2;

      struct Node *temp=malloc(sizeof(struct Node));
      printf("Enter the data for new Node.\n");
      scanf("%d",&temp->Data);

      while(i<(n-1))
      {
        temp_1=temp_1->Link_n;
        i++;
      }
      temp_2=temp_1->Link_n;

      temp_1->Link_n=temp;
      temp->Link_p=temp_1;
      temp->Link_n=temp_2;
      
      if(temp_2!=NULL)
      {
        temp_2->Link_p=temp;
      }

      //Size updated
      size++;

      display();
    }
    else
    {
      break;
    }

 } while (n!=0);

}

void deletion()
{
  int n;

  do
  {
    printf("\nEnter the position of the node to delete.\nPRESS 0 FOR EXIT\n");
    scanf("%d",&n);

    if(n==1)
    {
      Head=Head->Link_n;
      Head->Link_p=NULL;
      
      size--;

      display();
    }
    else if((n>1)&&(n<=size))
    {
      int i=1;

      struct Node *temp=Head;

      while(i<n)
      {
        temp=temp->Link_n;
        i++;
      }

      temp->Link_p->Link_n=temp->Link_n;

      if(temp->Link_n!=NULL)
      {
        temp->Link_n->Link_p=temp->Link_p;
      }

      size--;

      display();
    }
    else
    {
      break;
    }
  } while (n!=0);
  
}

void freespace()
{
  struct Node *temp_1=Head;

  while(temp_1!=NULL)
  {
    struct Node *temp_2=temp_1;
    temp_1=temp_1->Link_n;
    free(temp_2);
  }
}
