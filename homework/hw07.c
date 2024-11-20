// 报数游戏
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

// 生成1~10的一个随机数
int Rand(void)
{
    srand((unsigned int)time(NULL));
    return rand()%10+1;
}

// 确定顺序
int Order(void)
{
    int r,i;
    r=Rand();

    if(r<=5)
    {
        printf("Your order:1\n");
        return 1;
    }
    else
    {
        printf("Computer's order:1\n");
        return 0;
    }
}

// 玩家与电脑依次报数
int Progress(int first)
{
    int i=1;
    do{
        if(first)
        {
            if((30-i)%3==1)
            {
                printf("Computer's order:%d\n",i+1);
                i++;
            }
            else if((30-i)%3==2)
            {
                printf("Computer's order:%d\n",i+1);
                printf("Computer's order:%d\n",i+2);
                i=i+2;
            }
            else
            {
                int ra;
                ra=Rand();
                if(ra<=5)
                {
                    printf("Computer's order:%d\n",i+1);
                    i++;
                }
                else
                {
                    printf("Computer's order:%d\n",i+1);
                    printf("Computer's order:%d\n",i+2);
                    i=i+2;
                }
            }

            if(i==30)
            {
                return 0;
            }

            first=0;
        }
        else
        {
            int k;

            printf("Your time/times(please input 1 or 2):");
            scanf("%d",&k);

            if(k==1)
            {
                printf("Your order:%d\n",i+1);
                i++;
            }
            else
            {
                printf("Your order:%d\n",i+1);
                printf("Your order:%d\n",i+2);
                i=i+2;
            }

            if(i==30)
            {
                return 1;
            }

            first=1;
        }
    }while(i<=30);
}

int main()
{
    int first,out;

    first=Order();
    out=Progress(first);

    if(out)
    {
        printf("You win!\n");
    }
    else
    {
        printf("You lose!\n");
    }

    return 0;
}