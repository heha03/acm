#include <cstdio>
#include <cstring>
const int maxn=16;
int son[maxn][2];int fa[maxn];
///void addEdge(int i,char *s)
///{
///    if(s[0]=='-')return;
///    int sons=s[0]-'0';
///    fa[sons]=i;
///    if(son[i][1]==-1)son[i][1]=sons;
///    else son[i][0]=sons;
///}
bool firstSpace;
void inOrder(int root)
{
    if(son[root][0]!=-1)inOrder(son[root][0]);
    if(firstSpace)firstSpace=false;else printf(" ");
    printf("%d",root);
    if(son[root][1]!=-1)inOrder(son[root][1]);
}
int main()
{
//    freopen("0.txt","r",stdin);
    int n;while(scanf("%d",&n)==1)
    {
        memset(son,-1,sizeof(son));
        memset(fa,-1,sizeof(fa));
        for(int i=0;i<n;i++)
        {
            char s[3];
            for(int j=1;j>=0;j--)
            {
                scanf("%s",s);
                int sons=-1;
                if(s[0]!='-')sons=s[0]-'0';
                son[i][j]=sons;
                if(sons!=-1)fa[sons]=i;
            }
        }
        int root=0;
        while(fa[root]!=-1)root=fa[root];
        //level-order
        int nex[maxn],cnex=0,buf[maxn],cbuf=0;
        buf[cbuf++]=root;
        firstSpace=true;
        while(cbuf>0)
        {
            for(int i=0;i<cbuf;i++)
            {
                int now=buf[i];
                if(firstSpace)firstSpace=false;else printf(" ");
                printf("%d",now);
                for(int j=0;j<2;j++)if(son[now][j]!=-1)
                    nex[cnex++]=son[now][j];
            }
            memcpy(buf,nex,sizeof(nex));
            cbuf=cnex;cnex=0;
        }printf("\n");

        //in-order
        firstSpace=true;
        inOrder(root);printf("\n");
    }
    return 0;
}
