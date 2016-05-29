#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
struct line{
	int x,y;
	int dx,dy;
}a[MAXN];
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d",&N))){
		memset(a,0,sizeof(a));
		for (int i = 0;i <= N;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
			if (i){
				int dx = a[i].x-a[i-1].x;
				int dy = a[i].y-a[i-1].y;
				if (dx>0) a[i].dx = 1;
				else if (dx<0) a[i].dx = -1;
				else if (dy>0) a[i].dy = 1;
				else if (dy<0) a[i].dy = -1;
			}
		}
		int ans = 0;
		for (int i = 1;i <= N;i++){
			int ok = 0;
			if (a[i].dx)
				for (int j = 1;j <= N;j++)
					if (a[j].dx){
						int l = min(a[i].x,a[i].x+a[i].dx);
						int r = max(a[i].x,a[i].x+a[i].dx);
						if (min(a[j-1].x,a[j].x) <= l && max(a[j-1].x,a[j].x) >= r && a[j].y < a[i].y) ok++;
					}
			if (a[i].dy)
				for (int j = 1;j <= N;j++)
					if (a[j].dy){
						int l = min(a[i].y,a[i].y+a[i].dy);
						int r = max(a[i].y,a[i].y+a[i].dy);
						if (min(a[j-1].y,a[j].y) <= l && max(a[j-1].y,a[j].y) >= r && a[j].x < a[i].x) ok++;
					}
			if (ok&1) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
