#include <cstdio>
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
const char out[]="WAKJSD";
const int outWhite=0;
const int maxh=256;
const int maxw=64*8;
int idx[maxh][maxw];
bool black[maxh][maxw];
int H,W;
const int mx[]={0,0,-1,1};
const int my[]={1,-1,0,0};
bool valid(int nx,int ny){return nx>=0&&ny>=0&&nx<H&&ny<W*8;}
set<int> cntWhite;
int cntId;
void dfsWhite(int x,int y)
{
//    for(int k=0;k<4;k++)
    for(int dx=-1;dx<=1;dx++)for(int dy=-1;dy<=1;dy++)
    {
//        int dx=mx[k],dy=my[k];
        int nx=x+dx;int ny=y+dy;
        if(valid(nx,ny)&&!black[nx][ny]&&idx[nx][ny]==0)
        {
            idx[nx][ny]=idx[x][y];dfsWhite(nx,ny);
        }
    }
}
void dfsBlack(int x,int y)
{
    int nx,ny;
    for(int k=0;k<4;k++)
    {
        nx=x+mx[k];ny=y+my[k];
        if(valid(nx,ny))
        {
            if(black[nx][ny]&&idx[nx][ny]==0){idx[nx][ny]=idx[x][y];dfsBlack(nx,ny);}
            if(!black[nx][ny])
            {
                if(idx[nx][ny]==0){idx[nx][ny]=cntId++;dfsWhite(nx,ny);}
                cntWhite.insert(idx[nx][ny]);
            }
        }
    }
}
int main()
{
//    freopen("0.txt","r",stdin);
    int kase=1;
    while(scanf("%d%d",&H,&W)==2&&H+W)
    {
        memset(black,0,sizeof(black));
        char s[64];
        for(int i=0;i<H;i++)
        {
            scanf("%s",s);
            int tw=0;
            for(int j=0;j<W*2;j++)
            {
                int sj;
                if(isdigit(s[j]))sj=s[j]-'0';else sj=s[j]-'a'+10;
                if(sj>=8)black[i][tw]=true,sj-=8;tw++;
                if(sj>=4)black[i][tw]=true,sj-=4;tw++;
                if(sj>=2)black[i][tw]=true,sj-=2;tw++;
                if(sj>=1)black[i][tw]=true,sj-=1;tw++;
            }
        }

        memset(idx,0,sizeof(idx));
        cntId=1;
        idx[0][0]=cntId++;dfsWhite(0,0);
        int ans[10];memset(ans,0,sizeof(ans));
        for(int i=0;i<H;i++)for(int j=0;j<8*W;j++)if(black[i][j]&&idx[i][j]==0)
        {
            cntWhite.clear();
            idx[i][j]=cntId++;dfsBlack(i,j);
            if(cntWhite.count(1))cntWhite.erase(1);
            ans[(int)cntWhite.size()]++;
        }

        string outs="";
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<ans[i];j++)outs+=out[i];
        }
        sort(outs.begin(),outs.end());
        printf("Case %d: ",kase++);
        cout<<outs<<endl;
    }
    return 0;
}
