#include<bits/stdc++.h>

using namespace std;

const int mx=1e5;
int tree[4*mx+1];
int arr[mx+1];

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
    tree[root_index]=(tree[left]^tree[right]);//when left and right will be constructed then root_index will be sum of left and right
}

int query_sum(int root_index,int b,int e,int i,int j)
{
    if(i>e||j<b)// outside overlap nothing we get
    {
        return tree[root_index];
    }
    if(i<=b&&e<=j) // inside overlap ,so we will get value
    {
        return 0;
    }
    int left=2*root_index;
    int right=(2*root_index+1);
    int mid=(b+e)/2;
    int l1=query_sum(left,b,mid,i,j);
    int r1=query_sum(right,mid+1,e,i,j);
    return (l1^r1);
}

int main() {
    int tc;
    cin>>tc;
    while(tc--){
    int n;
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
   construct_segment_tree(1,1,n);
   int l,r;
   while(q--){
   cin>>l>>r;
   cout<<query_sum(1,1,n,l,r)<<endl;
   }
    }

}
