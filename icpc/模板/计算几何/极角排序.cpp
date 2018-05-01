///极角排序：http://www.cnblogs.com/devtang/archive/2012/02/01/2334977.html
///1、利用叉积的正负来做cmp(按照逆时针排序)
bool cmp(const Point &a,const Point &b){
    Point origin;
    origin.x=origin.y=0;
    return Cross(b-origin,a-origin)<0;
}
///2、利用complex的内建函数
#include <complex>
#define x real()
#define y imag()
bool cmp(const Point &p1,const Point &p2){
    return arg(p1)<arg(p2);
}
///3、利用arctan计算极角大小.(range:(-180,180]
bool cmp(const Point &p1,const Point &p2){
    return atan2(p1.y,p1.x)<atan2(p2.y,p2.x);
}
///4、利用象限加上极角
bool cmp(const Point &p1,const Point &p2){
    if(a.y==0&&b.y==0&&a.x+b.x<=0)return a.x>b.x;
    if(a.y==0&&a.x>=0&&b.y!=0)return true;
    if(b.y==0&&b.x>=0)return a.y>b.y;
    Point one;
    one.y=one.x=0;
    return Cross(a-one,b=one)>0||(Cross(a-one,b-one)==0&&a.x<b.x);
}
