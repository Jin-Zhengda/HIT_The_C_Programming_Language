// Pell数列
 #include <stdio.h>
 #define N 1000000
 #define M 32767
 int p[N+1]={0};

void PellMod(int k)     //关键：(a+-b)%c=(a%c+-b%c)%c和(a*b)%c=(a%c*b%c)%c
{
    int i;
    p[0]=1;
    p[1]=2;
    for(i=2;i<k;i++)
    {
        p[i]=(2*p[i-1]%M+p[i-2]%M)%M;
    }
}

int main(void)
{
    int i,n,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        PellMod(k);
        printf("%d\n",p[k-1]);
    }
    return 0;
}