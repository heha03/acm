#include <iostream>
#include <string>
using namespace std;
string reverses(string x)
{
    string ans="";
    for(int i=0;i<(int)x.size();i++)ans+=x[(int)x.size()-i-1];return ans;
}
bool isPalindromic(string x)
{
    return x==reverses(x);
}
string add(string x,string y)
{
    int len=(int)x.size();
    int res[len+10];int rlen=0;
    int pre=0;
    for(int i=(int)x.size()-1;i>=0;i--)
    {
        res[rlen++]=x[i]-'0'+y[i]-'0'+pre;
        if(res[rlen-1]>=10)pre=1,res[rlen-1]-=10;else pre=0;
    }
    if(pre>0)res[rlen++]=1;
    string ret="";
    int beg=rlen-1;
    while(beg>=0&&res[beg]==0)beg--;
    if(beg<0)return "0";
    for(int i=beg;i>=0;i--)ret+=res[i]+'0';return ret;
}
int main()
{
    string n;int k;while(cin>>n>>k)
    {
        string ans="";int i=0;
        for(;i<k;i++)
        {
            if(isPalindromic(n)){ans=n;break;}
            else n=add(n,reverses(n));
        }
        if(ans=="")cout<<n<<endl<<k<<endl;
        else cout<<ans<<endl<<i<<endl;
    }
    return 0;
}
