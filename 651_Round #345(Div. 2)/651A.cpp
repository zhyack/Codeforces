#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;

int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d%d",&N,&M))){
		int ans = 0;
		while(N>0 && M>0){
			if (N<M) N++,M-=2;
			else M++,N-=2;
			ans++;
			if (N<0 || M <0) ans--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
