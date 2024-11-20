#include <stdio.h>

int main(void)
{
    int a;
    short int b;
    char c;
    float d;
    double e;

    printf("Number:220110515\nSubject No.1-Program No.1\n");

    printf("\nPlease input int a:");
    scanf("%d",&a);
    printf("int a is %d,size of int is %I64d.\n",a,sizeof(int));

    printf("\nPlease input short int b:");
    scanf("%hd",&b);
    printf("short int b is %hd,size of short int is %I64d.\n",b,sizeof(short int));

    printf("\nPlease input char c:");
    scanf(" %c",&c);//%c前有一个空格
    printf("char c is %c,size of char is %I64d.\n",c,sizeof(char));

    printf("\nPlease input float d:");
    scanf("%f",&d);
    printf("float d is %f,size of float is %I64d.\n",d,sizeof(float));

    printf("\nPlease input double e:");
    scanf("%lf",&e);
    printf("double e is %f,size of double is %I64d.\n",e,sizeof(double));

    return 0;
}
