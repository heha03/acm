#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn=100;
char rs[maxn],s[maxn];
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)==2)
    {
        a+=b;
        int len=0;
        int posa=abs(a);
        while(posa>0)
        {
            rs[len++]=posa%10+'0';posa/=10;
        }
        for(int i=0;i<len;i++)s[i]=rs[len-i-1];s[len]=0;
        memcpy(rs,s,sizeof(s));
        int rslen=len;len=0;
        rs[0]=s[len++];
        for(int i=1;i<rslen;i++)
        {
            if(i%3==0)s[len++]=',';
            s[len++]=rs[i];
        }
        if(a<0)printf("-");
        s[len++]=0;printf("%s",s);
    }
    return 0;
}
