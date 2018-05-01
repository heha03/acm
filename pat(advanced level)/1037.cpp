#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll coupon[maxn],product[maxn];
ll couponPos[maxn],couponNeg[maxn],productPos[maxn],productNeg[maxn];
int main()
{
    int NC,NP;while(scanf("%d",&NC)==1)
    {
        for(int i=0;i<NC;i++)scanf("%lld",&coupon[i]);
        scanf("%d",&NP);
        for(int i=0;i<NP;i++)scanf("%lld",&product[i]);

        int cpos=0,cneg=0,ppos=0,pneg=0;
        for(int i=0;i<NC;i++)
        {
            if(coupon[i]>0)couponPos[cpos++]=coupon[i];
            else if(coupon[i]<0)couponNeg[cneg++]=coupon[i];
        }
        for(int i=0;i<NP;i++)
        {
            if(product[i]>0)productPos[ppos++]=product[i];
            else if(product[i]<0)productNeg[pneg++]=product[i];
        }

        sort(couponPos,couponPos+cpos,greater<ll>());
        sort(productPos,productPos+ppos,greater<ll>());
        sort(productNeg,productNeg+pneg);
        sort(couponNeg,couponNeg+cneg);

        ll ans=0;
        if(cpos>ppos)cpos=ppos;
        for(int i=0;i<cpos;i++)ans+=couponPos[i]*productPos[i];
        if(cneg>pneg)cneg=pneg;
        for(int i=0;i<cneg;i++)ans+=couponNeg[i]*productNeg[i];
        printf("%lld\n",ans);
    }
    return 0;
}
