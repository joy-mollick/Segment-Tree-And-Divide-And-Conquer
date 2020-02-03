#include <bits/stdc++.h>
    #define C 100001
    using namespace std;

    template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }

    //char Binary[C];
    typedef long long ll;
    ll tree[4 * C];
    ll arr[C];

void build(int node, int start, int end){
    if(start == end){
            tree[node]=arr[start];
        return;
    }
    build(node * 2, start, (start + end) / 2);
    build(node * 2 + 1, (start + end) / 2 + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    //cout<<start<<" "<<end<<"-"<<tree[node]<<endl;
}

void update(int node, int start, int end, int i, ll v){
    if(i<start||i>end) return;

    if(start==end&&start==i)
    {
        tree[node]+=v;
        //cout<<tree[node]<<endl;
        return;
    }
    int mid = (start + end) / 2;
    if(i<=mid)
    update(2 * node, start, mid, i,  v);
    else
    update(2 * node + 1, mid + 1, end, i,  v);

    tree[node] = tree[2*node] + tree[2*node + 1];
}

ll query(int node, int start, int end, int l, int r){
    if(start > r or end < l or start > end) {return 0ll;}

    if(start >= l and end <= r){
        return tree[node];}

    int mid = (start + end) / 2;
    ll p = query(2*node, start, mid, l, r);
    ll pp = query(2*node+1, mid + 1, end, l, r);
    return p + pp;
}

    int main(){
            int tc;
            int caso=1;
            scanf("%d",&tc);
            while(tc--){
            int n,c,i,j,Q;
            ll nwval;
            scanf("%d%d",&n,&Q);
            memset(tree,0,sizeof(tree));
            for(int l=1;l<=n;l++) scanf("%lld",&arr[l]);
            build(1,1, n);
            printf("Case %d:\n",caso);
            caso++;
            while(Q--){
               scanf("%d",&c);
                if(c==1){
                    scanf("%d",&j);
                    j++;
                     printf("%lld\n",arr[j]);
                    update(1,1, n, j,-arr[j]);
                    arr[j]=0ll;
                }
                else if(c==2){
                    scanf("%d%lld",&i,&nwval);
                    i++;
                    update(1,1, n, i,nwval);
                    arr[i]+=nwval;
                }
                else
                {
                    scanf("%d%d",&i,&j);
                    i++;j++;
                    ll ans=query(1,1,n,i,j);
                    printf("%lld\n",ans);
                }
            }
            }
            return 0;
        }
