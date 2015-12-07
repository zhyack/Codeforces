#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,K,T = INF,Cases = 0;
int a[MAXN];
int fodd[5] = {0,1,0,1,2},feven[5] = {0,1,2,0,1};
int ans;
int *p;
int sg(int x){
	if (x < 5) return p[x];
	else if ((K&1)==0) return ((x+1)&1);
	else if (x&1) return 0;
	else if (sg(x>>1)==1) return 2;
	else return 1;
}
int main(){
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);	//++++You fool, comment this line++++//
	while(T-- && ~(scanf("%d%d",&N,&K))){
		if (K&1) p = fodd;
		else p = feven;
		ans = 0;
		for (int i = 0;i < N;i++){
			scanf("%d",a+i);
			ans ^= sg(a[i]);
		}
		if (ans) puts("Kevin");
		else puts("Nicky");
	}
	return 0;
}
