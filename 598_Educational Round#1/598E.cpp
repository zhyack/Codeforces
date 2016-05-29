#include <bits/stdc++.h>
using namespace std;

const int MAXN = 310;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,K,T = INF,Cases = 0;

unsigned int dp[MAXN][MAXN][55];

int main(){
	scanf("%d",&T);
	memset(dp,0x3f3f3f3f,sizeof(dp));
	for (int i = 1;i <= 30;i++)
		for (int j = 1;j <= 30;j++){
			int kmax = min(50,i*j);
			dp[i][j][0] = 0;
			for (int k = 1;k <= kmax;k++){
				if (k == i*j){
					dp[i][j][k] = 0;
					continue;
				}
				for (int lk = 0;lk <= k;lk++){
					for (int ni = 1;ni < i;ni++)
						dp[i][j][k] = min(dp[i][j][k],dp[ni][j][lk]+dp[i-ni][j][k-lk]+j*j);
					for (int nj = 1;nj < j;nj++)
						dp[i][j][k] = min(dp[i][j][k],dp[i][nj][lk]+dp[i][j-nj][k-lk]+i*i);
				}
			}
		}
	while(T-- && ~(scanf("%d%d%d",&N,&M,&K))){
		printf("%d\n",dp[N][M][K]);
	}
	return 0;
}
