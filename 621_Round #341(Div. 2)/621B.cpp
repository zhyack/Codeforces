#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
bool g[MAXN][MAXN];
int x,y;
long long ans,cnt;
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d",&N))){
		memset(g,false,sizeof(g));
		ans = 0;
		while(N--){
			scanf("%d%d",&x,&y);
			g[x][y] = true;
		}
		for (y = 1000;y>=1;y--){
			x=1;
			int nx = x,ny = y;
			cnt = 0;
			while(nx <= 1000 && ny <= 1000){
				if (g[nx][ny]) cnt++;
				nx++;
				ny++;
			}
			ans = ans+cnt*(cnt-1)/2;
		}
		for (x = 1000;x>1;x--){
			y = 1;
			int nx = x,ny = y;
			cnt = 0;
			while(nx <= 1000 && ny <= 1000){
				if (g[nx][ny]) cnt++;
				nx++;
				ny++;
			}
			ans = ans+cnt*(cnt-1)/2;
		}
		for (y = 1000;y>=1;y--){
			x=1000;
			int nx = x,ny = y;
			cnt = 0;
			while(nx > 0 && ny <= 1000){
				if (g[nx][ny]) cnt++;
				nx--;
				ny++;
			}
			ans = ans+cnt*(cnt-1)/2;
		}
		for (x = 999;x>=1;x--){
			y = 1;
			int nx = x,ny = y;
			cnt = 0;
			while(nx > 0 && ny <= 1000){
				if (g[nx][ny]) cnt++;
				nx--;
				ny++;
			}
			ans = ans+cnt*(cnt-1)/2;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
