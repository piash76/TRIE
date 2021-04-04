
#include<bits/stdc++.h>

#define ll long long


using namespace std;


const int maxn =50009;

ll tree[3*maxn][3];
ll END[3*maxn],cnt[3*maxn],len[3*maxn];
ll nodecnt,mx;

void add(char str[],ll l)
{
    ll cur=0,i;
    for(i=0;i<l;i++)
    {
        ll idx=str[i]-'0';
        if(tree[cur][idx]==-1) tree[cur][idx]=++nodecnt;
        cur=tree[cur][idx];

        cnt[cur]++;  ///occurence of prefix
        len[cur]=i+1;  ///len of prefix

        mx=max(mx,len[cur]*cnt[cur]);
    }
    END[cur]++;
}



char s[210];

int main()
{
    ll t,i,j,cas=0;
    scanf("%lld",&t);
    while(t--)
    {
        nodecnt=0;
        mx=-1;
        memset(tree,-1,sizeof(tree));
        memset(cnt,0,sizeof(cnt));
        memset(len,0,sizeof(len));
        memset(END,0,sizeof(END));


        ll n;scanf("%lld",&n);
        while(n--)
        {
            scanf("%s",s);
            ll sz=strlen(s);
            add(s,sz);
        }

        printf("%lld\n",mx);


    }


}
