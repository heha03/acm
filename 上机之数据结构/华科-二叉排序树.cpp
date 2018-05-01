#include <cstdio>
#include <cstring>
struct Node
{
    int v;
    Node* l;Node* r;
    Node():l(NULL),r(NULL){}
};
int inserts(Node* u,int x)
{
    if(u->v<x)
    {
        if(u->r==NULL)
        {
            u->r=new Node();
            u->r->v=x;return u->v;
        }else return inserts(u->r,x);
    }else
    {
        if(u->l==NULL)
        {
            u->l=new Node();
            u->l->v=x;return u->v;
        }else return inserts(u->l,x);
    }
}
int main()
{
    Node* root;
    int n;while(scanf("%d",&n)==1)
    {
        root=new Node();
        for(int i=0;i<n;i++)
        {
            int vi;scanf("%d",&vi);
            if(i==0){root->v=vi;printf("-1\n");}
            else
            {
                printf("%d\n",inserts(root,vi));
            }
        }
    }
    return 0;
}
