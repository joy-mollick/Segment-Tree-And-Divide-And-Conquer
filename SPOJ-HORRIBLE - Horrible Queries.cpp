

    #include <bits/stdc++.h>
    #define C 100001
    using namespace std;

    //char Binary[C];
    typedef long long ll;
    struct{
        ll sum;
        ll prop;
    }Tree[C*4];
    int MX;
    int arr[C];

    void segment_tree(int node,int b, int e){
        if(b >= e){
            if(b == e)Tree[node].sum = 0;
            return;
        }
        int mid = (b+e)/2, child1 = node*2, child2 = child1+1;
        segment_tree(child1,b, mid);
        segment_tree(child2,mid+1, e);
        Tree[node].sum = Tree[child1].sum + Tree[child2].sum;
    }

    void update(int node,int b, int e, int i, int j,ll val){
        if(Tree[node].prop!=0)// These will be upper updation before going there
        {
            Tree[node].sum+=(e-b+1)*Tree[node].prop;
            if(b!=e)
            {
                Tree[2*node].prop+=Tree[node].prop;
                Tree[2*node+1].prop+=Tree[node].prop;
            }
            Tree[node].prop=0;
        }
        if(b > e)return;
        if(b > j || e < i)return;
        if(b >= i && e <= j){
            Tree[node].sum += (e-b+1)*val;
            if(b!=e)
            {
                Tree[2*node].prop+=val;
                Tree[2*node+1].prop+=val;
            }
            return;
        }
        int mid = (b+e)/2, child1 = node*2, child2 = child1+1;
        update(child1,b, mid, i, j,val);
        update(child2,mid+1, e, i, j,val);
        Tree[node].sum = Tree[child1].sum + Tree[child2].sum ;
    }

    ll query(int node,int b, int e,  int i,int j){

        if(Tree[node].prop!=0)// These will be upper updation before going there
        {
            Tree[node].sum+=(e-b+1)*Tree[node].prop;
            if(b!=e)
            {
                Tree[2*node].prop+=Tree[node].prop;
                Tree[2*node+1].prop+=Tree[node].prop;
            }
            Tree[node].prop=0;
        }

        if(b > e)return 0;

        if (i > e || j < b) return 0;

        if (b >= i and e <= j)
        {
            return Tree[node].sum;// return that value
        }

        int mid = (b+e)/2, child1 = node*2, child2 = child1+1;
        ll x = query(child1,b, mid, i,j);
        ll y = query(child2,mid+1, e,i,j);
        return x + y;
    }

    int main(){
            int tc;
            cin>>tc;
            while(tc--){
                    memset(Tree,0,sizeof(Tree));
            int n,c,i,j,Q;
            ll nwval;
            cin>>n>>Q;
            segment_tree(1,1, n);
            while(Q--){
               cin>>c;
                if(c==0){
                    cin>>i>>j>>nwval;
                    update(1,1, n, i, j,nwval);
                }
                else{
                    cin>>i>>j;
                    cout<<query(1,1, n, i,j)<<endl;
                }
            }
            }
            return 0;
        }

