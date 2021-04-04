
///PROBLEM DESCRIPTION:maximum xor of two elements in an array


///https://www.youtube.com/watch?v=jCu-Pd0IjIA&t=914s

#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long


using namespace std;



const int maxn =2000005;
ll a[maxn];

ll tree[maxn][2];
ll nodecnt;

void add(ll n)
{
    ll cur=0,i;
    for(i=31;i>=0;i--)
    {
        ll bit=(n>>i)&1;
        if(tree[cur][bit]==0) tree[cur][bit]=++nodecnt;
        cur=tree[cur][bit];

    }
}

ll query(ll num)
{
    ll sum=0,cur=0;
    for(ll i=31;i>=0;i--)
    {
        ll bit=(num>>i)&1;
        if(tree[cur][!bit])    ///opposite bit found
        {
            sum+=(1<<i);
            cur=tree[cur][!bit];

        }
        else
        {
            cur=tree[cur][bit];
        }
    }

    return sum;

}


int main()
{


    ll n;cin>>n;
    for(ll i=0;i<n;i++) { cin>>a[i];add(a[i]); }

    ll mx=-1;

    for(ll i=0;i<n;i++)
    {
       //cout<<"A{I} "<<a[i]<<endl;
        ll s=query(a[i]);

       // cout<<"S "<<s<<endl;
        mx=max(mx,s);

    }


    cout<<mx<<endl;



}
