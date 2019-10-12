#include<bits/stdc++.h>

using namespace std;

const int mx=300;
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
    tree[root_index]=__gcd(tree[left],tree[right]);//when left and right will be constructed then root_index will be sum of left and right
}

int query(int root_index,int b,int e,int i,int j)
{
    if(i>e||j<b)// outside overlap nothing we get
    {
        return 0;
    }
    if(i<=b&&e<=j) // inside overlap ,so we will get value
    {
        return tree[root_index];
    }
    int left=2*root_index;
    int right=(2*root_index+1);
    int mid=(b+e)/2;
    int l1=query(left,b,mid,i,j);
    int r1=query(right,mid+1,e,i,j);
    return __gcd(l1,r1);
}
int min_sub(int G,int n)
{
    bool ok=false;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]%G==0) ok=true;
    }
    if(!ok) return -1;
    int ans=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int gcd=query(1,1,n,i,j);
            if(gcd==G)
            {
                ans=min(ans,(j-i)+1);
            }
        }
    }
    if(ans==INT_MAX) return -1;
    else return ans;
}
int main() {
    int tc;
    cin>>tc;
    while(tc--){
    int n;
    int G;
    cin>>G>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
   construct_segment_tree(1,1,n);
   cout<<min_sub(G,n)<<endl;
    }

}
