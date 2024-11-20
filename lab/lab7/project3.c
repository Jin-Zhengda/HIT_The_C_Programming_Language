#include <stdio.h>
#define N 100
#define M 100

//输入：待转置矩阵，储存结果的数组，数组维度
//功能：计算转置矩阵
//输出：无
void Transpose(int p[M][N],int at[N][M],int m,int n)
{
    int i,j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            at[j][i]=p[i][j];
        }
    }
}

int main(void)
{
    int i,j,m,n;
    int a[M][N]= {0};
    int b[N][M]= {0};
    scanf("%d%d",&m,&n);
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    Transpose(a,b,m,n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
