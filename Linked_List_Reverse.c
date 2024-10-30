//Linked List Reverse

#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int Data;

  struct Node* Link;
};

void display(struct Node* temp);
void revlist(struct Node* temp);

int main()
{
  int i;
  
  //Allocating memory for nodes
  struct Node* Head=(struct Node*)(malloc(sizeof(struct Node)));
  struct Node* First=(struct Node*)(malloc(sizeof(struct Node)));
  struct Node* Second=(struct Node*)(malloc(sizeof(struct Node)));

  Head->Link=First;
  Head->Data=10;
  First->Link=Second;
  First->Data=20;
  Second->Link=NULL;
  Second->Data=30;
  
  display(Head);
  revlist(Head);

  return 0;

}

void display(struct Node* temp)
{
  printf("\nThe Data is:\n");
  while(temp!=NULL)
  {
    printf("%d->",(temp->Data));
    temp=temp->Link;
  }
}

void revlist(struct Node* temp)
{
  //Node Counter
  int n=1;
  struct Node* tempn=temp;
  while(temp->Link!=NULL)
  {
    temp=temp->Link;
    n++;
  }

  //Linked List Reverse
  struct Node* First=tempn;
  
  

  display(First);
}


