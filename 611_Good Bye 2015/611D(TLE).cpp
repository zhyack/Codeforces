#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
string s;
int diff[MAXN][MAXN];
struct dpNode{
	int x;
	int l,r;
	bool operator <(const dpNode &B)const{
		int l1 = l,r1 = r,l2 = B.l,r2 = B.r;
		if (l<0 || B.l < 0) return x < B.x || (x==B.x && l < B.l);
		else{
			bool cmp;
			int n1 = r1-l1,n2 = r2-l2;
			if (n1 < n2) cmp = true;
			else if (n1 > n2) cmp = false;
			else{
				int n = diff[l1][l2];
				if (n == -1 || n>n1 || s[l1+n]>s[l2+n])  cmp = false;
				else cmp = true;
			}
			return x < B.x || (x==B.x && cmp);
		}
	}
}dpn;
int dp[MAXN*MAXN];
dpNode node[MAXN*MAXN];
int nodecnt;
inline int MOD(int x){
	return x%INF;
}

int main(){
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);	//++++You fool, comment this line++++//
	cin >> N >> s;
	memset(diff,0xff,sizeof(diff));
	for (int i = N-1;i >= 0;i--)
		for (int j = N-1;j > i;j--)
			if (s[i] != s[j]) diff[j][i] = diff[i][j] = 0;
			else if (~diff[i+1][j+1]) diff[j][i] = diff[i][j] = diff[i+1][j+1]+1;
	nodecnt = 0;
	dpn.x = -1;
	dpn.l = dpn.r = -2;
	node[nodecnt] = dpn;
	dp[nodecnt++] = 0;
	dpn.x = -1;
	dpn.l = dpn.r = -1;
	node[nodecnt] = dpn;
	dp[nodecnt++] = 1;
	dpn.x = 0;
	dpn.l = 0;
	dpn.r = 0;
	node[nodecnt] = dpn;
	dp[nodecnt++] = 2;
//	for(int it = 0;it < nodecnt;it++){
//		cout << node[it].l << " " << node[it].x << " " << dp[it] << endl;
//	}
//	cout << "------" << endl;
	for (int i = 1;i < N;i++){
		for (int j = 0;j <= i;j++){
			int k = i-j;
			if (s[k] != '0'){
				dpn.l = -1;
				dpn.x = k-1;
				int l = lower_bound(node,node+nodecnt,dpn)-node-1;
				dpn.l = k;
				dpn.r = i;
				int r = lower_bound(node,node+nodecnt,dpn)-node-1;
				dpn.x = i;
				int pre =  nodecnt-1;
				node[nodecnt] = dpn;
				dp[nodecnt++] = MOD(MOD(dp[r]-dp[l])+dp[pre]);
//				for(int it = 0;it < nodecnt;it++){
//					cout << node[it].l << " " << node[it].x << " " << dp[it] << endl;
//				}
//				cout << "------" << endl;
			}
		}
	}
	dpn.l = -2;
	dpn.x = N-1;
	int l = lower_bound(node,node+nodecnt,dpn)-node-1;
	int r = nodecnt-1;
	int ans = MOD(dp[r]-dp[l]);
	cout << ans << endl;
	return 0;
}
