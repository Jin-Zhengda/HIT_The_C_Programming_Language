#include <stdio.h>
#define M 3
#define L 10

//输入：分数记录数组，总分数组，平均分数组，人数
//功能：计算总分和平均分
//输出：无
void CountingScore(int score[][M],int sum[],float aver[],int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        sum[i]=0;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<M; j++)
        {
            sum[i]=sum[i]+score[i][j];
        }
        aver[i]=(float)sum[i]/M;
    }
}

//输入：分数记录数组，课程总分数组，课程平均分数组，人数
//功能：计算课程总分和平均分
//输出：无
void CountingLesson(int score[][M],int lsum[],float laver[],int n)
{
    int i,j;
    for(j=0; j<M; j++)
    {
        for(i=0; i<n; i++)
        {
            lsum[j]=lsum[j]+score[i][j];
        }
        laver[j]=(float)lsum[j]/n;
    }
}

int main(void)
{
    int n,i,j;
    do{
        printf("Input the total number of the students(n<40):\n");
        scanf("%d",&n);
    }while(n<=0||n>=40);//判断输入是否合法
    char stuID[n][L];
    float aver[n],laver[M];
    int sum[n],lsum[M]= {0};
    int score[n][M];
    printf("Input student¡¯s ID and score as: MT  EN  PH:\n");
    for(i=0; i<n; i++)//读入学生各科成绩
    {
        scanf(" %s",&stuID[i]);
        for(j=0; j<M; j++)
        {
            scanf("%d",&score[i][j]);
        }
    }
    CountingScore(score,sum,aver,n);
    CountingLesson(score,lsum,laver,n);
    printf("Counting Result:\n");//输出计算后结果
    printf("Student¡¯s ID\t  MT \t  EN \t  PH \t SUM \t AVER\n");
    for(i=0; i<n; i++)
    {
        printf("%12s\t",stuID[i]);
        for(j=0; j<M; j++)
        {
            printf("%4d\t",score[i][j]);
        }
        printf("%4d\t%5.1f\n",sum[i],aver[i]);
    }
    printf("SumofCourse \t");
    for(i=0; i<M; i++)
    {
        printf("%4d\t",lsum[i]);
    }
    printf("\n");
    printf("AverofCourse\t");
    for(i=0; i<M; i++)
    {
        printf("%4.1f\t",laver[i]);
    }
    printf("\n");
    return 0;
}
