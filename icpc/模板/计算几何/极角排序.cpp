///��������http://www.cnblogs.com/devtang/archive/2012/02/01/2334977.html
///1�����ò������������cmp(������ʱ������)
bool cmp(const Point &a,const Point &b){
    Point origin;
    origin.x=origin.y=0;
    return Cross(b-origin,a-origin)<0;
}
///2������complex���ڽ�����
#include <complex>
#define x real()
#define y imag()
bool cmp(const Point &p1,const Point &p2){
    return arg(p1)<arg(p2);
}
///3������arctan���㼫�Ǵ�С.(range:(-180,180]
bool cmp(const Point &p1,const Point &p2){
    return atan2(p1.y,p1.x)<atan2(p2.y,p2.x);
}
///4���������޼��ϼ���
bool cmp(const Point &p1,const Point &p2){
    if(a.y==0&&b.y==0&&a.x+b.x<=0)return a.x>b.x;
    if(a.y==0&&a.x>=0&&b.y!=0)return true;
    if(b.y==0&&b.x>=0)return a.y>b.y;
    Point one;
    one.y=one.x=0;
    return Cross(a-one,b=one)>0||(Cross(a-one,b-one)==0&&a.x<b.x);
}
