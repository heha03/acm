#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn];
int main()
{
    int n;while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        memcpy(b,a,sizeof(a));
        sort(b,b+n);
        int csame=0;int maxOne=0;
        int same[maxn];
        for(int i=0;i<n;i++)
        {
            maxOne=max(maxOne,a[i]);
            if(a[i]==b[i]&&a[i]==maxOne)same[csame++]=a[i];
        }

        printf("%d\n",csame);
        for(int i=0;i<csame;i++)
        {
            if(i!=0)printf(" ");printf("%d",same[i]);
        }printf("\n");
    }
    return 0;
}
