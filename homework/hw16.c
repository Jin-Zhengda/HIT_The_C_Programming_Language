// 按照字典顺序对国家名进行排序
 #include <stdio.h>
 #include <string.h>
 #define N 150
 #define M 10

void SortString(char str[][M],int n)
{
    int i,j;
    char temp[M];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(str[j],str[i])<0)
            {
                strcpy(temp,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],temp);
            }
        }
    }
}

int main(void)
{
    int i,n;
    char name[N][M];
    printf("How many countries?");
    scanf("%d",&n);
    getchar();                                  //读走缓冲区的回车符
    printf("Input their names:\n");
    for(i=0;i<n;i++)
    {
        gets(name[i]);
    }
    SortString(name,n);
    printf("Result:\n");
    for(i=0;i<n;i++)
    {
        puts(name[i]);
    }
    return 0;
}