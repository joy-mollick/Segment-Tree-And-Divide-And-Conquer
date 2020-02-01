    #include <bits/stdc++.h>

    using namespace std;

    typedef  long long ll;

    #define C 40001
    #define inf 1e14

    struct {
        int prime_numbers;
        int prop;
    }Tree[4*C];

    int MX;
    const int n=1e6+7;
    ll arr[C];
    bool prime[n];

    void sieve()
    {
        memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p){
                prime[i] = false;}
        }
    }
    prime[1]=false;
    }

    void segment_tree(int node,int b, int e){
            if(b == e){
                if(prime[arr[b]])
                {
                    Tree[node].prime_numbers=1;
                }
                else Tree[node].prime_numbers=0;

                return;
            }

        int mid = (b+e)/2, child1 = node*2, child2 = child1+1;
        segment_tree(child1,b, mid);
        segment_tree(child2,mid+1, e);
        Tree[node].prime_numbers = (Tree[child1].prime_numbers+Tree[child2].prime_numbers);
    }

  void update(int node,int b, int e, int i, int j,int val){
        if(Tree[node].prop!=0)// These will be upper updation before going there
        {
            if(prime[Tree[node].prop])
            Tree[node].prime_numbers=(e-b+1);

            else Tree[node].prime_numbers=0;

            if(b!=e)
            {
                Tree[2*node].prop=Tree[node].prop;
                Tree[2*node+1].prop=Tree[node].prop;
            }
            Tree[node].prop=0;
        }
        if(b > e)return;
        if(b > j || e < i)return;
        if(b >= i && e <= j){
             if(prime[val])
            Tree[node].prime_numbers=(e-b+1);

            else Tree[node].prime_numbers=0;

            if(b!=e)
            {
                Tree[2*node].prop=val;
                Tree[2*node+1].prop=val;
            }
            Tree[node].prop=0;
            return;
        }
        int mid = (b+e)/2, child1 = node*2, child2 = child1+1;
        update(child1,b, mid, i, j,val);
        update(child2,mid+1, e, i, j,val);
        Tree[node].prime_numbers = Tree[child1].prime_numbers + Tree[child2].prime_numbers ;
    }

    ll query(int node,int b, int e,  int i,int j){

        if(Tree[node].prop!=0)// These will be upper updation before going there
        {
            if(prime[Tree[node].prop])
            Tree[node].prime_numbers=(e-b+1);

            else Tree[node].prime_numbers=0;

            if(b!=e)
            {
                Tree[2*node].prop=Tree[node].prop;
                Tree[2*node+1].prop=Tree[node].prop;
            }
            Tree[node].prop=0;
        }

        if(b > e)return 0;

        if (i > e || j < b) return 0;

        if (b >= i and e <= j)
        {
            return Tree[node].prime_numbers;// return that value
        }

        int mid = (b+e)/2, child1 = node*2, child2 = child1+1;
        int x = query(child1,b, mid, i,j);
        int y = query(child2,mid+1, e,i,j);
        return x + y;
    }



    int main(){
            //ios_base::sync_with_stdio(false);
            sieve();
            int tc;
            scanf("%d",&tc);
            int cse=1;
            while(tc--){
            memset(Tree,0,sizeof(Tree));
            int u,m,a,b,t,i,j,k;
            scanf("%d%d",&u,&m);
            for(int i=1;i<=u;i++) scanf("%d",&arr[i]);
            printf("Case %d:\n",cse);
            segment_tree(1,1, u);
            while(m--){

                   scanf("%d",&k);
                   if(k==0){
                    scanf("%d%d%d",&i,&j,&t);
                   update(1,1,u,i,j,t);}
                   else
                   {
                       scanf("%d%d",&i,&j);
                       printf("%d\n",query(1,1,u,i,j));
                   }
            }
             cse++;
            }
            return 0;
        }
