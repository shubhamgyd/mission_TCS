#include<stdio.h>
#include<math.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>


// Utility function which converts octal to decimal
int OctalToDecimal(int n) {
    int p = 0, decimal = 0, r;
    
    while(n>0){
        
        // retrieving the right-most digit of n
        r = n % 10;
        
        // dividing n by 10 to remove the
        // right-most digits since it is already
        // scanned in previous step
        n = n / 10;
        
        decimal = decimal + r * pow( 8 , p );    
        ++p;
        
    }
    
    return decimal;
}

// Utility function which conert hexadecimal to decimal
int HexadecimalToDecimal(char *hex) {
    int p = 0; 
    int decimal = 0;
    int r, i;
    
    // instead of reading charcacters from Right-To-Left
    // we can also read character from Left-To-Right
    // we just have to initialize p with strlen(c) - 1
    // and decrement p in each iteration
    for(i = strlen(hex) - 1 ; i >= 0 ; --i){
        
        // converting c[i] to appropriate decimal form
        if(hex[i]>='0'&&hex[i]<='9'){
            r = hex[i] - '0';
        }
        else{
            r = hex[i] - 'A' + 10;
        }
        
        decimal = decimal + r * pow(16 , p);
        ++p;
    }
    
    return decimal;
}


// Utility function which generates random integer between range ( minimum and maximum)
int random_in_range( int minimum, int maximum )
{
  int result;
  do result = rand();
  while (result < minimum || maximum < result);
  return result;
}


int main()
{

    int option;
    // loop will run option is valid
    // valid option between 1 to 4
    // otherwise program exit;
    do
    {
        printf("Enter an option: ");
        // input the option value
        scanf("%d",&option);

        
        if(option==1)
        {
            printf("Enter three values ( octal decimal hexadecimal): ");
            int octal,decimal;
            char hex[100];

            // read the three numbers : octal decimal, hexadecimal
            scanf("%d %d %s",&octal,&decimal,hex);

            int octToDecimal=OctalToDecimal(octal);     // convert to decimal
            int hexToDecimal=HexadecimalToDecimal(hex); // convert to decimal

            // compare octalToDecimal number with other two number
            if(octToDecimal>decimal && octToDecimal<hexToDecimal)
            {
                printf("Middle value: %d\n",octToDecimal);
            }
            // compare decimal number with other two number
            else if(decimal>octToDecimal && decimal<hexToDecimal)
            {
                printf("Middle value: %d\n",decimal);
            }
            // else print the hexaDecimal number
            else
            {
                printf("Middle value: %d\n",hexToDecimal);
            }
        }
        if(option==2)
        {
            printf("Enter an integer: ");
            int n;
            scanf("%d",&n);

            // it will generate the pattern
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<i;j++)
                {
                    printf("*");
                }
                printf("\n");
            }
        }
        if(option==3)
        {
            float angle;
            printf("Enter angle:");
            scanf("%f",&angle);
            float result=sin(angle)*sin(angle)-3*cos(angle);
            printf("Value of sin^2(x)-3cos(x): %f\n",result);

        }
        if(option==4)
        {
            int num= random_in_range( 100, 999 );  // get the random number between 100 and 999
            printf("Random number: %d\n",num);
            int middleDigit;              // it will store the middle digit of random number
            int temp=num;
            int count=0;
            while(temp>0)
            {
                middleDigit=temp%10;
                temp/=10;
                count+=1;
                if(count==2)
                {
                    break;
                }
            }
            printf("Middle digit: %d\n",middleDigit);
        }

        //if option is not valid, then exit the program
        else if(option<1 || option>4)
        {
            printf("Exit from the program.....\n");
            exit(0);
        }
    } while (option>=1 && option<=4);
    return 0;
    
}