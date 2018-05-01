//Mergeable Stack zoj4016
#include <bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
list<int> S[maxn];
void put_list(list<int> l)
{
    for(list<int>::iterator it=l.begin();it!=l.end();it++)
        cout<<*it<<" ";
    cout<<endl;
}
int main()
{
//    freopen("0.txt","r",stdin);
    int T;scanf("%d",&T);while(T--)
    {
        int n,q;scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)S[i].clear();
        while(q--)
        {
            int op,s;scanf("%d%d",&op,&s);
            if(op==2)
            {
                if(S[s].empty())printf("EMPTY\n");
                else{printf("%d\n",S[s].back());S[s].pop_back();}
            }else if(op==1)
            {
                int v;scanf("%d",&v);
                S[s].push_back(v);
            }else
            {
                int t;scanf("%d",&t);
                S[s].splice(S[s].end(),S[t]);
//                put_list(S[s]);
            }
        }
    }
    return 0;
}
