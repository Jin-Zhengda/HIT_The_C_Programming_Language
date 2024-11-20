// 字符串数字提取
 #include <stdio.h>
 #include <ctype.h>
 #include <stdlib.h>
 #define N 100

int main(void)
{
    char str[N]={0};
    int t;
    char* pstr=str;
    printf("Input:\n");
    scanf("%s",str);
    while(*pstr!='\0')
    {
        if(isdigit(*pstr))
        {
            t=atoi(pstr);
            printf("%10d\n",t);
            while(isdigit(*pstr))
            {
                pstr++;
            }
        }
        pstr++;
    }
    return 0;
}