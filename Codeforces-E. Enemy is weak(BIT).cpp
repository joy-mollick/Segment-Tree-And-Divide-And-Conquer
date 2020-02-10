#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

// Time Complexity O(nlogn)


const int MAXN = 1100100;
ll BIT[MAXN], A[MAXN],B[MAXN];
ll BITinv[MAXN];

ll below_still(ll *tree,int idx){
 ll sum = 0;
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
      int N;
      cin>>N;
      for(int i = 0; i < N; ++i) {
         scanf("%lld",&A[i]);
         B[i] = A[i];
      }
      sort(B, B + N);
      for(int i = 0; i < N; ++i) {
         int pos = int(lower_bound(B, B + N, A[i]) - B);
         A[i] = pos + 1;
      }
      ll triple_inv_count = 0ll;
      for(int i = N - 1; i >= 0; --i) {
         ll below_pos = below_still( BIT ,A[i] - 1);// First find only below position than A[i] ,
         ll tot_inv=below_still( BITinv,A[i] - 1);// Total inversions with A[i]-1 ,so this will be also inversions with A[i],so triplet inversions .
         triple_inv_count += tot_inv;
         update(BIT,A[i], 1ll);//A[i] is encountered as 1
         update(BITinv,A[i],below_pos);//Total below positions stored 
      }
      cout<<triple_inv_count<<endl;
   return 0;
}
