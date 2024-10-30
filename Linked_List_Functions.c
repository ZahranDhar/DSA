//Linked List Functions//

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Data;
    
    struct Node *Link;
};

void read(struct Node *temp);
void display(struct Node *temp, int flag);
void search(struct Node *temp);
struct Node* insertion(struct Node *temp);
void deletion(struct Node *temp);
void freespace(struct Node *temp);


int main()
{
    struct Node* First=(struct Node*)(malloc(sizeof(struct Node)));
    struct Node* Second=(struct Node*)(malloc(sizeof(struct Node)));
    struct Node* Third=(struct Node*)(malloc(sizeof(struct Node)));
    struct Node* Zeroth=NULL;
    
    First->Link=Second;
    Second->Link=Third;
    Third->Link=NULL;
    
    read(First);
    display(First,0);
    search(First);
    Zeroth=insertion(First);
    deletion(Zeroth);
    
    freespace(First);
    
    return 0;
}

void read(struct Node* temp)
{
    int n=1;
    while(temp!=NULL)
    {
    printf("Enter Data for Node %d.\n",n);
    scanf("%d",&(temp->Data));
    temp=temp->Link;
    n++;
    }
}

void display(struct Node *temp, int flag)
{
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

void search(struct Node* temp)
{
  int x,n=1,flag=0;

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

struct Node* insertion(struct Node *temp)
{
    //Insertion at start
    struct Node* Zeroth=(struct Node*)(malloc(sizeof(struct Node)));
    printf("Enter Data for new first Node.\n");
    scanf("%d",&(Zeroth->Data));
    Zeroth->Link=temp;
    display(Zeroth,1);
    
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
    display(Zeroth,1);

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
    display(Zeroth,1);

    return Zeroth;

}

void deletion(struct Node* temp)
{
  //Deleting first Node
  struct Node* tempn=temp->Link;
  free(temp);
  printf("//First Node deleted//.\n");
  display(tempn,1);

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
  display(tempn,1);

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
  display(tempn,1);

}

void freespace(struct Node* temp)
{
  struct Node* tempn=NULL;
  while(temp!=NULL)
  {
    tempn=temp->Link;
    free(temp);
    temp=tempn;
  }
}