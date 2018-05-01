#include <cstdio>
#include <cstring>
const int maxn=108;
const int inf=1e9;
int d[maxn];
bool inset[maxn];
int w[maxn][maxn];
int min(int x,int y){if(x>y)return y;else return x;}
int main()
{
    int n,m;while(scanf("%d%d",&m,&n)==2)
    {
        if(m==0)break;
        for(int i=0;i<maxn;i++)for(int j=0;j<maxn;j++)w[i][j]=inf;
        while(m--)
        {
            int u,v,c;scanf("%d%d%d",&u,&v,&c);
            w[u][v]=w[v][u]=min(w[u][v],c);
//            printf("%d\n",w[u][v]);
        }
        int ans=0;
        for(int i=0;i<maxn;i++)d[i]=inf;
        d[1]=0;
        memset(inset,0,sizeof(inset));
        for(int cnt=0;cnt<n;cnt++)
        {
            int addIdx=-1;int minD=inf;
            for(int i=1;i<=n;i++)if(!inset[i])
            {
                if(d[i]<minD)minD=d[i],addIdx=i;
            }
//            printf("add: %d\n",addIdx);
            if(minD==inf){ans=-1;break;}
            inset[addIdx]=true;ans+=minD;
            for(int v=1;v<=n;v++)
                d[v]=min(d[v],w[addIdx][v]);
        }
        if(ans==-1)printf("?\n");else printf("%d\n",ans);
    }
    return 0;
}
