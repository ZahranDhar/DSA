//PREPROCESSOR DIRECTORIES/MAIN FUCCTION NOT PRESENT//

https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

int lengthOfLongestSubstring(char* s) {
    int n=0,i=0,j=0,PC=0,HC=0,ch_found=0;

    n=strlen(s);

    char *LongestString=malloc((n+1)*sizeof(char));
    LongestString[0]='\0';

    while(s[i]!='\0')
    {
        j=0;
        ch_found=0;
        while(LongestString[j]!='\0')
        {   
            if(s[i]==LongestString[j]) 
            {
                ch_found=1;
                break;
            }
            j++;
        }

        if(!ch_found)
        {
            LongestString[j]=s[i];
            PC++;
            LongestString[j+1]='\0';
            if(HC<PC) HC++;
            i++;
        }
        else
        {
            i-=(PC-(j+1));
            j=0;
            PC=0;
            LongestString[0]='\0';
        }
        

    }

    return HC;
}