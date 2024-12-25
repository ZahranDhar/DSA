//PREPROCESSOR DIRECTORIES/MAIN FUCCTION NOT PRESENT//

https://leetcode.com/problems/reverse-integer/description/

int reverse(int x){

    long int y=0;
    
    while(x!=0)
    {
        y=(y*10+x%10);
        if(y<-(pow(2,31))||y>pow(2,31))
        {
            y=0;
            break;
        }
        x=x/10;
    }

    return y;
    
}