#include <bits/stdc++.h>
using namespace std;
map<string,vector<string> >info[6];
void insertStr(string infomation,string ID,int i)
{
    if(!info[i].count(infomation))info[i][infomation]=vector<string>();
    info[i][infomation].push_back(ID);
}
vector<string> split(string x)
{
    vector<string>ret;
    string tem="";
    for(int i=0;i<(int)x.size();i++)
    {
        if(x[i]==' '){ret.push_back(tem);tem="";}
        else {tem+=x[i];}
    }
    ret.push_back(tem);
    return ret;
}
int main()
{
    string delete_n;
    int N;scanf("%d",&N);getline(cin,delete_n);
    while(N--)
    {
        string ID;getline(cin,ID);
        for(int i=2;i<=6;i++)
        {
            string line;getline(cin,line);
            if(i==4)
            {
                vector<string> tem=split(line);
                for(int j=0;j<(int)tem.size();j++)
                {
                    insertStr(tem[j],ID,i-1);
                }
            }else
            {
                insertStr(line,ID,i-1);
            }
        }
    }

    int M;scanf("%d",&M);getline(cin,delete_n);
    while(M--)
    {
        string query;getline(cin,query);
        cout<<query<<endl;
        int type=query[0]-'0';query=query.substr(3);
        if(info[type].count(query))
        {
            vector<string> out=info[type][query];
            sort(out.begin(),out.end());
            for(int i=0;i<(int)out.size();i++)
            {
                cout<<out[i]<<endl;
            }
        }else
        {
            cout<<"Not Found"<<endl;
        }
    }
    return 0;
}
