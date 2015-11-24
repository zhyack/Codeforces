#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
long long x,n,m;
struct pairnode{
	long long x,y;
}ans[MAXN];
int anscnt;
bool cmp(pairnode A,pairnode B){
	return A.x < B.x;
}
int main(){
	while(T-- && ~(scanf("%I64d",&x))){
		anscnt = 0;
		n = 0;
		while(true){
			n++;
			if (n*(n+1)/2*(n*2+1)/3 > x) break;
			if (n*(n+1)/2*(n*2+1)/3 == x){
				ans[anscnt].y= n;
				ans[anscnt].x = n;
				anscnt++;
				continue;
			}
			long long t = x-n*(n+1)/2*(n*2+1)/3;
			if (t*2 % (n*n+n) == 0){
				t = t*2/(n*n+n);
				m = t+n;
				ans[anscnt].x= n;
				ans[anscnt].y = m;
				anscnt++;
				ans[anscnt].y= n;
				ans[anscnt].x = m;
				anscnt++;
			}
		}
		printf("%d\n",anscnt);
		sort(ans,ans+anscnt,cmp);
		for (int i = 0;i < anscnt;i++) printf("%I64d %I64d\n",ans[i].x,ans[i].y);
	}
	return 0;
}
