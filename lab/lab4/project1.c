#include <stdio.h>
#include <stdlib.h>

//输入：数列下标k
//函数功能：递归法计算Pell数列第k项
//输出：Pell数列第k项
int Pell(int k)
{
    if(k==1)
    {
        return 1;
    }
    else if(k==2)
    {
        return 2;
    }
    else
    {
        return Pell(k-1)*2+Pell(k-2);
    }
}

int main(void)
{
    int n,k,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        printf("%d\n",Pell(k)%32767);
    }
    return 0;
}
