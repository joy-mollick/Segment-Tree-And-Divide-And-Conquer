#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

int mod=1000000007;
const int maxn=100010;
int n;
int BIT[maxn];
int A[maxn],B[maxn];

void update(int x,ll val)
{
    for(int X=x;X<=n;X += X&-X)
    {
            BIT[X]=(BIT[X]+val)%mod;
    }
}

int query_sum(int x)
{
    ll sum=0;
    for(int X=x;X>0;X-=X&-X)
    {
            sum=(sum+BIT[X])%mod;
    }
    return (sum);
}


int main()

{
   //ios_base::sync_with_stdio(false);
   int caso=1;
   int t;
   scanf("%d",&t);
   for(caso;caso<=t;caso++){
    memset(BIT,0,sizeof(BIT));
   scanf("%d",&n);
   int a;
   unordered_map<int,int>m;
   for(int i=1;i<=n;i++)
   {
       scanf("%d",&a);
       A[i]=a;
       B[i]=a;
   }
   sort(B+1,B+n+1);
   int cnt=1;
   for(int i=1;i<=n;i++)
   {
       if(m[B[i]]==0)
       {
           m[B[i]]=cnt++;
       }
   }
   int below_increasing_subsequence_below_position_Ai;
   for(int i=1;i<=n;i++)
   {
       below_increasing_subsequence_below_position_Ai=query_sum(m[A[i]]-1);
       update(m[A[i]],below_increasing_subsequence_below_position_Ai+1);//position i itself one element is an increasing sequence ,so extra 1 added
   }

    int ans=query_sum(n);
   printf("Case %d: %d\n",caso,ans);
   }
}
