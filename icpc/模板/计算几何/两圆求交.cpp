#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

const LD eps = 1e-6;

int dcmp(LD x) {
    if(fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

LD sqr(LD x) { return x * x; }

struct Point
{
    LD x, y;
    Point(LD x = 0, LD y = 0):x(x), y(y) {}
    void read() { cin >> x >> y; }
};

Point operator - (const Point& A, const Point& B) {
    return Point(A.x - B.x, A.y - B.y);
}

bool operator == (const Point& A, const Point& B) {
    return dcmp(A.x - B.x) == 0 && dcmp(A.y - B.y) == 0;
}
bool operator < (const Point& A, const Point& B) {
    return dcmp(A.x - B.x) < 0 ||(dcmp(A.x - B.x) ==0&& dcmp(A.y - B.y) < 0);
}

LD Dot(const Point& A, const Point& B) {
    return A.x * B.x + A.y * B.y;
}

LD Length(const Point& A) { return sqrt(Dot(A, A)); }

struct Circle
{
    Point c;
    LD r;
    Circle() {}
    Circle(Point c, LD r):c(c), r(r) {}
};
bool OnCircle(Point&p,Circle&C){return dcmp(C.r-Length(p-C.c))==0;}
vector<Point>inter;
int getCircleIntersection(Circle C1, Circle C2) {
    LD &r1 = C1.r, &r2 = C2.r;
    LD &x1 = C1.c.x, &x2 = C2.c.x, &y1 = C1.c.y, &y2 = C2.c.y;
    LD d = Length(C1.c - C2.c);
    if(dcmp(fabs(r1-r2) - d) > 0) return -1;
    if(dcmp(r1 + r2 - d) < 0) return 0;
    LD d2 = Dot(C1.c - C2.c, C1.c - C2.c);
    LD a = r1*(x1-x2)*2, b = r1*(y1-y2)*2, c = r2*r2-r1*r1-d*d;
    LD p = a*a+b*b, q = -a*c*2, r = c*c-b*b;

    LD cosa, sina, cosb, sinb;
    //One Intersection
    if(dcmp(d - (r1 + r2)) == 0 || dcmp(d - fabs(r1 - r2)) == 0) {
        cosa = -q / p / 2;
        sina = sqrt(1 - sqr(cosa));
        Point p(x1 + C1.r * cosa, y1 + C1.r * sina);
        if(!OnCircle(p, C2)) p.y = y1 - C1.r * sina;
        inter.push_back(p);
        return 1;
    }
    //Two Intersections
    LD delta = sqrt(q * q - p * r * 4);
    cosa = (delta - q) / p / 2;
    cosb = (-delta - q) / p / 2;
    sina = sqrt(1 - sqr(cosa));
    sinb = sqrt(1 - sqr(cosb));
    Point p1(x1 + C1.r * cosa, y1 + C1.r * sina);
    Point p2(x1 + C1.r * cosb, y1 + C1.r * sinb);
    if(!OnCircle(p1, C2)) p1.y = y1 - C1.r * sina;
    if(!OnCircle(p2, C2)) p2.y = y1 - C1.r * sinb;
    if(p1 == p2)  p1.y = y1 - C1.r * sina;
    inter.push_back(p1);
    inter.push_back(p2);
    return 2;
}
//vctor<Point> inter;
int main()
{
    freopen("0.txt","r",stdin);
}
