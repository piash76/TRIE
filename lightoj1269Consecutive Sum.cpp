
///PROBLEM DESCRIPTION:maximum,minimum xor subarray


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long


using namespace std;




const int mod = 1000000007;


const int maxn =500005;

int tree[2*maxn][2];
int a[maxn],nodecnt;

void add(int n)
{
    int cur=0,i;
    for(i=31;i>=0;i--)
    {
        int bit=(n>>i)&1;
        if(tree[cur][bit]==0) tree[cur][bit]=++nodecnt;
        cur=tree[cur][bit];
    }

}

int query1(int n)  ///for max
{
    int cur=0,i,sum=0;

    for(i=31;i>=0;i--)
    {
        int bit=(n>>i)&1;
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

int query2(int n)  ///for min
{
    int cur=0,i,sum=0;

    for(i=31;i>=0;i--)
    {
        int bit=(n>>i)&1;
        if(tree[cur][bit])
        {
            cur=tree[cur][bit];
        }
        else
        {
            sum+=(1<<i);
            cur=tree[cur][!bit];
        }
    }

    return sum;
}



int main()
{



    int t,i,j,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        nodecnt=0;
        memset(tree,0,sizeof(tree));

        int n;scanf("%d",&n);

        for(i=0;i<n;i++) scanf("%d",&a[i]);


        int mx=-1,x_or=0,mn=INT_MAX;

        add(0);

        for(i=0;i<n;i++)
        {
            x_or^=a[i];

            mx=max(mx,query1(x_or));
            mn=min(mn,query2(x_or));

            add(x_or);
        }

        printf("Case %d: ",++cas);
        printf("%d %d\n",mx,mn);





    }

}
