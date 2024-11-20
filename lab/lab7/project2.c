#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define N 100

int main(void)
{
    char str[N]= {0};
    int t;
    char* pstr=str;
    printf("Input:\n");
    scanf("%s",str);
    while(*pstr!='\0')
    {
        if(isdigit(*pstr))//读到数字及将其转化为int型打印
        {
            t=atoi(pstr);
            printf("%10d\n",t);
            while(isdigit(*pstr))//打印后将指针指向下一个非数字
            {
                pstr++;
            }
        }
        pstr++;
    }
    return 0;
}
