#include <iostream>
#include <string>
using namespace std;
string reverses(string x)
{
    string ans="";
    for(int i=0;i<(int)x.size();i++)ans+=x[(int)x.size()-i-1];return ans;
}
int main()
{
    string x;while(cin>>x)cout<<reverses(x)<<endl;
    return 0;
}
