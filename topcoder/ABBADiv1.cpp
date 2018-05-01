#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxk=1e5+10;
ll a[maxk];
int main()
{
//    freopen("0.txt","r",stdin);
    ll n;int k;while(scanf("%I64d%d",&n,&k)==2)
    {
        for(int i=1;i<=k;i++)scanf("%I64d",&a[i]);
        ll gmax;int maxid=1;
        for(int i=1;i<=k;i++)
        {
            ll tmax=n-n%a[i];
            if(i==1)gmax=tmax;else if(tmax>gmax)tmax=gmax,maxid=i;
        }printf("%d\n",maxid);
    }
    return 0;
}
