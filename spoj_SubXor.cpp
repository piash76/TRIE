



///PROBLEM DESCRIPTION:number of subarrays whose xor is less than k


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long


using namespace std;




const int mod = 1000000007;


const int maxn =1000010;

ll tree[maxn][2],cnt[maxn],nodecnt;

void add(ll n)
{
    ll cur=0,i;
    for(i=31;i>=0;i--)
    {
        ll bit=(n>>i)&1;
        if(tree[cur][bit]==0) tree[cur][bit]=++nodecnt;
        cur=tree[cur][bit];
        cnt[cur]++;
    }
}

ll query(ll n,ll k)
{
    ll s=0,cur=0,i;

    for(i=31;i>=0;i--)
    {
        ll nbit=(n>>i)&1;
        ll kbit=(k>>i)&1;

        if(kbit)
        {
            ///if kbit is 1 then it can be bigger for nbit 1 ,and nbit 0

            ll idx=tree[cur][nbit];  ///same bit khujtasi

            s+=cnt[idx];   ///joto bar oi ith bit nbit er ith bit er same bit diye suru hyse,same bit krci cz xor e same^same=0

            if(tree[cur][!nbit]==0) break;

            ///same bit diye to ans small hocchei bt ekhn khujtasi opposite bit diye agaia samne k er choto kicu pai kina
            cur=tree[cur][!nbit];

        }
        else
        {
            ///if kbit is 0 then it can be smaller or equal for nbit 1 and nbit 0
            if(tree[cur][nbit]==0) break;
            cur=tree[cur][nbit];
        }


    }


    return s;
}


int main()
{
    ll t,i,j;
    scanf("%lld",&t);
    while(t--)
    {
        memset(tree,0,sizeof(tree));
        memset(cnt,0,sizeof(cnt));
        nodecnt=0;

        ll n,k;scanf("%lld %lld",&n,&k);
        ll sum=0,pre=0;

        add(0);

        for(i=1;i<=n;i++)
        {
            ll num;scanf("%lld",&num);
            pre^=num;
            sum+=query(pre,k);

            add(pre);
        }

        printf("%lld\n",sum);
    }




}
