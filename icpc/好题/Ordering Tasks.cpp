#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=108;
bool G[maxn][maxn];
int inDegree[maxn];
int main()
{
    int n,m;while(scanf("%d%d",&n,&m)==2&&n+m)
    {
        memset(inDegree,0,sizeof(inDegree));
        memset(G,0,sizeof(G));
        while(m--)
        {
            int i,j;scanf("%d%d",&i,&j);
            G[i][j]=true;inDegree[j]++;
        }

        int out[maxn];int outId=0;
        int nex[maxn];int nexId=0;

        for(int i=1;i<=n;i++)if(inDegree[i]==0)nex[nexId++]=i;

        while(outId<n)
        {
            int tnex[maxn];int tneId=0;
            for(int i=0;i<nexId;i++)
            {
                int u=nex[i];
                out[outId++]=u;
                for(int v=1;v<=n;v++)if(G[u][v])
                {
                    inDegree[v]--;
                    if(inDegree[v]==0)tnex[tneId++]=v;
                }
            }

            memcpy(nex,tnex,sizeof(tnex));nexId=tneId;
        }

        for(int i=0;i<n;i++)
        {
            if(i!=0)printf(" ");printf("%d",out[i]);
        }printf("\n");
    }
    return 0;
}
