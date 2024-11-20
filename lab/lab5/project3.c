#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k;
    int a,b,c;
    int d,e,f,x,y,z;
    int flag;
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        {
            for(k=1;k<=9;k++)
            {
                if((i+j+k)%3==0)
                {
                    c=i*100+j*10+k;
                    a=c/3;
                    b=a*2;
                    d=a/100;
                    e=(a-d*100)/10;
                    f=a%10;
                    x=b/100;
                    y=(b-x*100)/10;
                    z=b%10;
                    flag=i!=k&&i!=j&&i!=d&&i!=e&&i!=f&&i!=x&&i!=y&&i!=z&&j!=k&&j!=d&&j!=e&&j!=f&&j!=x&&j!=y&&j!=z&&k!=d&&k!=e&&k!=f&&k!=x&&k!=y&&k!=z&&d!=e&&d!=f&&d!=x&&d!=y&&d!=z&&e!=f&&e!=x&&e!=y&&e!=z&&f!=x&&f!=y&&f!=z&&x!=y&&x!=z&&y!=z;
                    if(b<c&&a>=100&&flag)
                    {
                        printf("%d,%d,%d\n",a,b,c);
                    }
                }
            }
        }
    }
    return 0;
}
