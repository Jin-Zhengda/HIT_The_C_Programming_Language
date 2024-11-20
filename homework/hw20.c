// 计算转置矩阵
 #include <stdio.h>
 #define N 100
 #define M 100

void Transpose1(int (*p)[N],int (*at)[M],int m,int n)    //行指针
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            *(at[j]+i)=*(p[i]+j);
        }
    }
}

void Transpose2(int *p,int *at,int m,int n)    //列指针
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            at[j*M+i]=p[i*N+j];
        }
    }
}

void Transpose3(int p[M][N],int at[N][M],int m,int n)    //数组
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            at[j][i]=p[i][j];
        }
    }
}

int main(void)
{
    int i,j,m,n;
    int a[M][N]={0};
    int b[N][M]={0};
    printf("Input the m&n:");
    scanf("%d%d",&m,&n);
    printf("Input the Matrix:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    Transpose1(a,b,m,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}