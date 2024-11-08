//Linked List Functions//

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Data;
    
    struct Node *Link;
};

struct Node *Head;

void create();
void read();
void display(int flag);
void search();
void insertion();
void deletion();
void freespace();


int main()
{
    create();
    read();
    display(0);
    search();
    insertion();
    deletion();
    freespace();
    
    return 0;
}

void create()
{
  int i,n;

  do
  {
    printf("Enter the number of Nodes.\n");
    scanf("%d",&n);

    if(n<2)
    {
      printf("ERROR\n");
    }
  } while (n<2);

  struct Node *Temp_1=NULL;
  for(i=1;i<=n;i++)
  {
    if(i==1)
    {
      Head=(struct Node*)(malloc(sizeof(struct Node)));
      
      Temp_1=Head;
    }
    else
    {
      struct Node *Temp_2=(struct Node*)(malloc(sizeof(struct Node)));
      Temp_2->Link=NULL;

      Temp_1->Link=Temp_2;
      Temp_1=Temp_2;
    }
  }
}

void read()
{
    int n=1;
    struct Node* temp=Head;
    while(temp!=NULL)
    {
    printf("Enter Data for Node %d.\n",n);
    scanf("%d",&(temp->Data));
    temp=temp->Link;
    n++;
    }
}

void display(int flag)
{
    struct Node *temp=Head;
    if(flag==0)
    {
      printf("The Data is:\n");
    }
    else
    {
      printf("The new Data is:\n");
    }

    while(temp!=NULL)
    {
    printf("%d ",temp->Data);
    temp=temp->Link;
    }
    printf("\n");
}

void search()
{
  int x,n=1,flag=0;
  struct Node *temp=Head;

  printf("Enter the Data you want to search for.\n");
  scanf("%d",&x);

  while(temp!=NULL)
  {
    if(temp->Data==x)
    {
      printf("The data was found in Node %d.\n",n);
      flag=1;
    }
    temp=temp->Link;
    n++;
  }
  if(flag==0)
  {
    printf("The Data was not found.\n");
  }
}

void insertion()
{
    struct Node *temp=Head;
    //Insertion at start
    struct Node* Zeroth=(struct Node*)(malloc(sizeof(struct Node)));
    printf("Enter Data for new first Node.\n");
    scanf("%d",&(Zeroth->Data));
    Zeroth->Link=temp;

    //Head Pointer Updated
    Head=Zeroth;
    display(1);
    
    //Temp Pointer Updated
    temp=Zeroth;     
    
    //Insertion at end
    struct Node* Fourth=(struct Node*)(malloc(sizeof(struct Node)));
    printf("Enter the Data for new last Node.\n");
    scanf("%d",&(Fourth->Data));
    Fourth->Link=NULL;
    
    while(temp->Link!=NULL)
    {
    temp=temp->Link;
    }
    temp->Link=Fourth;
    display(1);

    //Temp Pointer Updated
    temp=Zeroth; 

    //Insertion at n
    int n,i=2;
    printf("Enter the position where you want to add the Node.\n");
    scanf("%d",&n);
    struct Node* Nth=(struct Node*)(malloc(sizeof(struct Node)));
    printf("Enter Data for N'th Node.\n");
    scanf("%d",&(Nth->Data));
    struct Node* prev=temp;
    struct Node* pres=temp->Link;
    while(i<n)
    {
      prev=pres;
      pres=pres->Link;
      i++;
    }
    prev->Link=Nth; 
    Nth->Link=pres;
    display(1);

}

void deletion()
{
  struct Node* temp=Head;
  //Deleting first Node
  struct Node* tempn=temp->Link;
  free(temp);
  printf("//First Node deleted//.\n");

  //Head Node Updated
  Head=tempn;
  display(1);

  //Temp Pointer Updated
  temp=tempn; 

  //Deleting last Node
  while(temp->Link->Link!=NULL)
  {
    temp=temp->Link;
  }
  free(temp->Link);
  temp->Link=NULL;
  printf("//Last Node deleted//.\n");
  display(1);

  //Temp Pointer Updated
  temp=tempn; 

  //Deleting N'th Node
  int n,i=2;
  printf("Enter the position of Node you want to delete.\n");
  scanf("%d",&n);
  struct Node* prev=temp;
  struct Node* pres=temp->Link;
  struct Node* next=pres->Link;
  while(i<n)
  {
    prev=pres;
    pres=pres->Link;
    next=pres->Link;
    i++;
  }
  prev->Link=next;
  free(pres);
  printf("//Nth Node deleted//.\n");
  display(1);

}

void freespace()
{
  struct Node* temp=Head;
  struct Node* tempn=NULL;
  while(temp!=NULL)
  {
    tempn=temp->Link;
    free(temp);
    temp=tempn;
  }
}