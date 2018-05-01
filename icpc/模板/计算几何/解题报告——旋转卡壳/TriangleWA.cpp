#include <stdio.h>
#include <algorithm>
using namespace std;
struct Point{int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
};
typedef Point Vector;
Vector operator -(Vector A,Vector B){return Vector(A.x-B.x,A.y-B.y);}
bool operator <(const Point &a,const Point &b){
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
int Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
int ConvexHull(Point *p,int n,Point *ch){
    sort(p,p+n);
    int m=0;
    for(int i=0;i<n;i++){
        while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;i--){
        while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;
        ch[m++]=p[i];
    }
    if(n>1)m--;
    return m;
}
int fabs(int x){return x>0?x:-x;}
int Area2(Point A,Point B,Point C){return fabs(Cross(B-A,C-A));}
int Rotating_calipers(Point *ch,int n){
    int q=1;int ans=0;ch[n]=ch[0];///避免特判0——n-1的那条边
    for(int p=0;p<n;p++){
        while(fabs(Cross(ch[p]-ch[q+1],ch[p+1]-ch[p]))>fabs(Cross(ch[p]-ch[q],ch[p+1]-ch[p])))///fabs(),找对锺点
            {q=(q+1)%n;printf("%d %d %d\n",p,q+1,p+1),printf("%d %d %d\n",p,q,p+1);}
        ans=max(ans,Area2(ch[p],ch[p+1],ch[q]));
    }
    return ans;
}
const int maxn= 50050;
int n;
Point plane[maxn],ch[maxn];
int main()
{
    while(scanf("%d",&n)==1&&(n!=-1)){
        for(int i=0;i<n;i++)scanf("%d%d",&plane[i].x,&plane[i].y);
        int nch=ConvexHull(plane,n,ch);
        printf("%d\n",nch);
        //for(int i=0;i<nch;i++)printf("%d %d\n",ch[i].x,ch[i].y);
        int ans=Rotating_calipers(ch,nch);
        printf("%.2f\n",(double)ans*0.5);
    }
    return 0;
}
