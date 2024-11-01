//Linked List Nodes Counter

#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int Data;

  struct Node* Link;
};

int counter(struct Node* temp);

int main()
{
  
  int n;

  //Allocating memory for nodes
  struct Node* Head=(struct Node*)(malloc(sizeof(struct Node)));
  struct Node* First=(struct Node*)(malloc(sizeof(struct Node)));
  struct Node* Second=(struct Node*)(malloc(sizeof(struct Node)));

  Head->Link=First;
  First->Link=Second;
  Second->Link=NULL;

  n=counter(Head);

  printf("%d",n);

}

int counter(struct Node* temp)
{
  int n=1;
  while(temp->Link!=NULL)
  {
    temp=temp->Link;
    n++;
  }

  return n;
}