#include<stdio.h>
#include<stdlib.h>

struct Node* create(int isRoot);

struct Node
{
  int key;

  struct Node* left;
  struct Node *right;
};

int main()
{
  struct Node *root=create(1);

  return 0;
}

struct Node* create(int isRoot)
{
  int x;

  if(isRoot)
  {
    printf("Do you want to add a Node?\n");
    scanf("%d",&x);

    if(x==0) return 0;
  }                                                                                                                                                                                                          

  struct Node *newNode=malloc(sizeof(struct Node));
  printf("Enter data for the Node\n");
  scanf("%d",&newNode->key);

  printf("Do you want to add a left child for %d?\n",newNode->key);
  scanf("%d",&x);
  if(x==1) newNode->left=create(0);
  else newNode->left=NULL;

  printf("Do you want to add a right child for %d?\n",newNode->key);
  scanf("%d",&x);
  if(x==1) newNode->right=create(0);
  else newNode->right=NULL;

  return newNode;

}