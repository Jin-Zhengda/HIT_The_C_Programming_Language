// 计算定积分
 #include <stdio.h>
 #define EPS 1e-3

float y(float x)
{
    return x*x+1;
}

float Integeral(float(*f)(float),float a,float b)
{
    float in;
    in=0;
    while (a<b)
    {
        in=in+((*f)(a)+(*f)(a+EPS))*EPS/2;
        a=a+EPS;
    }
    return in;
}

int main(void)
{
    float a,b,in;
    printf("Input a & b:");
    scanf("%f%f",&a,&b);
    in=Integeral(y,a,b);
    printf("Result:%f",in);
    return 0;
}