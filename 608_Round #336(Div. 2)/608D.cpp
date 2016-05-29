#include <bits/stdc++.h>
using namespace std;

const int MAXN = 510;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int a[MAXN];
int dp[MAXN][MAXN];
int main(){
    //ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin); //++++You fool, comment this line++++//
    while(T-- && ~(scanf("%d",&N))){
        for (int i = 1;i <= N;i++) scanf("%d",a+i);
        for (int i = 1;i <= N;i++) dp[i][i] = 1;
        for (int k = 1;k < N;k++){
            for (int i = 1;i+k <= N;i++){
                int j = i+k;
                dp[i][j] = INF;
                for (int p = i;p <= j;p++){
                    if (p == i) dp[i][j] = min(dp[i][j],dp[p+1][j]+1);
                    else if (a[p] == a[i]){
                        if (p == i+1){
                            if (j == p) dp[i][j] = min(dp[i][j],1);
                            else dp[i][j] = min(dp[i][j],dp[p+1][j]+1);
                        }
                        else{
                            if (j == p) dp[i][j] = min(dp[i][j],dp[i+1][p-1]);
                            else dp[i][j] = min(dp[i][j],dp[i+1][p-1]+dp[p+1][j]);
                        }
                    }
                }
            }
        }
        printf("%d\n",dp[1][N]);
    }
    return 0;
}
