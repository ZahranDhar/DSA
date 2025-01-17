//PREPROCESSOR DIRECTORIES/MAIN FUCCTION NOT PRESENT//

https://leetcode.com/problems/longest-common-prefix/description/

char* longestCommonPrefix(char** strs, int strsSize) {

    char *prefix;
    int i=0,j=0,strsSSize=200;

    for(i=0;i<strsSize;i++)
    {
        if((strlen(strs[i]))<(strsSSize)) strsSSize=strlen(strs[i]);
    }

    prefix=malloc(strsSSize+1);

    for(j=0;j<strsSSize;j++)
    {
        for(i=0;i<strsSize-1;i++)
        {
            if(strs[i][j]!=strs[i+1][j])
            {
                prefix[j]='\0';
                return prefix;
            }
        }
        prefix[j]=strs[i][j];

    }

    prefix[j]='\0';

    return prefix;
    
}