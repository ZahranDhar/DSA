#include<stdio.h>
#define size 10

int top=-1;
int stack[size];

void push();
void pop();
int IsEmpty();
int IsFull();
void display();


int main()
{
  int x,y;

  do
  {
    printf("\nEnter\n1 for PUSH\n2 for POP\n3 for DISPLAY\n0 for EXIT\n");
    scanf("%d",&x);
    
    switch(x)
    {
      case 1:
      if(IsFull())
      {
        printf("STACK OVERFLOW--\n");
      }
      else
      {
        push();
        printf("SUCCESS\n");
      }
      break;

      case 2:
      if(IsEmpty())
      {
        printf("STACK UNDERFLOW\n");
      }
      else
      {
        pop();
        printf("SUCCESS\n");
      }
      break;

      case 3:
      display();
      break;

      default:
      printf("INVALID VALUE\n");
      
    }
  }while(x!=0);
}

void push()
{
  int x;

  top++;
  printf("Enter the element to PUSH.\n");
  scanf("%d",&stack[top]);
 
}

void pop()
{
  top--;
}

int IsEmpty()
{
  if(top>-1)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

int IsFull()
{
  if(top<(size-1))
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

void display()
{
  int i;

  for(i=0;i<=top;i++)
  {
    printf("%d ",stack[i]);
  }
}