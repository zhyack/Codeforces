#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int l,r;
double p[MAXN];

int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d%d",&N,&M))){
		for (int i = 1;i <= N;i++){
			scanf("%d%d",&l,&r);
			int ok = r/M-(l-1)/M;
			p[i] = double(ok)/double(r-l+1);
		}
		p[0] = p[N];
		p[N+1] = p[1];
		double ans = 0;
		for (int i = 1;i <= N;i++)
			ans += p[i]*2000+(1.0-p[i])*(p[i-1]+p[i+1])*1000;
		printf("%.12lf\n",ans);
	}
	return 0;
}
