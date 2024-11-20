// 删去某一字符串中特定的字符
 #include <stdio.h>
 #define N 50

void CutStr1(char str[],char c)           //以数组为函数参数
{
    int i,j;
    for(i=0;str[i]!='\0';i++)
    {
        while(str[i]==c)
        {
            for(j=i;str[j]!='\0';j++)
            {
                str[j]=str[j+1];
            }
        }
    }
}

void CutStr2(char *pstr,char c)           //以指针为函数参数
{
    char *pt=NULL;
    for(;*pstr!='\0';pstr++)
    {
        while(*pstr==c)
        {
            pt=pstr;
            for(;*pt!='\0';pt++)
            {
                *pt=*(pt+1);
            }
        }
    }
}

int main(void)
{
    char str[N];
    char c;
    printf("Input the str:");
    gets(str);
    printf("Input the c:");
    scanf("%c",&c);
    CutStr1(str,c);
    puts(str);
    return 0;
}