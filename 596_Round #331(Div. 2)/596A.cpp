#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int minx,maxx,miny,maxy,x,y;
int main(){
	while(T-- && ~(scanf("%d",&N))){
		minx = INF;
		maxx = -INF;
		miny = INF;
		maxy = -INF;
		for (int i = 0; i < N;i++){
			scanf("%d%d",&x,&y);
			minx = min(minx,x);
			maxx = max(maxx,x);
			miny = min(miny,y);
			maxy = max(maxy,y);
		}
		if (maxx != minx && maxy != miny){
			printf("%d\n",(maxy-miny)*(maxx-minx));
		}
		else puts("-1");
	}
	return 0;
}
