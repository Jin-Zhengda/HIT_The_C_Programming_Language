// 输出杨辉三角形
 #include <stdio.h>
 #define N 10

void YHTraingle(int n)
{
    int i,j;
    int num[N][N]={0};
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j==0||i==j)
            {
                num[i][j]=1;
            }
            else if(j<i)
            {
                num[i][j]=num[i-1][j]+num[i-1][j-1];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("%d\t",num[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int n;
    printf("Input n:");
    scanf("%d",&n);
    YHTraingle(n);
    return 0;
}