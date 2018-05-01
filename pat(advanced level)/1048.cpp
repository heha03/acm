#include <cstdio>
using namespace std;
const int maxv=1024;
int cnt[maxv];
int main()
{
    int n,m;while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<=m;i++)cnt[i]=0;
        while(n--)
        {
            int tv;scanf("%d",&tv);cnt[tv]++;
        }
        int ans=-1;
        for(int i=1;i<=m;i++)
        {
            if(cnt[i]>0)
            {
                cnt[i]--;
                if(cnt[m-i]>0){ans=i;break;}
            }
        }
        if(ans==-1)printf("No Solution\n");
        else printf("%d %d\n",ans,m-ans);
    }
    return 0;
}
