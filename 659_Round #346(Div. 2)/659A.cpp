#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,K,T = INF,Cases = 0;

int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d%d%d",&N,&M,&K))){
		int ans = ((M+K)%N+N)%N;
		if (ans == 0) ans = N;
		printf("%d\n",ans);
	}
	return 0;
}
