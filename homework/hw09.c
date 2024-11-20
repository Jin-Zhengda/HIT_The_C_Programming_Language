// 交换数组中的最大值和最小值
 #include <stdio.h>

void Swap(int *x,int *y)
{
    int t;
    t=*x;
    *x=*y;
    *y=t;
}

void Select(int a[],int *x,int *y)
{
    int max,min,i;
    max=a[0];
    min=a[0];
    for(i=0;i<10;i++)
    {
        if(a[i]>=max)
        {
            max=a[i];
            *x=i;
        }
        if(a[i]<=min)
        {
            min=a[i];
            *y=i;
        }
    }
}

int main(void)
{
    int a[10]={0};
    int i,m,n;
    int *x=&m;
    int *y=&n;
    printf("Input:\n");
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    Select(a,x,y);
    Swap(&a[m],&a[n]);
    for(i=0;i<10;i++)
    {
        printf("%-3d",a[i]);
    }
    return 0;
}