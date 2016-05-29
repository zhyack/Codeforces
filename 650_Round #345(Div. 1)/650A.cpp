#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
map<long long,int> mx,my,mz;
long long ans;
long long x,y,z;
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d",&N))){
		ans = 0;
		mx.clear();
		my.clear();
		mz.clear();
		while(N--){
			scanf("%d%d",&x,&y);
			z = x*INF+y;
			ans += mx[x]+my[y]-mz[z];
			mx[x]++;
			my[y]++;
			mz[z]++;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
