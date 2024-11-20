// 逆序输出字符串
 #include <stdio.h>
 #include <string.h>
 #define N 50

void Reverse1(char *dst,char *src)           //以指针为函数参数
{
    int cnt,len;
    cnt=0;
    len=strlen(dst);
    while(*dst!='\0')
    {
        dst++;
    }
    dst--;
    do{
        *src=*dst;
        src++;
        dst--;
        cnt++;
    }while(cnt<=len);
}

void Reverse2(char dst[],char src[])             //以数组为函数参数
{
    int len,i;
    len=strlen(dst);
    for(i=len-1;i>=0;i--)
    {
        src[i]=dst[len-i-1];
    }
    src[len+1]='\0';
}

int main(void)
{
    char a[N],b[N];
    printf("Input:  ");
    gets(a);
    Reverse1(a,b);
    printf("Result: ");
    puts(b);
    return 0;
}