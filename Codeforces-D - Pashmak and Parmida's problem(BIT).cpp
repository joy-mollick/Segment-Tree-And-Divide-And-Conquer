#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

// BIT and greedy 
// You have to find out such (i,j) that freqof(ai) between 1 and i greater than freqof(aj) between j and n where i<j 
// So , we have to lead to array which will store the frequency of ai till i from left to right called left_freq_of_ai
// another one is right_freq_of_ai which will store the frequency of ai from n to i (from right side to left ) 
// First Initialize a BIT by 0 
// So , now traversing from right to left and before updating right_freq_of_ai[i] by 1 in BIT check how many freq_of_element_of_greater_i is less than left_freq_of_ai those will be added to our answer 

int n;
ll BIT[1000001];

void update(int x,ll val)
{
    for(int X=x;X<=1000000;X += X&-X)
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
    ll a;
    scanf("%d",&n);
    map<ll,ll>m;
    ll arr[n];
    ll left_freq_of_ai[n+1];
    ll right_freq_of_ai[n+1];
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
        m[arr[i]]++;
        left_freq_of_ai[i]=m[arr[i]];
    }
    m.clear();
    for(int i=n;i>=1;i--)
    {
        m[arr[i]]++;
        right_freq_of_ai[i]=m[arr[i]];
    }
    ll ans=0ll;
    for(int i=n;i>=1;i--)
    {
        ans=ans+query_sum_till(left_freq_of_ai[i]-1);
        update(right_freq_of_ai[i],1ll);
    }
    cout<<ans<<endl;
    return 0;
}
