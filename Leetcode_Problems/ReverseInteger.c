//PREPROCESSOR DIRECTORIES/MAIN FUCCTION NOT PRESENT//

https://leetcode.com/problems/reverse-integer/description/

int reverse(int x){


    int y=0;
    
    while(x!=0)
    {
        
        if((y<(INT_MIN/10))||((y==(INT_MIN/10))&&((x%10)<(INT_MIN%10)))) return 0;
        if((y>(INT_MAX/10))||((y==(INT_MAX/10))&&((x%10)>(INT_MAX%10)))) return 0;
      
        y=(y*10+x%10);
        x=x/10;
    }

    return y;
    
}