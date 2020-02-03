#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll BIT[100005];// Binary Indexed Tree need one space exra for 0 .
ll arr[100005];

int n;

int getSum( int index)
{
    ll sum = 0;
    while (index>0)
    {
        sum += BIT[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT( int index, ll val)
{
    while (index <= n)
    {
    BIT[index] += val;
    index += index & (-index);
    }
}



void constructBITree( int n)
{

    for (int i=1; i<=n; i++)
        updateBIT( i, arr[i]);

}

int main()
{
    int tc;
    scanf("%d",&tc);
    int caso=1;
    for(caso=1;caso<=tc;caso++)
    {
        int m,indx,l,r,t;
        ll v;
        memset(BIT,0,sizeof(BIT));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
        constructBITree(n);
        printf("Case %d:\n",caso);
        while(m--)
        {
            scanf("%d",&t);
            if(t==1)
            {
                scanf("%d",&indx);
                indx++;
                printf("%lld\n",arr[indx]);
                updateBIT(indx,-arr[indx]);
                arr[indx]=0ll;
            }
            else if(t==2)
            {
                scanf("%d%lld",&indx,&v);
                indx++;
                arr[indx]+=v;
                updateBIT(indx,v);
            }
            else
            {
                scanf("%d%d",&l,&r);
                ll lft,right;
                l++;
                r++;
                lft=getSum(l-1);
                 right=getSum(r);
                printf("%lld\n",right-lft);
            }
        }
    }
    return 0;
}
