#include<stdio.h>
#include<string.h>
#include<ctype.h> 
#include <unistd.h>

int main()
{
  char str[50],ch,alphas[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  int i,n,j,k,flag,is=0;

  printf("Enter the string.\n");
  fgets(str,50,stdin);
  n=strlen(str);
  n--;

  for(k=0;k<n;k++)
  {
  for(i=0;i<n;i++)
  {
    ch=str[i];
    flag=0;
    j=0;
    is=0;
    if(isupper(ch))
    {
      while(flag==0)
      {
        printf("%c",alphas[j]);
        usleep(1000);
        
        if(ch==alphas[j])
        {
          flag=1;
        }
        else
        {
          printf("\b");
          fflush(stdout);
          j++;
        }
      }
    }
    else if(islower(ch))
    {
      while(flag==0)
      {
        alphas[j]=tolower(alphas[j]);
        printf("%c",alphas[j]);
        usleep(1000);

        if(ch==alphas[j])
        {
          flag=1;
        }
        else
        {
          printf("\b");
          fflush(stdout);
          j++;
        }
      }
    }
    else
    {
      printf(" "); 
    }
    if(i==k)
    {
      printf("\n");
      break;
    }
  }
  
  }

  return 0;

}