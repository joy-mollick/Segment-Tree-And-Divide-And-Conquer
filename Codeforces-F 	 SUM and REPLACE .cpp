    #include <bits/stdc++.h>

    using namespace std;

    typedef  long long ll;

    #define C 300001

    struct{
        ll mx;
        ll sum;
        ll prop;
    }Tree[C*4];
    int MX;
    const int n=1e6+1;
    ll arr[C];
    ll D[n];

    void pre_cal()
    {
         for (int i = 1; i <= n; ++i){
            for (int j = i; j <= n; j += i)
            {
                D[j]++;
            }
         }
    }

    void segment_tree(int node,int b, int e){
        if(b >= e){
            if(b == e){Tree[node].mx=Tree[node].sum = arr[b];}
            return;
        }
        int mid = (b+e)/2, child1 = node*2, child2 = child1+1;
        segment_tree(child1,b, mid);
        segment_tree(child2,mid+1, e);
        Tree[node].sum = Tree[child1].sum + Tree[child2].sum;
        Tree[node].mx=max(Tree[child1].mx,Tree[child2].mx);
    }

    void update(int node,int b, int e, int i, int j)
    {
        if(j<b || i>e || Tree[node].mx<=2) return;// These should not be changed because divisors of 2 is and divisors of 1 is 1 same
        if(b==e)
        {
            arr[b]=D[arr[b]];// replace by number of divisors
            Tree[node].mx=Tree[node].sum=arr[b];// sum and max also 
        }
        else{ // partial overlap
        int mid = (b+e)/2, child1 = node*2, child2 = child1+1;
        update(child1,b, mid, i, j);
        update(child2,mid+1, e, i, j);
        Tree[node].sum = Tree[child1].sum + Tree[child2].sum ;
        Tree[node].mx=max(Tree[child1].mx,Tree[child2].mx);// keeping updation of max of every segment
        }
    }

   ll query(int node, int b, int e, int i, int j, ll carry)
{
    if (i > e || j < b)
        return 0ll;

    if (b >= i and e <= j)
        return Tree[node].sum + carry * (e - b + 1);

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    ll p1 = query(Left, b, mid, i, j, carry + Tree[node].prop);
    ll p2 = query(Right, mid + 1, e, i, j, carry + Tree[node].prop);

    return p1 + p2;
}

    int main(){
            ios_base::sync_with_stdio(false);
            pre_cal();
            int u,m,t,i,j;
            cin>>u>>m;
            for(int i=1;i<=u;i++) cin>>arr[i];
            segment_tree(1,1, u);
            while(m--){
               cin>>t;
                if(t==1){
                    cin>>i>>j;
                    update(1,1,u,i,j);
                }
                else{
                    cin>>i>>j;
                    cout<<query(1,1, u, i,j,0ll)<<'\n';
                }
            }
            return 0;
        }
