#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
vector<int> edge[MAXN];
int d[MAXN];
long long X,Y;
int x,y;
long long ans;
int cnt;
bool visited[MAXN];
int dp[MAXN][2];

void treedp(int x){
	visited[x] = true;
	int cnt = 0;
	dp[x][1] = 0;
	for (vector<int>::iterator it = edge[x].begin();it != edge[x].end();it++){
		if (visited[*it]) continue;
		treedp(*it);
		dp[x][1] += min(dp[*it][0],dp[*it][1]);
		if (dp[*it][1] <= dp[*it][0]) cnt++;
	}
	if (cnt == 0) dp[x][1]++;
	dp[x][0] = dp[x][1];
	if (d[x] >= 2 && cnt > 1) dp[x][0]--;
}

int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d%I64d%I64d",&N,&X,&Y))){
		for (int i = 0;i <= N;i++) edge[i].clear();
		memset(d,0,sizeof(d));
		for (int i = 0;i < N-1;i++){
			scanf("%d%d",&x,&y);
			edge[x].push_back(y);
			edge[y].push_back(x);
			d[x]++;
			d[y]++;
		}
		if (X >= Y){
			bool full = false;
			for (int i = 1;i <= N;i++) if (d[i] == N-1) full =true;
			if (full) ans = Y*(N-2)+X;
			else ans = Y*(N-1);
		}
		else{
			memset(visited,false,sizeof(visited));
			treedp(1);
			cnt = min(dp[1][0],dp[1][1])-1;
			ans = Y*cnt+X*(N-1-cnt);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
