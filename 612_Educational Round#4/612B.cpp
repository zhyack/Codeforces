#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int a[MAXN],pos[MAXN];
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin);	//++++You fool, comment this line++++//
	while(T-- && ~(scanf("%d",&N))){
		for (int i = 1;i <= N;i++){
			scanf("%d",a+i);
			pos[a[i]] = i;
		}
		long long ans = 0;
		for(int i = 1;i < N;i++) ans+=abs(pos[i+1]-pos[i]);
		printf("%I64d\n",ans);
	}
	return 0;
}
