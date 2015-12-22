#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200020;
const int MAXB = 22;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;

struct edgeNode{
	int u,v,num;
	long long w;
}e[MAXN];
bool cmp(edgeNode A,edgeNode B){
	return A.w < B.w;
}
int f[MAXN];
int top(int x){
	if (f[x] != x) f[x] = top(f[x]);
	return f[x];
}

int x,y,z,root = 1;
vector<edgeNode> edge[MAXN];
int depth[MAXN],father[MAXN][MAXB];
long long heavy[MAXN][MAXB];
bool visited[MAXN];

void dfs(int x,int d){
	depth[x] = d;
	visited[x] = true;
	for (vector<edgeNode>::iterator it = edge[x].begin();it != edge[x].end();it++){
		if (!visited[it->v]){
			dfs(it->v,d+1);
			father[it->v][0] = x;
			heavy[it->v][0] = it->w;
		}
	}
}
void lcabinarylifting(int n){
	for (int j = 1;j < MAXB;j++)
		for (int i = 1;i <= n;i++)
			if (~father[i][j-1]){
				father[i][j] = father[father[i][j-1]][j-1];
				heavy[i][j] = max(heavy[i][j-1],heavy[father[i][j-1]][j-1]);
			}
}
long long findlca(int u,int v,long long w){
	long long r1 = 0,r2 = 0;
	if (depth[u] < depth[v]) swap(u,v);
	for (int b = MAXB-1;b >= 0;b--)
		if (depth[father[u][b]] >= depth[v]){
			r1 = max(r1,heavy[u][b]);
			u = father[u][b];
		}
	if (u == v) return w-r1;
	for (int b = MAXB-1;b >= 0;b--)
		if (father[u][b] != father[v][b]){
			r1 = max(r1,heavy[u][b]);u = father[u][b];
			r2 = max(r2,heavy[v][b]);v = father[v][b];
		}
	return w-max(max(heavy[u][0],heavy[v][0]),max(r1,r2));
}

long long kruskal(){
	long long ret = 0;
	for (int i = 0;i < M;i++){
		int p = top(e[i].u);
		int q = top(e[i].v);
		if (p != q){
			f[p] = q;
			ret += e[i].w;
			edge[e[i].u].push_back(e[i]);
			swap(e[i].u,e[i].v);
			edge[e[i].u].push_back(e[i]);
		}
	}
	return ret;
}

long long ans[MAXN];

int main(){
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);	//++++You fool, comment this line++++//
	while(T-- && ~(scanf("%d%d",&N,&M))){
		for (int i = 0;i < M;i++) scanf("%d%d%I64d",&e[i].u,&e[i].v,&e[i].w),e[i].num = i;
		sort(e,e+M,cmp);
		for (int i = 0;i <= N;i++) f[i] = i;
		for (int i = 0;i <= N;i++) edge[i].clear();
		long long mst = kruskal();
		memset(father,0xff,sizeof(father));
		memset(heavy,0,sizeof(heavy));
		memset(visited,false,sizeof(visited));
		dfs(root,1);
		lcabinarylifting(N);
		for (int i = 0;i < M;i++) ans[e[i].num] = mst+findlca(e[i].u,e[i].v,e[i].w);
		for (int i = 0;i < M;i++) printf("%I64d\n",ans[i]);
	}
	return 0;
}
