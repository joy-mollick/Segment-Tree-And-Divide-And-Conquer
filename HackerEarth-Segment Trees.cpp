
#include<bits/stdc++.h>

using namespace std;

int tree[10000];
int arr[100];

void construct_segment_tree(int root_index,int b,int e)
{
    if(b==e)// begin and end range is equal means leaf node comes place this value
    {
        tree[root_index]=arr[b];
        return ;
    }
    int left=root_index*2;
    int right=(root_index*2)+1;
    int mid=(b+e)>>1;// one half will be left range and another half will be right range
    construct_segment_tree(left,b,mid);// left tree will be construct when left is root and b-mid is range
    construct_segment_tree(right,mid+1,e);//right tree will be constructed when right is root node and mid+1 - e is range
    tree[root_index]=min(tree[left],tree[right]);//when left and right will be constructed then root_index will be sum of left and right
}

int query_sum(int root_index,int b,int e,int i,int j)
{
    if(i>e||j<b)// outside overlap nothing we get
    {
        return INT_MAX;
    }
    if(i<=b&&e<=j) // inside overlap ,so we will get value
    {
        return tree[root_index];
    }
    int left=2*root_index;
    int right=(2*root_index+1);
    int mid=(b+e)/2;
    int l1=query_sum(left,b,mid,i,j);
    int r1=query_sum(right,mid+1,e,i,j);
    return min(l1,r1);
}

void update(int root_index,int b,int e,int i,int nwval)
{
     if(i>e||i<b)// outside overlap nothing we get
    {
        return;
    }
    if(i==b&&i==e) // that node we get
    {
        tree[root_index]=nwval;
        return;
    }
    int left=(2*root_index);
    int right=(2*root_index)+1;
    int mid=(b+e)>>1;
    update(left,b,mid,i,nwval);
    update(right,mid+1,e,i,nwval);
    tree[root_index]=min(tree[left],tree[right]);
}

int main() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
   construct_segment_tree(1,1,n);
   int l,r;
   char c;
  // update(1,1,n,2,6);
   while(q--){
   cin>>c>>l>>r;
   if(c=='q')
   cout<<query_sum(1,1,n,l,r)<<endl;
   else update(1,1,n,l,r);
   }

}
