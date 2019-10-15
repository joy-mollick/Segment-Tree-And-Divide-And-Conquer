#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int mx=1e5;

pair<ll,ll>tree[4*mx+4];
int arr[mx+1];

void construct_segment_tree(int root_index,int b,int e)
{
    if(b==e)// begin and end range is equal means leaf node comes place this value
    {
        tree[root_index].second=arr[b];
        return ;
    }
    int left=root_index*2;
    int right=(root_index*2)+1;
    int mid=(b+e)>>1;
    //alter=!alter;// one half will be left range and another half will be right range
    construct_segment_tree(left,b,mid);// left tree will be construct when left is root and b-mid is range
    construct_segment_tree(right,mid+1,e);

    tree[root_index].second=(tree[left].second+tree[right].second);

}

ll query(int node, int b, int e, int i, int j, ll carry)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].second + carry * (e - b + 1);

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    ll p1 = query(Left, b, mid, i, j, carry + tree[node].first);
    ll p2 = query(Right, mid + 1, e, i, j, carry + tree[node].first);

    return p1 + p2;
}
void update(int node, int b, int e, int i, int j, ll x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].second += ((e - b + 1) * x);
        tree[node].first += x;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].second = tree[Left].second + tree[Right].second + (e - b + 1) * tree[node].first;

}

int main() {
    int tc;
    int s=1;
    scanf("%d",&tc);
    while(tc--){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=4*n+1;i++)
    {
        if(i<=n)
        arr[i]=0;

        tree[i].first=0;
    }
   construct_segment_tree(1,1,n);
   //cout<<tree[1].second<<endl;
   printf("Case %d:\n",s);
   s++;
   int l,r;
   ll nwval;
   int c;
  // update(1,1,n,2,6);
   while(q--){
        scanf("%d",&c);
       if(c==0){
        scanf("%d%d%lld",&l,&r,&nwval);
        l++;r++;
        update(1,1,n,l,r,nwval);
       }
        else {
                scanf("%d%d",&l,&r);
        l++;r++;
        printf("%lld\n",query(1,1,n,l,r,0));
        }
   }
    }
   }
