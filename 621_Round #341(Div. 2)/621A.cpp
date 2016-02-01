#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
long long minodd,sum,x;
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d",&N))){
		minodd = INF;
		sum = 0;
		for (int i = 0;i < N;i++){
			scanf("%I64d",&x);
			if (x&1) minodd = min(x,minodd);
			sum += x;
		}
		if (sum & 1) sum-=minodd;
		printf("%I64d\n",sum);
	}
	return 0;
}
