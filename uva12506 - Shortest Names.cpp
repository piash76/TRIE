
#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long


using namespace std;



const int mod = 1000000007;


const int maxn = 2000005;

ll tree[maxn][28],cnt[maxn];
ll nodecnt;

string s[1009];

void add(string str,ll len)
{
    ll cur=0,i;
    for(i=0;i<len;i++)
    {
        ll idx=str[i]-'a';
        if(tree[cur][idx]==-1) tree[cur][idx]=++nodecnt;
        cur=tree[cur][idx];
        cnt[cur]++;


    }
}


ll query(string str,ll len)
{
    ll cur=0,i;
    for(i=0;i<len;i++)
    {
        ll idx=str[i]-'a';
        cur=tree[cur][idx];
        if(cnt[cur]==1)
        {
            return (i+1);
        }
    }
}


int main()
{
    speed()
    ll t;cin>>t;

    while(t--)
    {
        nodecnt=0;
        memset(tree,-1,sizeof(tree));
        memset(cnt,0,sizeof(cnt));

        ll n;cin>>n;
        for(ll i=0;i<n;i++)
        {
            string st;cin>>st;
            s[i]=st;
            ll sz=st.size();

            add(st,sz);
        }

        ll ans=0;

        for(ll i=0;i<n;i++)
        {
            string st=s[i];
            ll sz=st.size();
            ll s=query(st,sz);
            ans+=s;
        }

        cout<<ans<<endl;

    }

    return 0;

}


/*

1
3
aaaaa
bbb
abababab


*/
