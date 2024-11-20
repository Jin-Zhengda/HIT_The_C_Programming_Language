#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int hour,minute,h;
    double angle;
    int f=0;
    do
    {
        printf("Please input time\n");
        scanf("%dh%dm",&hour,&minute);
        if(hour>=0&&hour<=12&&minute>=0&&minute<60)
        {
            f=1;
        }
        else
        {
            while(getchar()!='\n');
        }
    }//判断输入是否合法
    while(!f);
    if(hour==12)
    {
        h=0;
    }
    else
    {
        h=hour;
    }
    angle=(double)fabs(h*30+0.5*minute-minute*6);//计算时针与分针夹角

    if(angle>180)//使结果范围为0~180度
    {
        angle=360-angle;
    }
    if(minute==0)//对输出0的个数进行控制
    {
        printf("At %d:00 the angle is %.1f degrees.\n",hour,angle);
    }
    else if(minute<10)
    {
        printf("At %d:0%d the angle is %.1f degrees.\n",hour,minute,angle);
    }
    else
    {
        printf("At %d:%d the angle is %.1f degrees.\n",hour,minute,angle);
    }
    return 0;
}
