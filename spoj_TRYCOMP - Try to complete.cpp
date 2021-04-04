///PROBLEM DESCRIPTION:auto complete for any given words finding the words(matching prefix with given word) with most occuring with lexicographically


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long


using namespace std;

const int mod = 1000000007;


const int maxn =5000005;
ll tree[maxn][28],cnt[maxn],nodecnt;
string str[maxn];

map<string,ll>m;

void add(string &s,ll occu)
{
    ll cur=0,i,len=s.size();
    for(i=0;i<len;i++)
    {
        ll idx=s[i]-'a';
        if(tree[cur][idx]==0) tree[cur][idx]=++nodecnt;
        cur=tree[cur][idx];

        if(cnt[cur]<occu)   ///for the prefix of string
        {
            cnt[cur]=occu;
            str[cur]=s;
        }


    }
}


void query(string &s,ll len)
{
    ll cur=0,i;
    for(i=0;i<len;i++)
    {
        ll idx=s[i]-'a';
        if(tree[cur][idx]==0) {cout<<-1<<endl;return;}
        cur=tree[cur][idx];
    }

    cout<<str[cur]<<" "<<cnt[cur]<<endl;
}


int main()
{
    speed()

    ll t,i,j;
    ll n;cin>>n;
    while(n--)
    {
        string st;cin>>st;
        m[st]++;
    }

    for(auto x:m)
    {
        string st=x.first;
        ll num=x.second;
        add(st,num);
    }

    ll q;cin>>q;
    while(q--)
    {
        string s;cin>>s;
        ll sz=s.size();
        query(s,sz);
    }

}
