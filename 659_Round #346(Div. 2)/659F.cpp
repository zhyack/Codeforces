#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
long long K;
int father[MAXN];
int cnt[MAXN];
long long maxcnt;
int top(int x){
	if (father[x] != x) father[x] = top(father[x]);
	return father[x];
}
struct inode{
	int val;
	int x,y;
	bool operator <(const inode &t)const{
		return val > t.val;
	}
}a[MAXN],b[MAXN];
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int anspos;
bool hasans;
bool ans[1010][1010];
int lef;
void dfs(int index){
	if (lef == 0) return;
	int x = index/M;
	int y = index%M;
	if (ans[x][y]) return;
	ans[x][y] = true;
	lef--;
	for (int i = 0;i < 4;i++){
		int nx = x+dir[i][0];
		int ny = y+dir[i][1];
		if (nx >=0 && nx < N && ny >= 0 && ny < M && top(nx*M+ny) == top(index))dfs(nx*M+ny);
	}
}
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d%d%I64d",&N,&M,&K))){
		int n = N*M;
		for (int i = 0;i < n;i++){
			scanf("%d",&a[i].val);
			a[i].x = i/M;
			a[i].y = i%M;
			b[i] = a[i];
		}
		sort(a,a+n);
		for (int i = 0;i <= n;i++) cnt[i] = 1,father[i] = i;
		hasans = false;
		anspos = -1;
		for (int i = 0;i < n;i++){
			int x = a[i].x;
			int y = a[i].y;
			long long tmpcnt = cnt[top(a[i].x*M+a[i].y)];
			for (int k = 0;k < 4;k++){
				int nx = x+dir[k][0];
				int ny = y+dir[k][1];
				int j = nx*M+ny;
				if (nx>=0 && nx < N && ny>=0 && ny < M && b[j].val >= a[i].val){
					int fx = top(a[i].x*M+a[i].y);
					int fy = top(j);
					if (fx != fy){
						father[fy] = fx;
						cnt[fx] += cnt[fy];
						tmpcnt = max(tmpcnt,(long long)cnt[fx]);
					}
				}
			}
			if (K%a[i].val == 0){
				if (tmpcnt*a[i].val >= K){
					anspos = a[i].x*M+a[i].y;
					hasans = true;
					break;
				}
			}
		}
		if (!hasans) 	puts("NO");
		else{
			puts("YES");
			memset(ans,false,sizeof(ans));
			lef = K/b[anspos].val;
			dfs(anspos);
			for (int i = 0;i < N;i++){
				for (int j = 0;j < M;j++){
					if (ans[i][j]) printf("%d ",b[anspos].val);
					else printf("%d ",0);
				}
				putchar('\n');
			}
		}
	}
	return 0;
}
