#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll BIT[10000002];

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

int main()

{
    int tc;
    scanf("%d",&tc);
    while(tc--){
    memset(BIT,0,sizeof(BIT));
    int m;
    scanf("%d",&m);
    int arr[m];
    int mx=-1;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&arr[i]);
        mx=max(mx,arr[i]);
    }
    n=mx;
    ll ans=0;
    for(int i=m-1;i>=0;i--)
    {
        ans+=query_sum_till(arr[i]-1);
        update(arr[i],1);
    }
    printf("%lld\n",ans);
    }
    return 0;
}
