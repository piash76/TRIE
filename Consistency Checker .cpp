


#include<bits/stdc++.h>



#define ll long long


using namespace std;


const int maxn = 10009; ///2e5  5e4+20

ll nodecnt;
ll tree[12*maxn][12];
ll END[12*maxn];


bool f;

void add(char str[],ll len)
{
    ll cur=0;
    for(ll i=0;i<len;i++)
    {
        ll idx=str[i]-'0';
        if(tree[cur][idx]==-1) tree[cur][idx]=++nodecnt;
        cur=tree[cur][idx];


    }
    END[cur]++;
}

bool query(char str[],ll len)
{
    bool flag=true;  ///ase
    ll cur=0;
    for(ll i=0;i<len;i++)
    {
        ll idx=str[i]-'0';
        if(END[cur]) {flag=true;break;}   ///
        if(tree[cur][idx]==-1) {flag=false;break;}

        cur=tree[cur][idx];

    }
    return flag;
}

///123,1234|| 1234,123

char s[maxn];

int main()
{

    ll t,i,j,cas=0;
    scanf("%lld",&t);
    while(t--)
    {
        nodecnt=0;
        f=false;
        memset(tree,-1,sizeof(tree));
        memset(END,0,sizeof(END));

        ll n;scanf("%lld",&n);
        while(n--)
        {
            scanf("%s",s);
            ll sz=strlen(s);

            ///there is are strings which are prefix of other strings
            if(query(s,sz)) {f=true;
           //cout<<"S "<<s<<endl;

            }

            add(s,sz);


        }

        printf("Case %lld: ",++cas);
        if(!f) printf("YES\n");
        else printf("NO\n");

    }


}

