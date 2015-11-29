#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;

vector <int> edges[MAXN];
int c[MAXN];
long long ans[MAXN];
int maxcnt[MAXN];
map <int,int> mcnt[MAXN];
int mapnum[MAXN];
int x,y;
bool visited[MAXN];

void dfs(int x){
	visited[x] = true;
	maxcnt[x] = 1;
	ans[x] = c[x];
	for (vector<int>::iterator it = edges[x].begin();it != edges[x].end();it++){
		if (visited[*it]) continue;
		int y = *it;
		dfs(y);
		if (mcnt[mapnum[x]].size() < mcnt[mapnum[y]].size())
			swap(mapnum[x],mapnum[y]),ans[x] = ans[y],maxcnt[x] = maxcnt[y];
		int mx = mapnum[x], my = mapnum[y];
		for (map<int,int>::iterator mit = mcnt[my].begin(); mit != mcnt[my].end(); mit++){
			mcnt[mx][mit->first] += mit->second;
			if (mcnt[mx][mit->first] > maxcnt[x]){
				maxcnt[x] = mcnt[mx][mit->first];
				ans[x] = mit->first;
			}
			else if (mcnt[mx][mit->first] == maxcnt[x]) ans[x] += mit->first;
		}
	}
}

int main(){
	while(T-- && ~(scanf("%d",&N))){
		for (int i = 1;i <= N;i++) scanf("%d",c+i);
		for (int i = 0;i <= N;i++) edges[i].clear();
		for (int i = 1;i < N;i++){
			scanf("%d%d",&x,&y);
			edges[x].push_back(y);
			edges[y].push_back(x);
		}
		for (int i = 0;i <= N;i++){
			mcnt[i].clear();
			mcnt[i][c[i]] = 1;
			mapnum[i] = i;
		}
		memset(visited,false,sizeof(visited));
		memset(maxcnt,0,sizeof(maxcnt));
		dfs(1);
		for (int i = 1;i <= N;i++) printf("%I64d ",ans[i]);
		putchar('\n');
	}
	return 0;
}
