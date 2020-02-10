#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

// Time Complexity O(nlogn)


const int MAXN =  1000002;
int BITzero[MAXN],BITplus[MAXN],BITneg[MAXN], A[MAXN],B[MAXN];

int sum_still(int *tree,int idx){
 int sum = 0;
 while (idx > 0){
  sum += tree[idx];
  idx -= (idx & -idx);
 }
 return sum;
}

void update(int *tree,int idx ,int val){
 while (idx <= MAXN){
  tree[idx] += val;
  idx += (idx & -idx);
 }
}

int main()

{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
     int N,Q;
    while(cin>>N>>Q)
    {
        memset(BITzero,0,sizeof(BITzero));
        memset(BITplus,0,sizeof(BITplus));
        memset(BITneg,0,sizeof(BITneg));
      for(int i = 1; i <= N; ++i) {
         cin>>A[i];
         if(A[i]==0)
         {
             update(BITzero,i,1ll);
         }
         if(A[i]>0)
         {
             update(BITplus,i,1ll);
         }
         if(A[i]<0)
         {
             update(BITneg,i,1ll);
         }
      }
      char c;
      int l,r,zero=0,pos=0,neg=0;
      while(Q--)
      {
          cin>>c>>l>>r;
          if(c=='C'){
          if (A[l]>0) {update(BITplus,l,-1);}
          else if(A[l]==0) {update(BITzero,l,-1);}
          else {update(BITneg,l,-1);}
           if(r==0)
         {
             update(BITzero,l,1ll);
         }
         if(r>0)
         {
             update(BITplus,l,1ll);
         }
         if(r<0)
         {
             update(BITneg,l,1ll);
         }
         A[l]=r;
          }
          else
          {
             zero=sum_still(BITzero,r)-sum_still(BITzero,l-1);
             pos= sum_still(BITplus,r)-sum_still(BITplus,l-1);
             neg= sum_still(BITneg,r)-sum_still(BITneg,l-1);
            if(zero>0) cout<<'0';
            else if(neg>0&&(neg%2==1)) cout<<'-';
            else cout<<'+';
          }
      }
      cout<<'\n';
}
   return 0;
}
