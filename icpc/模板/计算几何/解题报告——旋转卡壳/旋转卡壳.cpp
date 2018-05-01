double dis(Point A,Point B){return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);}
double Rotating_calipers(Point *ch,int n){
    int q=1;double ans=0;ch[n]=ch[0];///避免特判0——n-1的那条边
    for(int p=0;p<n;p++){
        while(Cross(ch[p]-ch[q+1],ch[p+1]-ch[p])>Cross(ch[p]-ch[q],ch[p+1]-ch[p]))///fabs(),找对锺点
            q=(q+1)%n;
        ans=max(ans,max(dis(ch[p]-ch[q]),dis(ch[p+1]-ch[q+1])));///更新长度
    }
    return ans;///返回凸包直径的平方
}
