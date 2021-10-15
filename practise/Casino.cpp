#include<bits/stdc++.h>
using namespace std;


int cash=100;

void Play(int bet)
{
    char *C=(char*)malloc(3*sizeof(char));
    C[0]='Q';C[1]='J';C[2]='K';
    printf("Shuffling.....\n");
    printf("Shuffling Done...\n");
    srand(time(NULL)); // seeding the rndom generator
    int i;
    for(i=0;i<5;i++)
    {
        int x=rand()%3;
        int y=rand()%3;
        char temp=C[x];
        C[x]=C[y];
        C[y]=temp;
    }

    int guess;
    printf("What the posotion of the queen.....1, 2 or 3 ? : ");
    scanf("%d",&guess);
    if(C[guess-1]=='Q')
    {
        cash+=3*bet;
        printf("You Win !! Result =\"%c %c %c \" Total Cash= $%d\n",C[0],C[1],C[2],cash);
    }
    else
    {
        cash-=bet;
        printf("You Loose !! Result =\"%c %c %c \" Total Cash= $%d\n",C[0],C[1],C[2],cash);
    }
    free(C);
}

int main()
{
    printf("                *****Welcome to the Virtual Casino*****                    \n");
    printf("Total Cash: $%d\n",cash);
    int bet;
    while(cash>0)
    {
        printf("What is your bet amount ? $ ");
        scanf("%d",&bet);
        if(bet==0 || bet>cash) 
        {
            printf("Game Quiting......\n");
            printf("Either amount is 0 ir greater that available cash\n");
            break;
        }
        Play(bet);
        printf("            *********************************************              \n");
    }
}