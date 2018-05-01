#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
const int maxm=1e4+5;
int a[maxn];
int getn(int N)
{
    int ret=1;
    for(int i=1;i*i<=N;i++)if(N%i==0)ret=i;
    return ret;
}
const int mx[]={1,0,-1,0};
const int my[]={0,1,0,-1};
int n,m;
int getnx(int x,int dir){return x+mx[dir];}
int getny(int y,int dir){return y+my[dir];}
bool valid(int x,int y,int dir)
{
    int nx=getnx(x,dir),ny=getny(y,dir);
    return nx>=0&&ny>=0&&nx<n&&ny<m;
}
int main()
{
    int N;scanf("%d",&N);
    for(int i=0;i<N;i++)scanf("%d",&a[i]);
    sort(a,a+N,greater<int>());
    n=getn(N);m=N/n;

    int ans[m][n];
    memset(ans,-1,sizeof(ans));
    int dir=0;int id=0,x=0,y=0;
    ans[0][0]=a[id++];
    while(id<N)
    {
        while(!(valid(x,y,dir)&&ans[getny(y,dir)][getnx(x,dir)]==-1))dir=(dir+1)%4;
        x=getnx(x,dir);y=getny(y,dir);
        ans[y][x]=a[id++];
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j!=0)printf(" ");printf("%d",ans[i][j]);
        }printf("\n");
    }
    return 0;
}
