#include <bits/stdc++.h>
using namespace std;
const int maxn=108;
vector<int> son[maxn];
int input()
{
    char s[10];scanf("%s",s);
    return (s[0]-'0')*10+s[1]-'0';
}
int main()
{
    int n,m;while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<maxn;i++)son[i].clear();
        while(m--)
        {
            int fa=input();
            int k;scanf("%d",&k);
            while(k--)son[fa].push_back(input());
        }

        int ans[maxn];int cAns=0;
        int use[maxn],tem[maxn],cUse=0,cTem=0;
        use[cUse++]=1;
        while(cUse>0)
        {
            int tAns=0;
            for(int i=0;i<cUse;i++)
            {
                int fa=use[i];
                for(int j=0;j<(int)son[fa].size();j++)
                    tem[cTem++]=son[fa][j];
                if((int)son[fa].size()==0)tAns++;
            }
            ans[cAns++]=tAns;

            cUse=cTem;memcpy(use,tem,sizeof(tem));
            cTem=0;
        }

        for(int i=0;i<cAns;i++)
        {
            if(i!=0)printf(" ");printf("%d",ans[i]);
        }puts("");
    }
    return 0;
}
