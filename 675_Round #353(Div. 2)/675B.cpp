#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;

int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	int n,a,b,c,d,e,mi,ma;
	while(T-- && ~(scanf("%d%d%d%d%d",&n,&a,&b,&c,&d))){
		long long ans = 0;
		for (e=1;e<=n;e++){
			mi = min(a+b+e,min(b+d+e,min(a+c+e,c+d+e)));
			ma = max(a+b+e,max(b+d+e,max(a+c+e,c+d+e)));
			if (mi==ma) ans+=n;
			else ans += max(0,n-ma+mi);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
