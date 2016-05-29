#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int cnt[MAXN];
int a;
bool exist;
int p[MAXN];
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d",&N))){
		exist = false;
		for (int i = 0;i < N;i++){
			memset(cnt,0,sizeof(cnt));
			for (int j = 0;j < N;j++){
				scanf("%d\n",&a);
				cnt[a]++;
			}
			int m = 0;
			for (int j = 0;j < N;j++) m = max(m,cnt[j]);
			if (m == 1 && exist) p[i] = N;
			else{
				p[i] = N-m;
				if (p[i] == N-1) exist = true;
			}
		}
		for (int i = 0;i < N;i++) printf("%d ",p[i]);
		putchar('\n');
	}
	return 0;
}
