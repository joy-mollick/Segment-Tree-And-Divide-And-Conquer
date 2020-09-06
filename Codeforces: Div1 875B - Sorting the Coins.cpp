
/// Codeforces: Div1 875B - Sorting the Coins 
/// Category: Observation + BIT.(medium)


#include<bits/stdc++.h>

using namespace std;

const int mxn=300001;
 set<int>initial;

int BIT[mxn];

inline void update(int x,int val)
{
    for(int X=x;X<=mxn;X += X&-X)
    {
            BIT[X]+=val;
    }
}

/// number of less than x.
inline int query_sum_till(int x)
{
    int sum=0;
    for(int X=x;X>0;X-=X&-X)
    {
            sum+=BIT[X];
    }
    return sum;
}

int main()
{

    int n,pos;
    scanf("%d",&n);

    for(int i=1;i<=n;++i) initial.insert(i);/// initial all are out of circulation

    printf("1 ");

    for(int i=1;i<=n;++i)
    {
        if(i==n) {printf(" 1"); break;}
        scanf("%d",&pos);
        if(!initial.empty())
        initial.erase(pos);
        update(pos,1ll);
        int last_pos_initial=(*initial.rbegin());
        int crosses_to_left_of_rightmost=query_sum_till(last_pos_initial-1);
        printf(" %d",(crosses_to_left_of_rightmost+1));
    }
    return 0;
    }
