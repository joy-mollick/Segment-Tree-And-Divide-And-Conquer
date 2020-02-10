#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

// Time Complexity O(nlogn)


const int MAXN =  1000002;
ll BIT[MAXN], A[MAXN];

ll sum_still(ll *tree,int idx){
 ll sum = 0ll;
 while (idx > 0){
  sum += tree[idx];
  idx -= (idx & -idx);
 }
 return sum;
}

void update(ll *tree,int idx ,ll val){
 while (idx <= MAXN){
  tree[idx] += val;
  idx += (idx & -idx);
 }
}

int main()

{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int N;
   cin>>N;
   for(int i=1;i<=N;i++)
   {
       cin>>A[i];
       update(BIT,i,A[i]);
   }
   char c;
   int q,l,r;
   ll val;
   cin>>q;
   while(q--){
   cin>>c;
   if(c=='u')
   {
       cin>>l>>val;
       update(BIT,l,-A[l]);
       A[l]=A[l]+val;
       update(BIT,l,A[l]);
   }
   else{
    cin>>l>>r;
    ll sum=sum_still(BIT,r)-sum_still(BIT,l-1);
    cout<<sum<<'\n';
   }
   }
   return 0;

}
