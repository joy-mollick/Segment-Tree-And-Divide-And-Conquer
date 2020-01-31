    #include <bits/stdc++.h>

    using namespace std;

    typedef  long long ll;

    #define C 300001

    struct{
        ll lazy;
        ll mn;
        vector<int>v;
    }Tree[C*4];
    int MX;
    const int n=1e6+1;
    ll arr[C];

    vector<int> mege(vector<int>& v1, vector<int>& v2)
{
    int i = 0, j = 0;
    vector<int> v;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] <= v2[j]) {
            v.push_back(v1[i]);
            i++;
        }
        else {
            v.push_back(v2[j]);
            j++;
        }
    }

    for (int k = i; k < v1.size(); k++)
        v.push_back(v1[k]);
    for (int k = j; k < v2.size(); k++)
        v.push_back(v2[k]);
    return v;
}


    void segment_tree(int node,int b, int e){
        if(b >= e){
            if(b == e){Tree[node].v.push_back (arr[b]);}
            return;
        }
        int mid = (b+e)/2, child1 = node*2, child2 = child1+1;
        segment_tree(child1,b, mid);
        segment_tree(child2,mid+1, e);
        Tree[node].v = mege(Tree[child1].v,Tree[child2].v);
    }

  void update(int node, int b, int e, int i,
                     int j, ll val)
{

    if (Tree[node].lazy != 0) {

        Tree[node].mn += Tree[node].lazy;

        if (b != e) {
            Tree[node * 2 ].lazy += Tree[node].lazy;
            Tree[node * 2 + 1].lazy += Tree[node].lazy;
        }

        Tree[node].lazy = 0;
    }
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
}

  int query(int node,int b, int e, int i, int j,int k)
{
    if (Tree[node].lazy != 0) {
        Tree[node].mn += Tree[node].lazy;
        if (b != e) {
            Tree[node * 2 ].lazy += Tree[node].lazy;
            Tree[node * 2 + 1].lazy += Tree[node].lazy;
        }
        Tree[node].lazy = 0;
    }

    if (b > e || b > j || e < i){
        return 0;}

    if (b >= i && e <= j){
            int tot_sz=Tree[node].v.size();
            int start=(upper_bound(Tree[node].v.begin(),
                               Tree[node].v.end(), k) - Tree[node].v.begin());
                               return(tot_sz-start);
    }

    int mid = (b + e) / 2;
    return (query(2 * node,b, mid, i, j,k)+
               query(2 * node + 1,mid + 1, e, i, j,k));
}


    int main(){
            //ios_base::sync_with_stdio(false);
            int u,m,a,b,t,i,j,k;
            memset(Tree,0,sizeof(Tree));
            cin>>u;
            for(int i=1;i<=u;i++) cin>>arr[i];
            cin>>m;
            segment_tree(1,1, u);
            int last=0;
            while(m--){

                   cin>>i>>j>>k;
                   i=last^i;
                   j=last^j;
                   k=last^k;
                   if(i<1) i=1;
                   if(j>n) j=n;
                   last=query(1,1,u,i,j,k);

                   cout<<last<<'\n';
            }
            return 0;
        }
