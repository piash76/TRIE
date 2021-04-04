#include <bits/stdc++.h>

using namespace std;

const int N =1e6+100;

int n,q;
int nodecnt,tree[N][28],cnt[N];

void add(string s)
{
    int node=0;
    for(char ch:s)
    {
        int i=ch-'a';
        if(!tree[node][i])
        {
            tree[node][i]=++nodecnt;
        }
        node=tree[node][i];
        cnt[node]++;          ///counting the prefix
    }

   /* for(int i=0;i<10;i++)
    {
        for(int j=0;j<26;j++) cout<<tree[i][j]<<" ";
        cout<<endl;
    }
   // cout<<"NODE "<<node<<" cnt "<<cnt[node]<<endl;*/
}

int query(string s)
{
     int node=0;
    for(char ch:s)
    {
        int i=ch-'a';
        if(!tree[node][i])
        {
            return 0;
        }
        node=tree[node][i];

    }
    return cnt[node];
}

int main()
{
    cin>>n>>q;
    string s;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>s;
        add(s);
    }
    for(i=0;i<q;i++)
    {
        cin>>s;
        cout<<query(s)<<endl;
    }
}

