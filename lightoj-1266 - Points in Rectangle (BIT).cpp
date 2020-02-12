#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int n=1e3+10;

ll BIT[n][n];
bool vis[n][n];

void update(int x,int y,ll val)
{
    for(int X=x;X<=n;X += X&-X)
    {
        for(int Y=y;Y<=n;Y+=Y&-Y)
        {
            BIT[X][Y]+=val;
        }
    }
}

ll query_sum_till(int x,int y)
{
    ll sum=0;
    for(int X=x;X>0;X-=X&-X)
    {
        for(int Y=y;Y>0;Y-=Y&-Y)
        {
            sum+=BIT[X][Y];
        }
    }
    return sum;
}

int main()

{
    int tc,q;
    scanf("%d",&tc);
    int caso=1;
    while(tc--)
    {
        scanf("%d",&q);
        memset(BIT,0,sizeof(BIT));
        memset(vis,false,sizeof(vis));
        printf("Case %d:\n",caso);
        caso++;
        while(q--)
        {
            int type;
            scanf("%d",&type);
            if(type==0)
            {
                int x,y;
                ll val;
                scanf("%d%d",&x,&y);
                if(!vis[x][y]){
                update(x+1,y+1,1ll);
                vis[x][y]=true;
                }
            }
            else
            {
                int x1,y1,x,y;
                scanf("%d%d%d%d",&x,&y,&x1,&y1);
                ll ans=query_sum_till(x1+1,y1+1)+query_sum_till(x,y)-query_sum_till(x1+1,y)-query_sum_till(x,y1+1);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
