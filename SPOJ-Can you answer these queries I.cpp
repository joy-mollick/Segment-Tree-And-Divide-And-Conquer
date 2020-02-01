    #include <bits/stdc++.h>

    using namespace std;

    typedef  long long ll;

    #define C 50001
    #define inf 1e14

    struct Node{
        ll maxPrefixSum;
        ll maxSuffixSum;
        ll totalSum;
        ll maxSubarraySum;
        ll lazy;
        Node()
        {
            maxPrefixSum = maxSuffixSum = maxSubarraySum = -inf;
            totalSum = -inf;
        }
    };

    Node mege(Node leftChild, Node rightChild)
{
    Node parentNode;
    parentNode.maxPrefixSum = max(leftChild.maxPrefixSum,
                                  leftChild.totalSum +
                                  rightChild.maxPrefixSum);

    parentNode.maxSuffixSum = max(rightChild.maxSuffixSum,
                                  rightChild.totalSum +
                                  leftChild.maxSuffixSum);

    parentNode.totalSum = leftChild.totalSum +
                          rightChild.totalSum;

    parentNode.maxSubarraySum = max(leftChild.maxSubarraySum,
                                    max(
                                     rightChild.maxSubarraySum,
                                     leftChild.maxSuffixSum +
                                     rightChild.maxPrefixSum));

    return parentNode;
}

    Node Tree[4*C];

    int MX;
    const int n=1e6+1;
    ll arr[C];


    void segment_tree(int node,int b, int e){
        if(b >= e){
            if(b == e){Tree[node].totalSum=Tree[node].maxSubarraySum=Tree[node].maxSuffixSum=Tree[node].maxPrefixSum=(arr[b]);}
            return;
        }
        int mid = (b+e)/2, child1 = node*2, child2 = child1+1;
        segment_tree(child1,b, mid);
        segment_tree(child2,mid+1, e);
        Tree[node] = mege(Tree[child1],Tree[child2]);
    }

    /*
  void update(int node, int b, int e, int i,
                     int j, ll val)
{

    
    if (b > e || b > j || e < i)
        return;

    if (b >= i && e <= j) {
        Tree[node].mn += val;
        if (b != e) {
            Tree[node * 2 ].lazy += val;
            Tree[node * 2 + 1].lazy += val;
        }
        return;
    }
    int mid = (b + e) / 2;
    update(node * 2 , b, mid, i, j, val);
    update(node * 2 + 1, mid + 1, e, i, j, val);
    Tree[node].mn = max(Tree[node * 2 ].mn, Tree[node * 2 + 1].mn);
}*/

  Node query(int node,int b, int e, int i, int j)
{
    

    if (b > e || b > j || e < i){

        return Node();}

    if (b >= i && e <= j){
           return Tree[node];
    }

    int mid = (b + e) / 2;
    return mege(query(2 * node,b, mid, i, j),
               query(2 * node + 1,mid + 1, e, i, j));
}


    int main(){
            //ios_base::sync_with_stdio(false);
            int u,m,a,b,t,i,j,k;
            cin>>u;
            for(int i=1;i<=u;i++) cin>>arr[i];
            cin>>m;
            segment_tree(1,1, u);
            int last=0;
            while(m--){

                   cin>>i>>j;
                   Node last=query(1,1,u,i,j);

                   cout<<(last.maxSubarraySum)<<'\n';
            }
            return 0;
        }
