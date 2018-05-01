#include <cstdio>
typedef long long ll;
ll tem[100];
ll reverses(ll x)
{
    int len=0;
    while(x>0)
    {
        tem[len++]=x%10;x/=10;
    }
    ll ret=0;
    for(int i=0;i<len;i++)ret=ret*10+tem[i];return ret;
}
bool isPalindromic(ll x)
{
    int len=0;
    while(x>0)
    {
        tem[len++]=x%10;x/=10;
    }
    for(int i=0;i<len;i++)if(tem[i]!=tem[len-i-1])return false;
    return true;
}
int main()
{
    ll n;int k;while(scanf("%lld%d",&n,&k)==2)
    {
        ll ans=-1;int i=0;
        for(;i<k;i++)
        {
            if(isPalindromic(n)){ans=n;break;}
            else n+=reverses(n);
            if(n<0)n/=0;
        }
        if(ans==-1)
        {
            printf("%lld\n%d\n",n,k);
        }else printf("%lld\n%d\n",ans,i);
    }
    return 0;
}
