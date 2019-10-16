

    #include <bits/stdc++.h>
    #define C 100001
    using namespace std;

    char Binary[C];
    struct{
        int sum, prop;
    }Tree[C*4];
    int MX;

    void segment_tree(int node,int b, int e){
        if(b >= e){
            if(b == e)Tree[node].sum = Binary[b]-'0';
            return;
        }
        int mid = (b+e)/2, child1 = node*2, child2 = child1+1;
        segment_tree(child1,b, mid);
        segment_tree(child2,mid+1, e);
        Tree[node].sum = Tree[child1].sum + Tree[child2].sum;
    }

    void update(int node,int b, int e, int I, int J){
        if(b > e)return;
        if(b > J || e < I)return;
        if(b >= I && e <= J){
            Tree[node].sum += ((e-b+1)*1);
            Tree[node].prop += 1;
            return;
        }
        int mid = (b+e)/2, child1 = node*2, child2 = child1+1;
        update(child1,b, mid, I, J);
        update(child2,mid+1, e, I, J);
        Tree[node].sum = Tree[child1].sum + Tree[child2].sum + (e-b+1)*Tree[node].prop;
    }

    int query(int node,int b, int e,  int I, int carry ){
        if(b > e)return 0;
        if(b > I || e < I)return 0;
        if(b == I && e == I)return Tree[node].sum + carry*(e-b+1);
        int mid = (b+e)/2, child1 = node*2, child2 = child1+1;
        int x = query(child1,b, mid, I, carry+Tree[node].prop);
        int y = query(child2,mid+1, e,I, carry+Tree[node].prop);
        return x + y;
    }

    int main(){
        int T, I, J, Q, CS = 0;
        char que[2];
        scanf("%d", &T);
        while(T--){
            scanf("%s", Binary);
            int S = strlen(Binary)-1;
            memset(Tree, 0, sizeof(Tree));
            build(1,0, S);
            scanf("%d", &Q);
            printf("Case %d:\n", ++CS);
            for(int i = 1; i <= Q; i++){
                scanf("%s", que);
                if(que[0] == 'I'){
                    scanf("%d %d", &I, &J);
                    update(1,0, S, I-1, J-1);
                }
                else{
                    scanf("%d", &I);
                    printf("%d\n", query(1,0, S, I-1,0)%2);
                }
            }
        }
        return 0;
    }

