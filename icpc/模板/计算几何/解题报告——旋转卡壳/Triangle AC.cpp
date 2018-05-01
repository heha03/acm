#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=50050;
struct Point{double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
Vector operator -(Vector A,Vector B){return Vector(A.x-B.x,A.y-B.y);}
bool operator <(const Point &a,const Point &b){
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
double Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
double Area2(Point A,Point B,Point C){return fabs(Cross(B-A,C-A));}
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
Point ori[maxn],ch[maxn];
int n;
int main()
{
    while(scanf("%d",&n)==1&&(n!=-1)){
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&ori[i].x,&ori[i].y);
        }
        int ncon=ConvexHull(ori,n,ch);
        ch[ncon]=ch[0];
        double ans=0;
        for(int i=0;i<ncon-1;i++){
            for(int p=i+1,q=p+1;p<ncon;p++){
                while(Area2(ch[i],ch[p],ch[q+1])>Area2(ch[i],ch[p],ch[q]))
                q=(q+1)%ncon;
            ans=max(ans,Area2(ch[i],ch[q],ch[p]));
            }
        }
        printf("%.2f\n",0.5*ans);
    }
    return 0;
}
