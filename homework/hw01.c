// 文曲星猜数
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #define N 4

void GuessNumber(int a[],int n)
{
    int i, j, x, y, cnt, find;
    int b[N] = {0};
    cnt = find = 0;

    printf("Start:\n");
    do{
        x = y = 0;

        for(i = 0; i < N; i++)
        {
            scanf("%d", &b[i]);
        }
        cnt++;

        for(i = 0; i < N; i++)
        {
            if(a[i] == b[i])
            {
                x++;
            }
            for(j = 0; j < N; j++)
            {
                if(a[i] == b[j]&&i!= j)
                {
                    y++;
                }
            }
        }
        if(x == 4)
        {
            printf("Congratulations!\n");
            find = 1;
        }
        else
        {
            printf("%dA%dB\n", x, y);
        }
    }while(cnt <= n);

    if(!find)
    {
        printf("You haven't guess the right number!");
    }
}

int main()
{
    int a[N] = {0};
    int i, flag, n;
    srand((unsigned int)time(NULL));

    do{
        for(i = 0; i < N; i++)
        {
            a[i] = rand() % 10;
        }
        flag = (a[0]!= a[1]&&a[0]!= a[2]&&a[0]!= a[3]&&a[1]!= a[2]&&a[1]!= a[3]&&a[2]!= a[3]&&a[0]!= 0);
    }while(!flag);

    printf("Iuput n:");
    scanf("%d", &n);
    GuessNumber(a, n);

    return 0;
}