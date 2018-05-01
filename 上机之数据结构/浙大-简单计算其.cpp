#include <bits/stdc++.h>
using namespace std;
const int ISNUM=1;
const int ISOPE=0;
const int maxc=256;
char s[maxc];
int pos,len;
int readNum()
{
    while(s[pos]==' ')pos++;
    int ret=0;
    while(s[pos]!=' '&&pos<len){ret=ret*10+s[pos]-'0';pos++;}
//    printf("readnum: %d\n",ret);
    return ret;
}
char readOpe()
{
    while(s[pos]==' ')pos++;
    return s[pos++];
}
void cal(stack<double>&num,stack<char>&ope)
{
    double y=num.top();num.pop();
    double x=num.top();num.pop();
    char operators=ope.top();ope.pop();
    if(operators=='+')num.push(x+y);
    if(operators=='-')num.push(x-y);
    if(operators=='*')num.push(x*y);
    if(operators=='/')num.push(x/y);
//    printf("x %c y \n",x,operators,y);
}
inline bool isMulDiv(char x){return x=='*'||x=='/';}
inline bool isAddSub(char x){return x=='+'||x=='-';}
int main()
{
    while(fgets(s,maxc,stdin))
    {
        if(strlen(s)==2&&s[0]=='0')break;

        stack<double> num;stack<char> ope;
        pos=0;len=strlen(s)-1;
        int tar=ISNUM;
        while(pos<len)
        {
            if(tar==ISNUM)num.push(readNum());
            else
            {
                char tope=readOpe();
                while(!ope.empty()&&(isMulDiv(ope.top())||(isAddSub(tope)&&isAddSub(ope.top()))))
//                while(((tope=='*'||tope=='/')&&(ope.empty()&&(ope.top()=='+'||ope.top()=='-')))
                {
                    //calculate...
                    cal(num,ope);
                }
                ope.push(tope);
            }
            tar^=1;
        }

        while(!ope.empty())
        {
            //calculate
            cal(num,ope);
        }
        printf("%.2f\n",num.top());
    }
    return 0;
}
