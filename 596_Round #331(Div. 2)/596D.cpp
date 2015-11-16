#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;

double dp[MAXN][MAXN][2][2];
int x[MAXN];
int tl[MAXN],tr[MAXN];
int h;
double p;
double e;
bool visited[MAXN][MAXN][2][2];
double dpit(int l,int r,int dl,int dr){
	if (l > r) return 0.0;
	if (visited[l][r][dl][dr]) return dp[l][r][dl][dr];
	visited[l][r][dl][dr] = true;
	int ll,rr;
	ll = x[l]-x[l-1]-(dl?h:0);
	rr = x[r+1]-x[r]-(dr?h:0);
	dp[l][r][dl][dr] = 0.0;
	dp[l][r][dl][dr] += 0.5*p*(min(h,ll)+dpit(l+1,r,0,dr));
	if (tr[l] <= r) dp[l][r][dl][dr] += 0.5*(1-p)*((x[tr[l]-1]-x[l]+h)+dpit(tr[l],r,1,dr));
	else dp[l][r][dl][dr] += 0.5*(1-p)*(x[r]-x[l]+min(h,rr));
	if (tl[r] >= l) dp[l][r][dl][dr] += 0.5*p*((x[r]-x[tl[r]+1]+h)+dpit(l,tl[r],dl,1));
	else dp[l][r][dl][dr] += 0.5*p*(x[r]-x[l]+min(h,ll));
	dp[l][r][dl][dr] += 0.5*(1-p)*(min(h,rr)+dpit(l,r-1,dl,0));
	return dp[l][r][dl][dr];
}
int main(){
	while(T-- && ~(scanf("%d%d%lf",&N,&h,&p))){
		for (int i = 1;i <= N;i++) scanf("%d",x+i);
		sort(x+1,x+N+1);
		int l = 1,r = 2;
		x[0] = -INF;
		x[N+1] = INF;
		while(l <= N){
			while(x[r]-x[r-1] < h) r++;
			while(l < r) tr[l++] = r;
			r++;
		}
		l = N-1,r = N;
		while(r > 0){
			while(x[l+1]-x[l] < h) l--;
			while(l < r) tl[r--] = l;
			l--;
		}
		memset(visited,false,sizeof(visited));
		e = dpit(1,N,0,0);
		printf("%lf\n",e);
	}
	return 0;
}
