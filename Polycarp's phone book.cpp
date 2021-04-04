




///PROBLEM DESCRIPTION:finding unique substring for one string


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long
#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;




const int mod = 1000000007;

const int maxn =80009*10;///1e6

ll tree[maxn][12],cnt[maxn];
//ll cnt[maxn][12];

ll n,nodecnt;
string s[70009];
map<ll,string> m;


void add(string &str,ll len)
{
    ll cur=0,i;
    for(i=0;i<len;i++)
    {
        ll idx=str[i]-'0';
        if(tree[cur][idx]==0) tree[cur][idx]=++nodecnt;
        cur=tree[cur][idx];

       // cnt[cur][idx]++;
    }
    cnt[cur]++;

}

void del(string &str,ll len)
{
    ll cur=0,i;
    for(i=0;i<len;i++)
    {
         ll idx=str[i]-'0';
        cur=tree[cur][idx];

       // cnt[cur]--;
    }
    cnt[cur]--;
}

bool query(string str,ll len)
{
    bool f=true; ///ase

    ll cur=0,i;
    for(i=0;i<len;i++)
    {
         ll idx=str[i]-'0';
        if(tree[cur][idx]==0) {f=false;return f;}   ///nai
        cur=tree[cur][idx];

    }

    return cnt[cur];


}

int main()
{
    speed();

    ll i,j,k;

    ll n;cin>>n;
    for(ll idx=0;idx<n;idx++)
    {
        string st;cin>>st;
        s[idx]=st;

       // cout<<st<<endl;

        for(i=1;i<=9;i++)  ///len
        {
            for(j=0;j<9;j++)  ///index
            {
                if(j+i-1<9)
                {
                    string st1=st.substr(j,i);
                   //cout<<"ST "<<st1<<endl;
                   ll sz=st1.size();
                   add(st1,sz);
                }
            }
        }

    }

    for(ll idx=0;idx<n;idx++)
    {
        string st=s[idx];

       /// cout<<"ST "<<st<<endl;
        ///deleting own substrings contribution

        for(i=1;i<=9;i++)  ///len
        {
            for(j=0;j<9;j++)  ///index
            {
                if(j+i-1<9)
                {
                    string st1=st.substr(j,i);
                   //cout<<"ST "<<st<<endl;
                   ll sz=st1.size();
                   del(st1,sz);
                 }
            }
        }
        string ans="";

        for(i=1;i<=9;i++)  ///len
        {
            for(j=0;j<9;j++)  ///index
            {
                if(j+i-1<9)
                {
                   string st1=st.substr(j,i);
                  // cout<<"ST "<<st<<endl;
                   ll sz=st1.size();

                   if(!query(st1,sz))  ///jodi na thake
                   {
                       //cout<<"NAI "<<st1<<endl;

                   if(ans=="") ans=st1;
                   else if(ans.size()>st1.size()) ans=st1;

                   }
                 }
            }
        }



        m[idx]=ans;

       // cout<<"ANS "<<ans<<endl;

        ///abar add krtc
        for(i=1;i<=9;i++)  ///len
        {
            for(j=0;j<9;j++)  ///index
            {
                if(j+i-1<9)
                {
                    string st1=st.substr(j,i);
                   //cout<<"ST "<<st1<<endl;
                   ll sz=st1.size();
                   add(st1,sz);
                }
            }
        }



    }

    for(i=0;i<n;i++) cout<<m[i]<<endl;

    return 0;

}

/*
2
123
234

*/




