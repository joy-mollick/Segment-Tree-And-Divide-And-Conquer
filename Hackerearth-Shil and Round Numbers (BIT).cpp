#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll BIT[1000002];

void update(int x,int val)
{
    for(int X=x;X<=n;X += X&-X)
    {
            BIT[X]+=val;
    }
}

ll query_sum_till(int x)
{
    ll sum=0;
    for(int X=x;X>0;X-=X&-X)
    {
            sum+=BIT[X];
    }
    return sum;
}

bool round(ll x)
{
    if(x<0) return false;
        string num=to_string(x);
    int len=num.length();
    if(num[len-1]==num[0])
        return true;

    return false;
}

int main()

{
   int m,t,l;
   ll r;
   scanf("%d%d",&n,&m);
   ll arr[n];
   for(int i=1;i<=n;i++){
   scanf("%lld",&arr[i]);
   if(round(arr[i])) arr[i]=1ll;
   else arr[i]=0ll;
   }
   for(int i=1;i<=n;i++)
   {
       update(i,arr[i]);
   }
   while(m--)
   {
       scanf("%d%d%lld",&t,&l,&r);
       if(t==1)
       {
           printf("%lld\n",query_sum_till(r)-query_sum_till(l-1));
       }
       else
       {
           if(arr[l])
           {
               update(l,-1);
           }
           if(round(r))
           {
               update(l,1);
           }
           arr[l]=(round(r)==true);
       }
   }

}
