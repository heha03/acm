#include <cstdio>
#include <cstring>
const int maxn=1e4+5;
bool appear[maxn];
int mid[maxn],m[maxn],p[maxn];
struct Node
{
    int v;
    Node* l;Node* r;
    Node(int val):v(val),l(NULL),r(NULL){}
};
Node* build(int pl,int pr,int ml,int mr)
{
    if(pl>pr)return NULL;
    Node*root=new Node(p[pr]);
    int middle=mid[p[pr]];
    root->l=build(pl,pl+middle-ml-1,ml,middle-1);
    root->r=build(pl+middle-ml,pr-1,middle+1,mr);
//    printf("root: %d ",root->v);
//    if(root->l!=NULL)printf("lv: %d ",root->l->v);
//    if(root->r!=NULL)printf("rv: %d ",root->r->v);
//    printf("\n");
    return root;
}
int temSum,globalMin,minId;
void dfs(Node* root)
{
    temSum+=root->v;
    if(root->l==NULL&&root->r==NULL)
    {
        if(globalMin>temSum||(globalMin==temSum&&minId>root->v))
        {
            minId=root->v;globalMin=temSum;
        }
//        globalMin=min(globalMin,temSum);
    }else
    {
        if(root->l!=NULL)dfs(root->l);
        if(root->r!=NULL)dfs(root->r);
    }temSum-=root->v;
}
int main()
{
//    freopen("0.txt","r",stdin);
    int n=0;int in;while(scanf("%d",&in)==1)
    {
        if(appear[in])
        {
            for(int i=0;i<n;i++)
            {
                int tin;
                if(i==0)tin=in;else scanf("%d",&tin);
                p[i]=tin;
            }
            Node*root=build(0,n-1,0,n-1);
            temSum=0;globalMin=1e9;minId=1e9;
            dfs(root);
            printf("%d\n",minId);


            memset(appear,0,sizeof(appear));n=0;
        }else
        {
            m[n++]=in;mid[in]=n-1;appear[in]=true;
        }
    }
    return 0;
}
