#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int a[MAXN];
vector<int> b[MAXN];
int bcnt;
int main(){
	//ios_base::sync_with_stdio(0);

	freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d",&N))){
		for (int i = 0;i < N;i++) scanf("%d",a+i);
		bcnt = 0;
		sort(a,a+N);
		int ans = 0;
		for (int i = 0;i < N;i++) b[i].clear();
		for (int i = 0;i < N;i++){
			bool ok = false;
			for (int j = 0;j < bcnt;j++){
				if (a[i] > b[j].back()){
					b[j].push_back(a[i]);
					ok = true;
					break;
				}
			}
			if (!ok) b[bcnt++].push_back(a[i]);
			else ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
