#include<bits/stdc++.h>

using namespace std;

int BIT[100002];
int arr[100002];
int last_pos[100001];

struct Query
{
    int left,right,index;
};

bool comp(Query x,Query y)
{
    return (x.right<y.right);
}

int n;

void update(int i,int val)
{
    for(int index=i;index<=n;index += index&-index)
    {
        BIT[index]+=val;
    }
}

int distinct_numbers_till(int i)
{
    int sum=0;
    for(int index=i;index>0;index-=index&-index)
    {
        sum+=BIT[index];
    }
    return sum;
}

int main()

{
    int tc,k,j,y;
    scanf("%d",&tc);
    for(int caso=1;caso<=tc;caso++)
    {
        int q;
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        Query queries[q];
        for(int m=0;m<q;m++)
        {
            scanf("%d%d",&k,&j);
            queries[m].left=k;
            queries[m].right=j;
            queries[m].index=m;
        }
        sort(queries,queries+q,comp);
        int ans[q]={0};
        int query=0;
        memset(last_pos,-1,sizeof(last_pos));
        memset(BIT,0,sizeof(BIT));
        for( y=0;y<n;y++)
        {
            if(last_pos[arr[y]]!=-1){
                update(last_pos[arr[y]]+1,-1);}

            last_pos[arr[y]]=y;
            update(y+1,1);

            while(query<q&&queries[query].right==y+1)
            {
                ans[queries[query].index]=distinct_numbers_till(queries[query].right)-distinct_numbers_till(queries[query].left-1);
                query++;
            }
        }
        printf("Case %d:\n",caso);
        for(int p=0;p<q;p++)
        {
            printf("%d\n",ans[p]);
        }
    }
    return 0;
}
