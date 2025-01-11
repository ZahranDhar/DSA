//PREPROCESSOR DIRECTORIES/MAIN FUCCTION NOT PRESENT//

https://leetcode.com/problems/palindrome-number/description/

//Code 1
bool isPalindrome(int x) {

    if(x<0) return 0;
    else if(x<10) return 1;

    int xcpy,i=0,length=0;

    xcpy=x;
    while(xcpy!=0)
    {
        xcpy/=10;
        length++;
    }

    int *xArr=malloc(length*sizeof(int));

    while(x!=0)
    {
        xArr[i++]=(x%10);
        x/=10;
    }

    for(i=0;i<(length/2);i++)
    if(xArr[i]!=xArr[length-i-1])
    return 0;
    
    return 1;
    
}


//Code 2
bool isPalindrome(int x) {

    if(x<0) return false;
    else if(x<10) return true;
    
    int xcpy,Digit,length=0;

    xcpy=x;

    while(xcpy!=0)
    {
        xcpy/=10;
        length++;
    }

    while(length>1)
    {
        Digit=x/(pow(10,(length-1)));
        if(Digit!=(x%10)) return false;
        x%=(pow(10,length-1));
        x/=10;
        length-=2;
    }

    return true;
    
}