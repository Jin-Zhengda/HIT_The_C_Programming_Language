// 在每个字符间插入一个空格
 #include <stdio.h>
 #include <string.h>
 #define N 50

void SpaceStr1(char str[])           //以数组为函数参数
{
    int i,j,k;
    char tem[N];
    strcpy(tem,str);
    for(i=2;tem[i/2]!='\0';i=i+2)
    {
        for(j=i,k=j/2;tem[k]!='\0';j++,k++)
        {
            str[j]=tem[k];
        }
    }
    for(i=1;str[i]!='\0'||str[i-1]!='\0'||str[i+1]!='\0';i=i+2)
    {
        str[i]=' ';
    }
}

void SpaceStr2(char *pstr)           //以指针为函数参数
{
    char *pt=pstr;
    pstr++;
    for(;*pstr!='\0';pstr=pstr+2)
    {
        while(*pt!='\0')
        {
            pt++;
        }
        for(;pt>=pstr;pt--)
        {
            *(pt+1)=*pt;
        }
        *pstr=' ';
    }
}

int main(void)
{
    char str[N];
    printf("Input:");
    gets(str);
    SpaceStr1(str);
    puts(str);
    return 0;
}