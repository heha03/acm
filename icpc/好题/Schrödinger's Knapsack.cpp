#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2048;
ll d[maxn][maxn],sum1[maxn],sum2[maxn],s1[maxn],s2[maxn];
ll k1,k2,c;
int n,m;
int main()
{
//    freopen("0.txt","r",stdin);
    int T;scanf("%d",&T);while(T--)
    {
        scanf("%lld%lld%lld%d%d",&k1,&k2,&c,&n,&m);
        for(int i=1;i<=n;i++)scanf("%lld",&s1[i]);
        for(int i=1;i<=m;i++)scanf("%lld",&s2[i]);

        sort(s1+1,s1+1+n);sort(s2+1,s2+1+m);
        sum1[0]=0;for(int i=1;i<=n;i++)sum1[i]=sum1[i-1]+s1[i];
        sum2[0]=0;for(int i=1;i<=m;i++)sum2[i]=sum2[i-1]+s2[i];

        for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)d[i][j]=0;
        for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)
        {
            ll lefts=c-sum1[i]-sum2[j];
            if(i>0)d[i][j]=max(d[i][j],d[i-1][j]+k1*lefts);
            if(j>0)d[i][j]=max(d[i][j],d[i][j-1]+k2*lefts);
        }
        ll ans=0;
        for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)
            ans=max(ans,d[i][j]);
        printf("%lld\n",ans);

//        for(int i=1;i<=n;i++)
//        {
//            for(int j=1;j<=m;j++)printf("%lld ",d[i][j]);
//            printf("\n");
//        }puts("");
    }
    return 0;
}
