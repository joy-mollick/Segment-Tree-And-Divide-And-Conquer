#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

// BIT and Binary_Search 

const int mxn=150001;

ll BIT[mxn];
ll arr[mxn];

void update(int x,ll val)
{
    for(int X=x;X<=mxn;X += X&-X)
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
    for(int caso=1;caso<=tc;caso++){
    memset(BIT,0,sizeof(BIT));
    int n,q,i,k;
    char c;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++) {scanf("%lld",&arr[i]);update(i,1ll);}
    printf("Case %d:\n",caso);
    while(q--)
    {
        scanf(" %c",&c);
        if(c=='a')
        {
            scanf("%d",&i);
            update(++n,1ll);
            arr[n]=i;
        }
        else
        {
            scanf("%d",&k);
            int left=1,right=n,ans=-1;
            while(left<=right)
            {
                int mid=(left+right)>>1;
                if(query_sum_till(mid)<k){
                    left=mid+1;}
                else if(query_sum_till(mid)>=k){right=mid-1;ans=mid;}
            }
            if(ans!=-1)
            {
                    printf("%lld\n",arr[ans]);
                    update(ans,-1);
            }
            else{
                printf("none\n");
            }
        }
    }
    }

   return 0;
}
