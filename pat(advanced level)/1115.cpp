#include <cstdio>
#include <cstring>
using namespace std;
struct Node
{
    int v;
    Node* l;Node* r;
    Node():v(1024),l(NULL),r(NULL){}
};
const int maxn=1024;
int cnt[maxn];
void inserts(Node* root,int val)
{
    if(val<=root->v)
    {
        if(root->l==NULL)
        {
            root->l=new Node();
            root->l->v=val;
        }else inserts(root->l,val);
    }else
    {
        if(root->r==NULL)
        {
            root->r=new Node();
            root->r->v=val;
        }else inserts(root->r,val);
    }
}
void dfs(Node*root,int dep)
{
    cnt[dep]++;
    if(root->l!=NULL)dfs(root->l,dep+1);
    if(root->r!=NULL)dfs(root->r,dep+1);
}
int main()
{
    int N;scanf("%d",&N);
    Node* root=new Node();
    for(int i=0;i<N;i++)
    {
        int ai;scanf("%d",&ai);
        if(i==0)root->v=ai;else inserts(root,ai);
    }
    memset(cnt,0,sizeof(cnt));
    dfs(root,0);

    int lowest=0;
    for(int i=0;i<N;i++)if(cnt[i]!=0)lowest=i;

    int sum=cnt[lowest];
    printf("%d + ",cnt[lowest]);
    if(lowest==0)printf("0");else printf("%d",cnt[lowest-1]),sum+=cnt[lowest-1];
    printf(" = %d\n",sum);
    return 0;
}
