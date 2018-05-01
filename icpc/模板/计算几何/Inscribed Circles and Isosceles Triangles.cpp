#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
const double eps=1e-6;
const double pi=acos(-1.0);
int dcmp(double x){if(fabs(x)<eps)return 0;else return x<0?-1:1;}
int T;
double b,h,r,lmd,nlmd;
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%lf%lf",&b,&h);
        r=h*b/(b+2*sqrt(h*h+b*b/4));nlmd=lmd=(h-2*r)/h;
        while(dcmp(nlmd*r)>0){// while(dcmp(nlmd)>0)
            nlmd*=lmd;
        };
        printf("%13lf\n",2*pi*r*(nlmd-1)/(lmd-1));
        if(T)printf("\n");
    }
    return 0;
}
