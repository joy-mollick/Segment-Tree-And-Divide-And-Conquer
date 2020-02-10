#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

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
   // ios_base::sync_with_stdio(false);
     int N=-1;
    while(N!=0)
    {
        memset(BIT,0,sizeof(BIT));
      scanf("%d",&N);
      for(int i = 0; i < N; ++i) {
         scanf("%lld",&A[i]);
         B[i] = A[i];
      }
      sort(B, B + N);
      for(int i = 0; i < N; ++i) {
         int pos = int(lower_bound(B, B + N, A[i]) - B);
         A[i] = pos + 1;
      }
      ll inv_count = 0ll;
      for(int i = N - 1; i >= 0; --i) {
         ll below_pos = below_still( BIT ,A[i] - 1);// First find only below position than A[i]
         inv_count+=below_pos;
         update(BIT,A[i], 1ll);//A[i] is encountered as 1
      }
          if(N!=0){
            printf("%lld\n",inv_count);}
}
   return 0;
}
