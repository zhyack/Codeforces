#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;

long long dp[MAXN];
int a[MAXN];
int l,r;
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d",&N))){
		for (int i = 0;i < N;i++) scanf("%d",a+i);
		memset(dp,0,sizeof(dp));
		l = 0,r = N-1;
		while(a[l] == 0) l++;
		while(a[r] == 0) r--;
		if (l > r){
			puts("0");
			continue;
		}
		dp[l] = 1;
		for (int i = l+1;i <= r;i++){
			int cnt = 0;
			if (a[i] == 0) dp[i] = dp[i-1];
			else for (int j = i;j >= l && cnt < 2;j--){
				dp[i] += dp[j];
				if (a[j] == 1) cnt++;
			}
		}
		printf("%I64d\n",dp[r]);
	}
	return 0;
}
