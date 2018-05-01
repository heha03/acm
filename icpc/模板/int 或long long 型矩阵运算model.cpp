struct Mat{int mat[maxn][maxn];};
Mat operator *(Mat a,Mat b){///行列数相同的方阵间矩阵相乘
    Mat c;
    memset(c.mat,0,sizeof(c.mat));
    int i,j,k;
    for(k=0;k<n;k++){///n（下同）是方阵的行数（或列数）
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                c.mat[i][j]=c.mat[i][j]+a.mat[i][k]*b.mat[k][j];
            }
        }
    }
    return c;
}
Mat operator ^(Mat a,int k){
    Mat c;
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            c.mat[i][j]=(i==j);
    for(;k;k>>=1){
        if(k&1)c=c*a;
        a=a*a;
    }
    return c;
}
Mat operator +(Mat a,Mat b){
    Mat c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c.mat[i][j]=a.mat[i][j]+b.mat[i][j];
        }
    }
    return c;
}
Mat A;
Mat sum(int k){
    if(k==1)return A;
    if(k==2)return A+A*A;
    else{
        if(k&1){
            Mat temp=sum(k/2),tmpe=A^(k/2+1);
            return temp+tmpe+tmpe*temp;///sum(k/2)+A^(k/2+1)+A^(k/2+1)*sum(k/2)
        }
        else{
            Mat temp=sum(k/2);
            return temp+(A^(k/2))*temp;///sum(k/2)+A^(k/2)*sum(k/2)
        }
    }
}///return A+A^2+A^3+...+A^k
