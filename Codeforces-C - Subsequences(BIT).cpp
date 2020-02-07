#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod=5000000;

int n;
ll BIT[51][100001];

// BIT[l][j] number of increasing subsequence of size l with ending value of arr[j].

void update(int l,int x,ll val)
{
    for(int X=x;X<100002;X += X&-X)
    {
            BIT[l][X]=(BIT[l][X]+val);
          /*  if(BIT[l][X]>=mod)
            {
                BIT[l][X]=BIT[l][X]-mod;
            }*/
    }
}

ll query_sum(int x,int l)
{
    ll sum=0;
    for(int X=x;X>0;X-=X&-X)
    {
            sum=(sum+BIT[l][X]);
           // if(sum>=mod) sum=sum-mod;
    }
    return sum;
}


int main()

{
   //ios_base::sync_with_stdio(false);
   int K,l,r,a,p;
   scanf("%d %d",&n,&K);
   K++;
   int t=n;
   while(t--)
   {
       scanf("%d",&a);
       update(1,a,1);
       for(int k=2;k<=K;k++)
       {
           ll sbseqnce_wth_sz_k_minus_1_less_than_a=query_sum(a-1,k-1);
           update(k,a,sbseqnce_wth_sz_k_minus_1_less_than_a);
       }
   }
   ll ans=query_sum(100000,K);
   printf("%lld\n",ans);
}
