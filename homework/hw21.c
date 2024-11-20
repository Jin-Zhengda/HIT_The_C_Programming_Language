// 动态数组输出最高分
 #include <stdio.h>
 #include <stdlib.h>

void MaxScore(int *p,int m,int n)
{
    int max,i,j;
    printf("Input the score:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&p[i*n+j]);
        }
    }
    max=p[0];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(p[i*n+j]>max)
            {
                max=p[i*n+j];
            }
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(p[i*n+j]==max)
            {
                printf("%d班第%d个学生,分数为:%d\n",i+1,j+1,max);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int m,n;
    int *p=NULL;
    printf("Input m&n:");
    scanf("%d%d",&m,&n);
    p=(int *)calloc(m*n,sizeof(int));
    if(p==NULL)
    {
        exit(1);
    }
    else
    {
        MaxScore(p,m,n);
    }
    free(p);
    return 0;
}