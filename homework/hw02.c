// 评分排序并输出各个评委评分与平均分之差的和
 #include <stdio.h>
 #include <math.h>
 #define n 3
 #define m 5

void ReadNumber(int number[], int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        number[i] = i + 1;
    }
}

void ReadScore(int score[][m])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("Input No.%d's score:\n", i + 1);
        for (j = 0; j < m; j++)
        {
            scanf("%d", &score[i][j]);
        }
    }
}

void Average(int score[][m], int aver[]) //去除一个最高分和一个最低分并计算平均分
{
    int i, j,max, min;
    for (i = 0; i < n; i++)
    {
        max = score[i][0];
        min = score[i][0];
        for (j = 0; j < m; j++)
        {
            if (max < score[i][j])
            {
                max = score[i][j];
            }
            if (min > score[i][j])
            {
                min = score[i][j];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            aver[i] = aver[i] + score[i][j];
        }
        aver[i] = (aver[i] - max - min) / (m - 2);
    }
}

void DateSort(int input[], int onesnum[], int num) //对输入进行排序
{
    int i, j, t1, t2;
    for (i = 0; i < num - 1; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (input[j] > input[i])
            {
                t1 = input[j];
                input[j] = input[i];
                input[i] = t1;

                t2 = onesnum[j];
                onesnum[j] = onesnum[i];
                onesnum[i] = t2;
            }
        }
    }
}

void Judge(int score[][m], int aver[], int deviation[]) //计算每个评委评分与平均分之差的绝对值之和
{
    int i, j;
    for (j = 0; j < m; j++)
    {
        for (i = 0; i < n; i++)
        {
            deviation[j] = deviation[j] + (fabs(score[i][j] - aver[i]));
        }
    }
}

void Print(int output[], int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        printf("%2d ", output[i]);
    }
    printf("\n");
}

int main()
{
    int score[n][m] = {0};
    int StuNum[n] = {0};
    int JudNum[m] = {0};
    int aver[n] = {0};
    int deviation[m] = {0};

    ReadNumber(StuNum, n);
    ReadNumber(JudNum, m);
    ReadScore(score);
    Average(score, aver);
    DateSort(aver, StuNum, n);
    printf("Students:\n");
    Print(StuNum, n);
    Print(aver, n);
    Judge(score, aver, deviation);
    DateSort(deviation, JudNum, m);
    printf("Judges:\n");
    Print(JudNum, m);
    Print(deviation, m);
    return 0;
}