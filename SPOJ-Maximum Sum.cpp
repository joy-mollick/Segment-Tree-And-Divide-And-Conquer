#include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;

    #define C 300001

    struct{
        pair<ll,ll>p;
    }Tree[C*4];
    int MX;
    const int n=1e6+1;
    ll arr[C];

    pair<ll,ll> mege(pair<ll,ll>left,pair<ll,ll>right)
    {
        vector<ll>v;
        v.push_back(left.first);
        v.push_back(left.second);
        v.push_back(right.first);
        v.push_back(right.second);
        sort(v.rbegin(),v.rend());
        return (make_pair(v[0],v[1]));
    }


    void segment_tree(int node,int b, int e){
        if(b >= e){
            if(b == e){Tree[node].p=make_pair(arr[b],-1);}
            return;
        }
        else{
        int mid = (b+e)/2, child1 = node*2, child2 = child1+1;
        segment_tree(child1,b, mid);
        segment_tree(child2,mid+1, e);
        Tree[node].p = mege(Tree[child1].p,Tree[child2].p);
        // cout<<b<<" "<<e<<"  -> "<<(Tree[node].p.first)<<" "<<(Tree[node].p.second)<<endl;
        }
    }

  void update(int node, int b, int e, int i,ll val)
{

    if ( i<b || i>e )
        return;

    if (b ==e ) {
        Tree[node].p = make_pair(arr[i],-1);
        return;
    }
    int mid = (b + e) / 2;
    update(node * 2 , b, mid, i, val);
    update(node * 2 + 1, mid + 1, e, i, val);
    Tree[node].p = mege(Tree[node * 2 ].p, Tree[node * 2 + 1].p);
}

  pair<ll,ll> query(int node,int b, int e, int i, int j)
{

    if ( b > j || e < i){
        return make_pair(-1,-1);}

    if (b >= i && e <= j){
           return Tree[node].p;
    }

    int mid = (b + e) / 2;
    return mege(query(2 * node,b, mid, i, j), query(2 * node + 1,mid + 1, e, i, j));
}


    int main(){
            //ios_base::sync_with_stdio(false);
            int u,m,a,b,t,i,j;
            ll k;
            cin>>u;
            for(int i=1;i<=u;i++) cin>>arr[i];
            cin>>m;
            segment_tree(1,1, u);
            char c;
            while(m--){

                   cin>>c>>j>>k;
                   if(c=='U') {arr[j]=k;update(1,1,u,j,k);}
                   else
                   {
                       pair<ll,ll>pq=query(1,1,u,j,k);
                       cout<<(pq.first+pq.second)<<'\n';
                   }
            }
            return 0;
        }
