#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int BIT[1025][1025];
int mat[1025][1025];


int n;

void update(int x,int y,int val)
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
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        memset(BIT,0,sizeof(BIT));
        while(true)
        {
            char s[5];
            scanf("%s",s);
            if(s[1]=='E')
            {
                int x,y;
                ll val;
                scanf("%d%d%lld",&x,&y,&val);
                ll tot_sum_of_x_y=query_sum_till(x+1,y+1)+query_sum_till(x,y)-query_sum_till(x+1,y)-query_sum_till(x,y+1);
                
                // we have to add our value to that index x,y .it is the case for adding value in BIT
                // But this is the case where we have to assign the value .Basically, we have to add the value |value-BIT(x,y)|
                // To find out the exact BIT value of BIT[x][y] ,we have to apply the inclusion-exclusion rules.
                
                ll value_add_will_be=val-tot_sum_of_x_y;
                update(x+1,y+1,value_add_will_be);
            }
            else if(s[1]=='U')
            {
                int x1,y1,x,y;
                scanf("%d%d%d%d",&x,&y,&x1,&y1);
                ll ans=query_sum_till(x1+1,y1+1)+query_sum_till(x,y)-query_sum_till(x1+1,y)-query_sum_till(x,y1+1);
                printf("%lld\n",ans);
            }
            else
            {
                break;
            }
        }
        printf("\n");
    }
    return 0;
}
