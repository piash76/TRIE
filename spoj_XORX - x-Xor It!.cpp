

///PROBLEM DESCRIPTION:maximum,minimum xor subarray


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long


using namespace std;




const int mod = 1000000007;


const int maxn =2000010;

ll tree[2*maxn][2];
ll pref[maxn],nodecnt;

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

ll query1(ll n)  ///for max
{
    ll cur=0,i,sum=0;

    for(i=31;i>=0;i--)
    {
        ll bit=(n>>i)&1;
        if(tree[cur][!bit])
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



    ll t,i,j,cas=0;
    scanf("%lld",&t);
    while(t--)
    {
        nodecnt=0;
        memset(tree,0,sizeof(tree));

        ll n,x;scanf("%lld %lld",&n,&x);

        for(i=0;i<n;i++)
        {
            ll num;
            scanf("%lld",&num);
            if(i==0) pref[i]=num;
            else
            {
                pref[i]=pref[i-1]^num;
            }

        }


        ll mx=-1,x_or=0,ans;

        add(0);

        for(i=0;i<n;i++)
        {
            ll pre=pref[i];

            x_or=pre^x;

            ll q=query1(x_or);

            if(mx<q)
            {
                mx=max(mx,q);

                ans=q^x;
            }



            add(pref[i]);
        }


        printf("%d\n",ans);





    }

}
