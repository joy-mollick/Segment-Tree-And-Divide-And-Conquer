    #include <bits/stdc++.h>

    using namespace std;

    typedef  long long ll;

    #define C 300001

    struct{
        ll lazy;
        ll mn;
    }Tree[C*4];
    int MX;
    const int n=1e6+1;
    ll arr[C];

    void segment_tree(int node,int b, int e){
        if(b >= e){
            if(b == e){Tree[node].mn = arr[b];}
            return;
        }
        int mid = (b+e)/2, child1 = node*2, child2 = child1+1;
        segment_tree(child1,b, mid);
        segment_tree(child2,mid+1, e);
        Tree[node].mn = min(Tree[child1].mn,Tree[child2].mn);
    }

  void update(int node, int b, int e, int i,
                     int j, ll val)
{
    // If lazy value is non-zero for current node of segment
    // tree, then there are some pending updates. So we need
    // to make sure that the pending updates are done before
    // making new updates. Because this value may be used by
    // parent after recursive calls (See last line of this
    // function)
    if (Tree[node].lazy != 0) {
        // Make pending updates using value stored in lazy
        // nodes
        Tree[node].mn += Tree[node].lazy;

        // Checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (b != e) {
            // We can postpone updating children we don't
            // need their new values now.
            // Since we are not yet updating children of si,
            // we need to set lazy flags for the children
            Tree[node * 2 ].lazy += Tree[node].lazy;
            Tree[node * 2 + 1].lazy += Tree[node].lazy;
        }

        // Set the lazy value for current node as 0 as it
        // has been updated
        Tree[node].lazy = 0;
    }

    // Out of range
    if (b > e || b > j || e < i)
        return;

    // Current segment is fully in range
    if (b >= i && e <= j) {
        // Add the difference to current node
        Tree[node].mn += val;

        // Same logic for checking leaf node or not
        if (b != e) {
            // This is where we store values in lazy nodes,
            // rather than updating the segment tree itelf
            // Since we don't need these updated values now
            // we postpone updates by storing values in lazy[]
            Tree[node * 2 ].lazy += val;
            Tree[node * 2 + 1].lazy += val;
        }
        return;
    }

    // If not completely in range, but overlaps
    // recur for children
    int mid = (b + e) / 2;
    update(node * 2 , b, mid, i, j, val);
    update(node * 2 + 1, mid + 1, e, i, j, val);

    // And use the result of children calls
    // to update this node
    Tree[node].mn = min(Tree[node * 2 ].mn, Tree[node * 2 + 1].mn);
}

  ll query(int node,int b, int e, int i, int j)
{

    // If lazy flag is set for current node of segment tree
    // then there are some pending updates. So we need to
    // make sure that the pending updates are done before
    // processing the sub sum query
    if (Tree[node].lazy != 0) {

        // Make pending updates to this node. Note that this
        // node represents sum of elements in arr[ss..se] and
        // all these elements must be increased by lazy[si]
        Tree[node].mn += Tree[node].lazy;

        // Checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (b != e) {
            // Since we are not yet updating children os si,
            // we need to set lazy values for the children
            Tree[node * 2 ].lazy += Tree[node].lazy;
            Tree[node * 2 + 1].lazy += Tree[node].lazy;
        }

        // Unset the lazy value for current node as it has
        // been updated
        Tree[node].lazy = 0;
    }

    // Out of range
    if (b > e || b > j || e < i)
        return INT_MAX;

    // At this point, we are sure that pending lazy updates
    // are done for current node. So we can return value

    // If this segment lies in range
    if (b >= i && e <= j)
        return Tree[node].mn;

    // If a part of this segment overlaps with the given
    // range
    int mid = (b + e) / 2;
    return min(query(2 * node,b, mid, i, j),
               query(2 * node + 1,mid + 1, e, i, j));
}


    int main(){
            //ios_base::sync_with_stdio(false);
            int u,m,a,b,t;
            char c;
            ll val;
            cin>>u;
            for(int i=1;i<=u;i++) cin>>arr[i];
            cin>>m;
            segment_tree(1,1, u);
            while(m--){

                    scanf("%d%d%c",&a,&b,&c);
                    if(c==' ')
                    {
                        scanf("%lld",&val);
                        a++;
                        b++;
                        if(a<=b)
                        update(1,1,u,a,b,val);
                        else{
                            update(1,1,u,a,u,val);
                            update(1,1,u,1,b,val);
                        }
                    }

                else{
                        a++;b++;
                    if( a>b )
				printf("%lld\n",min(query(1,1,u,a,u),query(1,1,u,1,b)));
			else
				printf("%lld\n",query(1,1,u,a,b));
                }
            }
            return 0;
        }
