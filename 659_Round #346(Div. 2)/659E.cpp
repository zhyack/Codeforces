#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int x,y;
int father[MAXN];
bool loop[MAXN];
int top(int x){
	if (father[x]!=x) father[x]=top(father[x]);
	return father[x];
}
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d%d",&N,&M))){
		for (int i = 0;i <= N;i++) father[i] = i;
		memset(loop,false,sizeof(loop));
		while(M--){
			scanf("%d%d",&x,&y);
			int fx = top(x);
			int fy = top(y);
			if (fx != fy){
				father[fx] = fy;
				loop[fy] = loop[fx]||loop[fy];
			}
			else loop[fx] = true;
		}
		int ans = 0;
		for (int i = 1;i <= N;i++){
			int f = top(i);
			if (loop[f] == false){
				loop[f] = true;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
