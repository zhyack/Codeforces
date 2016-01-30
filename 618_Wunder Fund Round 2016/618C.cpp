#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const long double eps = 1e-20;
int N,M,T = INF,Cases = 0;
struct pp{
	long double x,y;
	int num;
	bool operator < (const pp &A) const{
		long double a1 = atan2(x,y),a2 = atan2(A.x,A.y);
		return a1 < a2 || (abs(a1-a2)<eps) && (x*x+y*y < A.x*A.y+A.y*A.y);
	}
}p[MAXN];
bool cmp(pp A,pp B){
	return A.x < B.x || A.x == B.x && A.y < B.y;
}
int x,y;
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d",&N))){
		for (int i = 0;i < N;i++){
			scanf("%d%d",&x,&y);
			p[i].x = x;
			p[i].y = y;
			p[i].num = i+1;
		}
		sort(p,p+N,cmp);
		x = p[0].x;
		y = p[0].y;
		for (int i = 0;i < N;i++) p[i].x-=x,p[i].y-=y;
		sort(p+1,p+N);
		long double a1 = atan2(p[1].x,p[1].y),a2;
		int ans = -1;
		for (int i = 2;i < N;i++){
			a2 = atan2(p[i].x,p[i].y);
			if (abs(a2 - a1) > eps){
				ans = i;
				break;
			}
		}
		printf("%d %d %d\n",p[0].num,p[1].num,p[ans].num);
	}
	return 0;
}
