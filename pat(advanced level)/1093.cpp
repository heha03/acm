#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int maxn=1e5+5;
char s[maxn];
ll p[maxn],t[maxn];
inline ll add(ll x,ll y){return (x+y)%mod;}
inline ll mul(ll x,ll y){return x*y%mod;}
int main()
{
    while(scanf("%s",s)==1)
    {
        int n=strlen(s);
        p[0]=0;
        for(int i=1;i<n;i++)
        {
            p[i]=p[i-1];
            if(s[i-1]=='P')p[i]++;
        }
        t[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            t[i]=t[i+1];
            if(s[i+1]=='T')t[i]++;
        }
//        for(int i=0;i<n;i++)printf("i: %d p: %lld t: %lld\n",i,p[i],t[i]);
        ll ans=0;
        for(int i=0;i<n;i++)if(s[i]=='A')
        {
            ans=add(ans,mul(p[i],t[i]));
        }printf("%lld\n",ans);
    }
    return 0;
}
