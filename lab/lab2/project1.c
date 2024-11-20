#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    float a,b,c,p,s;
    const float E=1e-2;//用于进行浮点数判等
    int f=1;//标志变量，置为0时表明并非一般三角形

    scanf("%f %f %f",&a,&b,&c);

    if(a+b>c&&b+c>a&&a+c>b)
    {
        if(fabs(a-b)<=E&&fabs(a-c)<=E&&fabs(a-c)<=E)
        {
            printf("等边");
            f=0;
        }
        else
        {
            if(fabs(a-b)<=E||fabs(a-c)<=E||fabs(b-c)<=E)
            {
                printf("等腰");
                f=0;
            }
            if(fabs(a*a+b*b-c*c)<=E||fabs(a*a+c*c-b*b)<=E||fabs(b*b+c*c-a*a)<=E)
            {
                printf("直角");
                f=0;
            }
        }
        if(f)
        {
            printf("一般");
        }
        p=(a+b+c)/2;
        s=sqrt(p*(p-a)*(p-b)*(p-c));
        printf("三角形\nS=%.2f\n",s);

    }
    else
    {
        printf("不是三角形\n");
    }
    return 0;
}
