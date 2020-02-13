#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod=1e9+7;

#define MAX 1000010

ll BIT[MAX];
ll A[MAX];
ll phi[MAX];
ll f[MAX];

int n;

void sieve(){
    for (ll i = 1; i < MAX; ++i)
    phi[i] = i;

    for (ll i = 2; i < MAX; ++i){

    if(phi[i] == i)
    for (ll j = i; j < MAX; j+=i)
    {
    phi[j]/= i;
    phi[j]*= (i-1);
    }

}

    for (ll i = 1; i < MAX; ++i){
    for (ll j = i; j < MAX; j+=i){
    f[j]+= i*phi[j/i];
    if(f[j] >= mod)f[j]-= mod;
    } }
}

void update(int x,ll val)
{
    for(int X=x;X<=n;X += X&-X)
    {

            BIT[X]=(BIT[X]+val);
            if(BIT[x]>=mod) BIT[x]=BIT[x]-mod;
    }
}

ll query_sum_till(int x)
{
    ll sum=0;
    for(int X=x;X>0;X-=X&-X)
    {
            sum=(sum+BIT[X]);
            if(sum>=mod) sum=sum-mod;
    }
    if(sum>=mod) sum=sum-mod;
    return sum;
}

int main()

{
    ios_base::sync_with_stdio(false);
    sieve();
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       cin>>A[i];
       update(i,f[A[i]]);
   }
   int q,x,y;
   char c;
   cin>>q;
   while(q--)
   {
       cin>>c>>x>>y;
       if(c=='C')
       {
           ll ans=query_sum_till(y)-query_sum_till(x-1);
           if(ans<0) ans+=mod;
           cout<<ans%mod<<'\n';
       }
       else
       {
           ll val=f[y]-f[A[x]];
           update(x,val);
           A[x]=y;
       }
   }
}
