#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=4004;
int a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int n,ans;
void input(){
    getchar();
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
}
///总的想法是在以前hashSet的基础上，把用于保存下一个位置的next数组换成结构体，额外保存对应的key,value
///the lines below show my hashmap
const int hashsize=MAXN*MAXN/10;///size of the array（一般选除留余数的那个mod）
const int maxstate=MAXN*MAXN;///最多的情况个数
///Unions保存下一个位置的地址，关键字key和对应的value
struct Unions{
    int next1;int value;int key;
};
int head[hashsize];
Unions nexts[maxstate];
///纪录nexts数组的使用情况
int indexOfNexts;
void init_lookup_table(){indexOfNexts=1;memset(head,0,sizeof(head));memset(nexts,0,sizeof(nexts));}
//int abs(int x){if(x>0)return x;return -x;}
///hash函数
int hashs(int x){
    return abs(x)%hashsize;
}
///map.put()
void try_to_insert(int s){
    int h=hashs(s);
    int u=head[h];
    while(u){
        if(nexts[u].key==s){nexts[u].value++;return;}
        u=nexts[u].next1;
    }
    nexts[indexOfNexts].next1=head[h];
    nexts[indexOfNexts].key=s;
    head[h]=indexOfNexts;
    nexts[indexOfNexts++].value=1;
    return;
}
///map.get()
int get_value(int s){
    int h=hashs(s);
    int u=head[h];
    while(u){
        if(nexts[u].key==s){return nexts[u].value;}
        u=nexts[u].next1;
    }
    return 0;
}
///ends here
void solve(){
    init_lookup_table();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int sum=a[i]+b[j];
            try_to_insert(sum);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int sum=-(c[i]+d[j]);
            ans+=get_value(sum);
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    bool outBlank=true;
    while(T--){
        if(outBlank)outBlank=false;else printf("\n");
        ans=0;
        input();
        solve();
        printf("%d\n",ans);
    }
    return 0;
}
