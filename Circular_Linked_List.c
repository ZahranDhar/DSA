//Circular Linked List

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
  search();
  insertion();
  deletion();
  freespace();

}

void create()
{
  int i;

  do
  {
    printf("Enter the number of Nodes.\n");
    scanf("%d",&size);

  } while (size<2);
  
  struct Node *temp_n;
  for(i=1;i<=size;i++)
  {
    if(i==1)
    {
      struct Node *temp=malloc(sizeof(struct Node));
      temp_n=temp;
      //Set Head pointer
      Head=temp;
    }
    else if((i>1)&&(i<size))
    {
      struct Node *temp=malloc(sizeof(struct Node));

      temp_n->Link=temp;

      temp_n=temp;
    }
    else
    {
      struct Node *temp=malloc(sizeof(struct Node));
      temp_n->Link=temp;
      temp->Link=Head;
      
    }
  }
}

void read()
{
  struct Node *temp=Head;
  int i=1;

  do
  {
    printf("Enter the data for Node %d:",i);
    scanf("%d",&temp->Data);

    temp=temp->Link;
    i++;
  } while (temp!=Head);
  

}

void display()
{
  struct Node *temp=Head;

  printf("The Linked List data is:\n");
  do
  {
    printf("%d ",temp->Data);

    temp=temp->Link;
  } while (temp!=Head);
  
}

void search()
{
  int x,i=1;
  struct Node *temp=Head;

  printf("\nEnter the data to search for.\n");
  scanf("%d",&x);

  do
  {
    if(temp->Data==x)
    {
      printf("The data was found in Node %d.\n",i);
    }
    temp=temp->Link;
    i++;
  } while (temp!=Head);
  
}

void insertion()
{ 
  int n;

  do
  {
    printf("\nEnter the position to add Node.\nPRESS 0 FOR EXIT\n");
    scanf("%d",&n);

  
    struct Node *temp_n=Head;

    if(n==1)
    {
      struct Node *temp=malloc(sizeof(struct Node));
      printf("Enter data for Node %d.\n",n);
      scanf("%d",&temp->Data);

      do
      {
        temp_n=temp_n->Link;
      } while (temp_n->Link!=Head);

      temp_n->Link=temp;
      temp->Link=Head;

      Head=temp;
      size++;
    }
    else if (n==(size+1))
    {
      struct Node *temp=malloc(sizeof(struct Node));
      printf("Enter data for Node %d.\n",n);
      scanf("%d",&temp->Data);

      temp_n=Head;
      while(temp_n->Link!=Head)
      {
        temp_n=temp_n->Link;
      }

      temp_n->Link=temp;
      temp->Link=Head;

      size++;
    }
    else if((n>1)&&(n<=size))
    {
      int i=1;

      struct Node *temp=malloc(sizeof(struct Node));
      printf("Enter data for Node %d.\n",n);
      scanf("%d",&temp->Data);
      
      struct Node *temp_p=Head;
      while(i<(n-1))
      {
        temp_p=temp_p->Link;
        i++;
      }
      
      temp->Link=temp_p->Link;
      temp_p->Link=temp;

      size++;
    }
    display();
  } while (n!=0);
  
}

void deletion()
{
  int n;
  
  do
  {
    printf("\nEnter the position of Node to delete.\nPRESS 0 FOR EXIT\n");
    scanf("%d",&n);

    struct Node *temp=malloc(sizeof(struct Node));
    struct Node *temp_n=malloc(sizeof(struct Node));

    if(n==1)
    {
      temp=Head->Link;

      temp_n=Head;
      while(temp_n->Link!=Head)
      {
        temp_n=temp_n->Link;
      }

      temp_n->Link=temp;
      free(Head);
      Head=temp;
      size--;
    }
    else if((n>1)&&(n<=size))
    {
      int i=1;
      temp=Head;

      while(i<(n-1))
      {
        temp=temp->Link;
        i++;
      }

      temp_n=temp->Link->Link;
      free(temp->Link);
      temp->Link=temp_n;

      size--;
    }

    display();
  } while (n!=0);
  
}

void freespace()
{
  int i;
  struct Node *temp=Head;
  struct Node *temp_n;

  for(i=1;i<=size;i++)
  {
    temp_n=temp->Link;
    free(temp);
    
    temp=temp_n;
  }
}