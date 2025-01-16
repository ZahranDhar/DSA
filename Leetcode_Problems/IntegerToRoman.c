//PREPROCESSOR DIRECTORIES/MAIN FUCCTION NOT PRESENT//

https://leetcode.com/problems/integer-to-roman/description/

char* intToRoman(int num) {
    int digits=0,numcpy,i=0,k,Digit;
    char *RomStr,R1,R5,R10;
    numcpy=num;
    digits=0;
    while(numcpy!=0)
    {
        numcpy/=10;
        digits++;
    }

    RomStr=malloc((sizeof(char))*(digits*4)+1);
    
    while(digits>0)
    {
        switch(digits)
        {
            case 4:
            R1='M';
            Digit=num/1000;
            break;

            case 3:
            R1='C';
            R5='D';
            R10='M';
            Digit=num/100;
            break;

            case 2:
            R1='X';
            R5='L';
            R10='C';
            Digit=num/10;
            break;

            case 1:
            R1='I';
            R5='V';
            R10='X';
            Digit=num;
            break;

        }

        switch(Digit)
        {
            case 0:
            break;

            case 4:
            RomStr[i++]=R1;
            RomStr[i++]=R5;
            break;

            case 5:
            RomStr[i++]=R5;
            break;

            case 9:
            RomStr[i++]=R1;
            RomStr[i++]=R10;
            break;

            default:
            if(Digit>5)
            {
                RomStr[i++]=R5;
                Digit-=5;
            }
            for(k=1;k<=Digit;k++) RomStr[i++]=R1;
        }

        num%=(int)pow(10,(--digits));

    }
    RomStr[i]='\0';

    return RomStr;
}