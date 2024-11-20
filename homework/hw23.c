// 模拟投票
#include <stdio.h>
#include <string.h>
#define N 10

typedef struct{
    char name[N];
    int p;
}Candidate;

int main(void)
{
    Candidate candidate[3]={{"zhang",0},{"li",0},{"wang",0}};
    int i,j;
    char name[N];
    printf("Input:\n");
    for(i=0;i<N;i++)
    {
        scanf(" %s",name);
        for(j=0;j<3;j++)
        {
            if(!strcmp(name,candidate[j].name))
            {
                candidate[j].p++;
            }
        }
    }
    printf("\n");
    for(i=0;i<3;i++)
    {
        printf("%s\t",candidate[i].name);
        printf(" %d\t\n",candidate[i].p);
    }
    return 0;
}