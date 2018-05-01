#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow(ll a,ll n,ll mod)
{
    ll ret=1,tem=a%mod;
    while(n>0)
    {
        if(n&1)ret=ret*tem%mod;
        tem=tem*tem%mod;
        n>>=1;
    }return ret;
}
double bbp(ll n,ll add)
{
    double ret=0;
    for(ll k=0;k<=n;k++)ret+=pow(16,n-k)/(double)(8*k+add);
    for(ll k=n+1;k<=n+1000;k++)ret+=pow(16,n-k)/(double)(8*k+add);
    return ret;
}
char out(int x)
{
    if(x<10)return '0'+x;else return 'A'+x-10;
}
int main()
{
    int T;scanf("%d",&T);for(int kase=1;kase<=T;kase++)
    {
        ll n;scanf("%lld",&n);n--;
        double pos=4*bbp(n,1)-2*bbp(n,4)-bbp(n,5)-bbp(n,6);
        pos-=(int)pos;
        if(pos<0)pos+=1;
        pos*=16;
        printf("Case #%d: %lld %c\n",kase,n+1,out((int)pos));
    }
    return 0;
}
