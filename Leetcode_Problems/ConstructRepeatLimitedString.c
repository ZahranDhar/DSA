//PREPROCESSOR DIRECTORIES/MAIN FUCCTION NOT PRESENT//

https://leetcode.com/problems/construct-string-with-repeat-limit/description/


char* repeatLimitedString(char* s, int repeatLimit) {
int freq[26]={0},n,i=0,subtop,top,low,index=0,e_added=0;

    n=strlen(s);
    
    char *repeatLimitedString=malloc(n+1);

    while(s[i]!='\0')
    {
        freq[(s[i]-'a')]++;
        i++;
    }

    for(i=25;i>=0;i--)
    {
        if(freq[i]>=0)
        {
        top=i;
        break;
        }
   }

   for(i=0;i<=25;i++)
    {
        if(freq[i]>0)
        {
        low=i;
        break;
        }
   }
        while(1)
        {
            int additions=(freq[top]>repeatLimit?repeatLimit:freq[top]);
            for(i=1;i<=additions;i++)
            {
                repeatLimitedString[index++]=top+'a';
                freq[top]--;
            }

            if(freq[top]>0)
            {
                e_added=0;
                for(subtop=(top-1);subtop>=low;subtop--)
                {
                    if(freq[subtop]>0)
                    {
                        repeatLimitedString[index++]=subtop+'a';
                        freq[subtop]--;
                        e_added=1;
                        break;
                    }
                }
                if(!e_added)break;
            }
            else
            {
                for(subtop=top-1;subtop>=low;subtop--)
                {
                    if(freq[subtop]>0)
                    {
                        top=subtop;
                        break;
                    }
                }
                if(!freq[top])break;
            }
        }
    
    repeatLimitedString[index]='\0';
    return repeatLimitedString;

}
