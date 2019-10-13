
#include<bits/stdc++.h>

using namespace std;

const int mx=1000001;

int tree[4*mx];
int arr[mx];

void construct_segment_tree(int root_index,int b,int e)
{
    if(b==e)// begin and end range is equal means leaf node comes place this value
    {
        tree[root_index]=(arr[b]);
        //cout<<tree[root_index]<<endl;
        return ;
    }
    int left=root_index*2;
    int right=(root_index*2)+1;
    int mid=(b+e)>>1;// one half will be left range and another half will be right range
    construct_segment_tree(left,b,mid);// left tree will be construct when left is root and b-mid is range
    construct_segment_tree(right,mid+1,e);//right tree will be constructed when right is root node and mid+1 - e is range
    tree[root_index]=(tree[left]+tree[right]);//when left and right will be constructed then root_index will be sum of left and right
}

int query_sum(int root_index,int b,int e,int val)
{
    if(b==e&&val==1) // inside overlap ,so we will get value
    {
        return b;
    }
    int left=2*root_index;
    int right=(2*root_index+1);
    int mid=(b+e)/2;
    int l1=tree[left];
    int r1=tree[right];
    if(val>l1)//Then we have to search among right child of this node
    {
        val=val-l1;
        return(query_sum(right,mid+1,e,val));
    }
    else{
        return (query_sum(left,b,mid,val));
    }
}

void update(int root_index,int b,int e,int i)
{
     if(i>e||i<b)// outside overlap nothing we get
    {
        return;
    }
    if(i==b&&i==e) // that node we get
    {
        tree[root_index]=(arr[i]);
        return;
    }
    int left=(2*root_index);
    int right=(2*root_index)+1;
    int mid=(b+e)>>1;
    update(left,b,mid,i);
    update(right,mid+1,e,i);
    tree[root_index]=(tree[left]+tree[right]);
}

int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        arr[i]=1;
    }
   construct_segment_tree(1,1,n);
   int l,r;
   int c;
  // update(1,1,n,2,6);
   while(q--){
   scanf("%d",&c);
   if(c==0)
   {
       scanf("%d",&l);
       arr[l]=0;
       update(1,1,n,l);
   }
   else
   {
       scanf("%d",&l);
       if(l>tree[1]) printf("-1\n");//Given is bigger than the total sum .
       else printf("%d\n",query_sum(1,1,n,l));
   }

   }

}
