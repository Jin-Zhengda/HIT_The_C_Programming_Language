// 输出输入字符串中单词个数
 #include <stdio.h>
 #include <ctype.h>
 #define N 50
 int main(void)
 {
     char str[N];
     int i,cnt;
     cnt=0;
     printf("Input:");
     gets(str);
     for(i=0;str[i]!='\0';i++)
     {
         if(isspace(str[i]))
         {
             if(isalpha(str[i+1]))
             {
                 cnt++;
             }
         }
     }
     printf("result:%d",cnt);
     return 0;
 }