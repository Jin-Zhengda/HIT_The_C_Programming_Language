#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a,b,c,d;
    do
    {
        scanf("%d/%d,%d/%d",&a,&b,&c,&d);
    }while(b<=0&&d<=0);
    if(a*d>b*c)//»¯¼òa/b>c/d(a,b,c,d>0)
    {
        printf("%d/%d > %d/%d",a,b,c,d);
    }
    else if(a*d<b*c)
    {
        printf("%d/%d < %d/%d",a,b,c,d);
    }
    else
    {
        printf("%d/%d = %d/%d",a,b,c,d);
    }
    return 0;
}
