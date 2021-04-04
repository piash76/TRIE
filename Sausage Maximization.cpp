





///PROBLEM DESCRIPTION:


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long
#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;




const int mod = 1000000007;


const int maxn = 2000005;

ll tree[2*maxn][2],nodecnt;

ll suf[maxn],a[maxn];

void add(ll n)
{
    ll cur=0,i;
    for(i=40;i>=0;i--)
    {
        ll bit=(n>>i)&1;
        if(tree[cur][bit]==0) tree[cur][bit]=++nodecnt;
        cur=tree[cur][bit];
    }
}


ll query(ll n)
{
    ll sum=0,i,cur=0;
    for(i=40;i>=0;i--)
    {
        ll bit=(n>>i)&1;
        if(tree[cur][!bit])
        {
            sum+=(1ll<<i);
            cur=tree[cur][!bit];
        }
        else cur=tree[cur][bit];
    }


    return sum;
}


int main()
{
    ll i,j;

    ll n;scanf("%lld",&n);

    suf[0]=0;
    ll pref=0;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        pref^=a[i];
    }

    ll idx=1;

    for(i=n;i>=1;i--)
    {
        if(i==n) suf[idx++]=a[i];
        else
        {
            ll x=suf[idx-1]^a[i];
           // cout<<x<<endl;

            suf[idx++]=x;

        }
    }
    //cout<<pref<<endl;

   /* for(i=0;i<=n;i++) {
            cout<<suf[i]<<" ";
            ll x1=pref^suf[i];
            cout<<x1<<endl;
    }*/
   // cout<<endl;

   ll mx=-1;
   for(i=0;i<=n;i++)
   {
       add(suf[i]);

       ll pre=pref^suf[i];

       //cout<<"PREF "<<pref<<endl;

       ll s=query(pre);

       mx=max(mx,s);


   }

   cout<<mx<<endl;

   return 0;



}

/*

6
13 21 3 61 1 2


*/
