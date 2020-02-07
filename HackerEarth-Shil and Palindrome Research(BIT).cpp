#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll BIT[27][100005];
char s[100005];
void update(int x,ll val,char c)
{
    int l=c-'a';
    for(int X=x;X<=n;X += X&-X)
    {
            BIT[l][X]+=val;
    }
}

ll query_sum(int x,char c)
{
    ll sum=0;
    int l=c-'a';
    for(int X=x;X>0;X-=X&-X)
    {
            sum+=BIT[l][X];
    }
    return sum;
}


int main()

{
   //ios_base::sync_with_stdio(false);
   int q,t,l,r;
   char c;
   scanf("%d %d",&n,&q);
   scanf("%s",s);
   for(int i=1;i<=n;i++)
   {
       update(i,1ll,s[i-1]);
   }
   while(q--)
   {
       scanf("%d",&t);
       if(t==1)
       {
           scanf("%d %c",&l,&c);
           //cin>>l>>c;
           char prev=s[l-1];
           update(l,-1,prev);
           update(l,1,c);
           s[l-1]=c;
       }
       else{
        scanf("%d%d",&l,&r);
        //if(l>r) swap(l,r);
        //cin>>l>>r;
        int odd_tms=0;
        int even_tms=0;
        for( c='a';c<='z';c++)
        {
            ll tms=query_sum(r,c)-query_sum(l-1,c);
            if(tms%2ll==1ll) {odd_tms++;}
        }
        if(odd_tms==1||odd_tms==0) {printf("yes\n");}
        else {printf("no\n");}
       }
   }
   return 0;
}
