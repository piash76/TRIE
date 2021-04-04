




///PROBLEM DESCRIPTION:shortest unique prefix for given words



#include<iostream>
#include<vector>
#include<string>
#include <cstring>

#define ll long long


using namespace std;


const int maxn = 100005;
int tree[maxn][28],cnt[maxn],nodecnt;

string s[1009];

void add(string str,int len)
{
    int cur=0,i;
    for(i=0;i<len;i++)
    {
        int idx=str[i]-'a';
        if(tree[cur][idx]==-1) tree[cur][idx]=++nodecnt;
        cur=tree[cur][idx];
        cnt[cur]++;
    }
}

string query(string str,int len)
{
    int cur=0,i;
    string ans="";

    for(i=0;i<len;i++)
    {
        int idx=str[i]-'a';
        cur=tree[cur][idx];
        ans+=str[i];
        if(cnt[cur]==1) {break;}
    }

    return ans;
}


int main()
{
    memset(tree,-1,sizeof(tree));

    int i,j,idx=0;
    string st;

    //for(i=0;i<12;i++)
    while(cin>>st)
    {
       // cin>>st;
        s[idx++]=st;
        int sz=st.size();
        add(st,sz);
    }

    for(i=0;i<idx;i++)
    {
        string st=s[i];
        int sz=st.size();

        string ans=query(st,sz);

        cout<<st<<" "<<ans<<endl;
    }



}


