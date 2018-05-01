#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int divs=1000;
const int maxn=100;
char rs[maxn],s[maxn];
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)==2)
    {
        a+=b;
        if(a==0){printf("0");continue;}
        int posa=abs(a);
        int stacks[maxn];int stackLen=0;
        while(posa>0)
        {
            stacks[stackLen++]=posa%divs;
            posa/=divs;
        }
        if(a<0)printf("-");
//        for(int i=0;i<stackLen;i++)printf("%d ",stacks[i]);
        for(int i=stackLen-1;i>=0;i--)
        {
            if(i==stackLen-1)printf("%d",stacks[i]);
            else printf(",%03d",stacks[i]);
        }
    }
    return 0;
}

