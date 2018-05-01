#include <cstdio>
#include <cstring>
const int maxn=1024;
double a[maxn];
int main()
{
    int k;
        memset(a,0,sizeof(a));
        scanf("%d",&k);
        for(int i=0;i<k;i++)
        {
            int ni;double ani;
            scanf("%d%lf",&ni,&ani);
            a[ni]=ani;
        }scanf("%d",&k);
        for(int i=0;i<k;i++)
        {
            int ni;double ani;
            scanf("%d%lf",&ni,&ani);
            a[ni]+=ani;
        }

        int cntk=0;
        for(int i=0;i<maxn;i++)if(a[i]!=0)cntk++;
        printf("%d",cntk);
        for(int i=maxn-1;i>=0;i--)if(a[i]!=0)printf(" %d %.1f",i,a[i]);
        printf("\n");
    return 0;
}
