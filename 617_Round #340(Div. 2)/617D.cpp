#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
struct pp{
	int x,y;
	bool operator < (const pp &A) const{
		return x < A.x || x == A.x && y < A.y;
	}
}p[3];
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d%d%d%d%d%d",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y))){
		sort(p,p+3);
		if (p[0].x == p[2].x || p[0].y == p[1].y && p[1].y == p[2].y){
			puts("1");
			continue;
		}
		if (p[0].x == p[1].x && (p[2].y <= p[1].y && p[2].y <= p[0].y||p[2].y >= p[1].y && p[2].y>=p[0].y) ||
				p[1].x == p[2].x && (p[0].y >= p[1].y&&p[0].y>=p[2].y || p[0].y <= p[1].y && p[0].y<=p[2].y) ||
				p[0].y == p[1].y && (p[2].x <= p[0].x && p[2].x <= p[1].x || p[2].x >= p[0].x && p[2].x >= p[1].x)||
				p[0].y == p[2].y && (p[1].x <= p[0].x && p[1].x <= p[2].x || p[1].x >= p[0].x && p[1].x >=p[2].x) ||
				p[1].y == p[2].y && (p[0].x <= p[1].x && p[0].x <= p[2].x || p[0].x >= p[1].x && p[0].x >= p[2].x)){
			puts("2");
			continue;
		}
		puts("3");
	}
	return 0;
}
