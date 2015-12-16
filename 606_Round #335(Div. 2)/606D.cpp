#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int nodecnt;
int ny,nx;
struct edgenode{
	int w;
	int in;
	int no;
}edge[MAXN];
bool cmp(edgenode A,edgenode B){
	return A.w < B.w || A.w == B.w && A.in > B.in;
}
bool ok;
int ansx[MAXN],ansy[MAXN];
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin);	//++++You fool, comment this line++++//
	while(T-- && ~(scanf("%d%d",&N,&M))){
		for (int i = 0;i < M;i++) scanf("%d%d",&edge[i].w,&edge[i].in),edge[i].no = i;
		sort(edge,edge+M,cmp);
		nodecnt = 1;
		ny = 2;
		nx = 0;
		ok = true;
		for (int i = 0;i < M;i++){
			int no = edge[i].no;
			if (edge[i].in){
				nodecnt++;
				ansx[no] = nodecnt,ansy[no] = nodecnt-1;
			}
			else{
				if (ny >= nodecnt){
					puts("-1");
					ok = false;
				}
				ansx[no] = nx+1,ansy[no] = ny+1;
				nx--;
				while (nx < 0){
					ny++;
					nx = ny-2;
				}
			}
			if (!ok) break;
		}
		if (ok)	for (int i = 0;i < M;i++) printf("%d %d\n",ansx[i],ansy[i]);
	}
	return 0;
}
