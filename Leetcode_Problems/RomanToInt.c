//PREPROCESSOR DIRECTORIES/MAIN FUCCTION NOT PRESENT//

https://leetcode.com/problems/roman-to-integer/description/

int romanToInt(char* s) {
    int LastVal=10000,PresVal,result=0,i=0;

    while(s[i]!='\0')
    {
        switch(s[i])
        {
            case 'I':
            PresVal=1;
            break;

            case 'V':
            PresVal=5;
            break;

            case 'X':
            PresVal=10;
            break;

            case 'L':
            PresVal=50;
            break;

            case 'C':
            PresVal=100;
            break;

            case 'D':
            PresVal=500;
            break;

            case 'M':
            PresVal=1000;
            break;

        }

        (LastVal>=PresVal)? (result+=PresVal):(result=((result-LastVal)+(PresVal-LastVal)));

        LastVal=PresVal;
        i++;
    }

    return result;

    
}