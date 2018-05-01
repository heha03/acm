#include <bits/stdc++.h>
using namespace std;
bool app[5][10];
int maxDepth;
int c[5][10];
///at the beginning I forgot to flip the cube...
const int four[8][4]={1,2,3,4, 2,3,4,1, 3,4,1,2, 4,1,2,3, 1,4,3,2, 4,3,2,1, 3,2,1,4, 2,1,4,3};
class CubeStackingGame
{
public:
    bool dfs(int dep)
    {
        if(dep>=maxDepth)return true;
        bool con=false;///continue is vital,or it will return false and miss the remaining i
        for(int i=0;i<8;i++)
        {
//            for(int j=0;j<4;j++)printf("%d ",c[four[i][j]][dep]);
//            printf("\n");
            for(int j=0;j<4;j++)
            {
                int col=four[i][j];
                int val=c[j+1][dep];
                if(app[col][val])con=true;///return false at once? No!!!
            }
            if(con){con=false;continue;}
            for(int j=0;j<4;j++)
            {
                int col=four[i][j];
                int val=c[j+1][dep];
                app[col][val]=true;
            }
            if(dfs(dep+1))return true;
            for(int j=0;j<4;j++)
            {
                int col=four[i][j];
                int val=c[j+1][dep];
                app[col][val]=false;
            }
        }
//        printf("dep= %d is false\n",dep);
        return false;
    }
    bool able()
    {
//        printf("able is excetuating\n");
        memset(app,0,sizeof(app));
        return dfs(0);
    }
    int MaximumValue(int n,vector<int> c1,vector<int> c2,vector<int> c3,vector<int> c4)
    {
        for(int i=0;i<n;i++)c[1][i]=c1[i];
        for(int i=0;i<n;i++)c[2][i]=c2[i];
        for(int i=0;i<n;i++)c[3][i]=c3[i];
        for(int i=0;i<n;i++)c[4][i]=c4[i];

        maxDepth=2;
        while((!(maxDepth>n))&&able())maxDepth++;
        return maxDepth-1;
    }
};
int main()
{
    freopen("0.txt","r",stdin);
    CubeStackingGame c;
    int n;
    while(cin>>n)
    {vector<int> cc[4];
        for(int i=0;i<4;i++)
    {
        for(int j=0;j<n;j++)
        {
            int tc;cin>>tc;cc[i].push_back(tc);
        }
    }
    cout<<c.MaximumValue(n,cc[0],cc[1],cc[2],cc[3]);
    }

    return 0;
}
