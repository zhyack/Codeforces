#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;
const int INF = 1e9+7;
int N,M,T = INF;
int a[MAXN];
int main(){
	//freopen("input.txt","r",stdin);
	//scanf("%d",&T);
	while(~(scanf("%d%d",&N,&M)) && T--){
		for(int i = 0;i < N;i++) scanf("%d",a+i);
		int cnt = 1;
		for(int i = 1;i < N;i++){
			if (a[i]-a[i-1] <= M) cnt++;
			else cnt = 1;
		}
		printf("%d\n",cnt);
	}
	
	return 0;
}