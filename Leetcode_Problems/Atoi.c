//PREPROCESSOR DIRECTORIES/MAIN FUCCTION NOT PRESENT//

https://leetcode.com/problems/string-to-integer-atoi/description/

//Code 1
int myAtoi(char* s) {

    int sign=1,i=0;
    long int x=0;

    while(s[i]==' ') i++;

    if (s[i]=='-'||s[i]=='+')
    {
        (s[i]=='-')? (sign=-1):(sign=1);
        i++;
    }

    while(isdigit(s[i]))
    {
        x=(x*10)+(s[i]-48);
        i++;

        if(x>INT_MAX)
        {
            return (sign==1)? INT_MAX:INT_MIN;
        }
        
    }

    return sign*x;
}

//Code 2
int myAtoi(char* s) {
    int  x=0,i=0,sign=1,start_added=0,Digit;

    while(s[i]!='\0')
    {
        if(!start_added)
        {
            if(s[i]>31&&s[i]<59)
            {
                if(s[i]==' ') 
                {
                    i++;
                    continue;
                }
                else if(s[i]=='-')
                {
                    sign*=-1;
                    start_added=1;
                    i++;
                    continue;
                }
                else if(s[i]=='+')
                {
                    start_added=1;
                    i++;
                    continue;
                }
                else if(s[i]>47&&s[i]<58)
                {
                    x=x*10+(s[i]-48);
                    start_added=1;
                    i++;
                    continue;
                }
                else return 0;

            }
        }
        if((s[i]<48||s[i]>57)) return sign*x;

        Digit=s[i]-48;
        if(((x*sign)>INT_MAX/10)||(((x*sign)==INT_MAX/10)&&((Digit>(INT_MAX%10)||(Digit==(INT_MAX%10)))))) 
        return INT_MAX;
        if(((x*sign)<INT_MIN/10)||(((x*sign)==INT_MIN/10)&&(((-Digit)<(INT_MIN%10)||((-Digit)==(INT_MIN%10)))))) 
        return INT_MIN;

        x=x*10+(s[i]-48);
        i++;

    }

    return sign*x;
    
}