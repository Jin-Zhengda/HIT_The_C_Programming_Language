// 模拟扑克洗牌发牌
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
 #define N 10
 #define M 52
 #define A 4
 #define B 13

typedef struct poker{
    char suit[N];
    char face[N];
}Poker;

char dst[][N]={"Spades","Hearts","Clubs","Diamonds"};
char str[][B]={"A","1","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};

void InitializingPoker(Poker card[])
{
    int i,j,k;
    i=j=k=0;
    while(i<M)
    {
        if(k==13)
        {
            k=0;
            j++;
        }
        strcpy(card[i].suit,dst[j]);
        strcpy(card[i].face,str[k]);
        i++;
        k++;
    }
}

void ShufflingPoker(Poker card[])
{
    int x,y;
    int i;
    for(i=0;i<60;i++)
    {
        srand((unsigned int)time(NULL));
        x=rand()%52;
        y=rand()%52;
        Sleep(1000);
        if(x!=y)
        {
            strcpy(card[x].suit,card[y].suit);
            strcpy(card[x].face,card[y].face);
        }
        else
        {
            continue;
        }
    }
}

void AssigningPoker(Poker card[])
{
    Poker* people[A][B]={NULL};
    int i,j,k;
    i=j=k=0;
    while(i<M)
    {
        if(j==4)
        {
            k++;
            j=0;
        }
        people[j][k]=&card[i];
        i++;
        j++;
    }
    printf("Assigning Result:\n");
    for(i=0;i<A;i++)
    {
        printf("No.%d:\n",i+1);
        for(j=0;j<B;j++)
        {
            printf("%-8s.%-8s",people[i][j]->suit,people[i][j]->face);
            if(j%4==0)
            {
                printf("\n");
            }
        }
        printf("\n");
    }
}

void PrintPoker(Poker card[])
{
    int i;
    for(i=0;i<M;i++)
    {
        printf("%-8s.%-8s",card[i].suit,card[i].face);
        if((i+1)%4==0)
        {
            printf("\n");
        }
    }
}

int main(void)
{
    Poker card[M];
    InitializingPoker(card);
    PrintPoker(card);
    printf("\n\n");
    printf("Shffle pokers now.Please wait sometime...\n\n");
    ShufflingPoker(card);
    PrintPoker(card);
    printf("\n\n");
    AssigningPoker(card);
    return 0;
}