//PREPROCESSOR DIRECTORIES/MAIN FUCCTION NOT PRESENT//

https://leetcode.com/problems/longest-palindromic-substring/description/

char* longestPalindrome(char* s) {
        int i,j,k,iPal=0,jPal=0,sSize,PalFound=0,PalSize,num,LongestPal=1;

        sSize=strlen(s);
        if (sSize == 1) return s;

        for(i=0;i<sSize-1;i++)
        {
            for(j=sSize-1;j>i;j--)
            {
                if(s[i]==s[j])
                {
                    num=0;
                    PalSize=(j-i)+1;
                    PalFound=1;

                    for(k=i;k<=(j-(PalSize/2));k++)
                    {
                        if(s[k]!=s[j-num])
                        {
                            PalFound=0;
                            break;
                        } 
                        
                        num++;
                    }

                    if((PalFound==1)&&(PalSize>LongestPal)) 
                    {
                        iPal=i;
                        jPal=j;
                        LongestPal=PalSize;
                    }
                }

            }
        }
        
        char *PalStr=malloc(LongestPal+1);
        for(i=0;i<LongestPal;i++)
        {
            PalStr[i]=s[iPal+i];
        }
        PalStr[i]='\0';

        return PalStr;

    }