///let the head point empty is good for inserting because it makes it easy to insert before head
///4
///5 2 3 4
#include <cstdio>
struct Node
{
    int v;
    Node* nex;
    Node():nex(NULL){}
};

int main()
{
    int n;while(scanf("%d",&n)==1)
    {
        Node* head=new Node();
        for(int i=0;i<n;i++)
        {
            int vi;scanf("%d",&vi);
//            if(i==0)
//            {
//                head->nex=new Node();
//                head->nex->v=vi;
//            }
//            else
            {
                Node* th=head;
                while(th->nex!=NULL&&th->nex->v<=vi)th=th->nex;
                if(th->nex==NULL)
                {
                    th->nex=new Node();th->nex->v=vi;
                }else
                {
                    Node* add=new Node();
                    add->nex=th->nex;th->nex=add;add->v=vi;
                }
            }
        }
        Node* tem=head->nex;bool first=true;
        while(tem!=NULL)
        {
            if(first)first=false;else printf(" ");
            printf("%d",tem->v);
            tem=tem->nex;
        }printf("\n");
    }
    return 0;
}
