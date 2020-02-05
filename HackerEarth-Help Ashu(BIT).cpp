#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int BIT[100005];
int arr[100005];
void update(int x,int val)
{
    for(int X=x;X<=n;X += X&-X)
    {
            BIT[X]+=val;
    }
}

ll query_sum(int x)
{
    ll sum=0;
    for(int X=x;X>0;X-=X&-X)
    {
            sum+=BIT[X];
    }
    return sum;
}


int main()

{
    int a;
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
       scanf("%d",&arr[i]);
       if(arr[i]%2==0)
        update(i,1);
   }
   int m;
   scanf("%d",&m);
   int type,i,j;
   while(m--)
   {
       scanf("%d%d%d",&type,&i,&j);
       if(type==0)
       {
           if(arr[i]%2==0) update(i,-1);
           if(j%2==0) update(i,1);
           arr[i]=j;
       }
       else if(type==1||type==2)
       {
           int lngth=j-i+1;
           int even_nm=query_sum(j)-query_sum(i-1);
           int odd=lngth-even_nm;
           if(type==1) printf("%d\n",even_nm);
           else printf("%d\n",odd);
       }
   }
   return 0;
}
