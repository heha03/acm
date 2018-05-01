#include <cstdio>
int main()
{
    int elePos=0;int n;
    while(scanf("%d",&n)==1)
    {
        elePos=0;int ans=0;
        for(int i=0;i<n;i++)
        {
            int fi;scanf("%d",&fi);
            if(fi>elePos)ans+=6*(fi-elePos);
            else ans+=4*(elePos-fi);
            elePos=fi;
            ans+=5;
        }printf("%d\n",ans);
    }
}
