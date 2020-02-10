#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

// Time Complexity O(nlogn)


const int MAXN = 200002;
int BIT[MAXN], A[MAXN],B[MAXN];

int below_still(int idx){
 int sum = 0;
 while (idx > 0){
  sum += BIT[idx];
  idx -= (idx & -idx);
 }
 return sum;
}

void update(int idx ,int val){
 while (idx <= MAXN){
  BIT[idx] += val;
  idx += (idx & -idx);
 }
}

int main(){
 int n, x, y, i;
    int cases = 0;
    char op[10], cmd[50];
    while(scanf("%d", &n) == 1 && n) {
        for(i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            BIT[i] = 0;
        }
        for(i = 1; i <= n; i++){
            update(i, A[i]);}
        while(getchar() != '\n');
        if(cases)   puts("");
        printf("Case %d:\n", ++cases);
        while(gets(cmd)) {
            if(cmd[0] == 'E')
                break;
            sscanf(cmd, "%s %d %d", op, &x, &y);
            if(op[0] == 'M')
                printf("%d\n", below_still(y) - below_still(x-1));
            else {
                update(x, y-A[x]);
                A[x] = y;
            }
        }
    }
    }
