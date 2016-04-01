#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;

struct cellNode{
	int r,c,val;
	bool operator <(const cellNode &t)const{
		return val < t.val;
	}
};
cellNode cell[MAXN];
int ans[MAXN];
int colval[MAXN],rowval[MAXN];
int collab[MAXN],rowlab[MAXN];
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d%d",&N,&M))){
		memset(cell,0,sizeof(cell));
		memset(colval,0,sizeof(colval));
		memset(rowval,0,sizeof(rowval));
		memset(collab,0,sizeof(collab));
		memset(rowlab,0,sizeof(rowlab));
		int ccnt = 0;
		for (int i = 0;i < N;i++)
			for (int j = 0;j < M;j++){
				cell[ccnt].r = i;
				cell[ccnt].c = j;
				scanf("%d",&cell[ccnt].val);
				ccnt++;
			}
		sort(cell,cell+ccnt);
		for (int i = 0;i < ccnt;i++){
			int r = cell[i].r,c = cell[i].c,val = cell[i].val;
			int tlab = 0;
			if (rowval[r] == val) tlab = rowlab[r];
			else tlab = rowlab[r]+1;
			if (colval[c] == val) tlab = max(tlab,collab[c]);
			else tlab = max(tlab,collab[c]+1);
			rowval[r] = colval[c] = val;
			rowlab[r] = collab[c] = tlab;
			ans[r*M+c] = tlab;
			if (val != cell[i+1].val){
				bool changed = true;
				while(changed){
					changed = false;
					for (int j = i;cell[j].val == cell[i].val;j--){
						if (ans[cell[j].r*M+cell[j].c] < max(rowlab[cell[j].r],collab[cell[j].c])){
							ans[cell[j].r*M+cell[j].c] = max(rowlab[cell[j].r],collab[cell[j].c]);
							rowlab[cell[j].r] = collab[cell[j].c] = ans[cell[j].r*M+cell[j].c];
							changed = true;
						}
					}
				}
			}
		}
		for (int i = 0;i < N;i++){
			for (int j = 0;j < M;j++){
				printf("%d ",ans[i*M+j]);
			}
			printf("\n");
		}
	}
	return 0;
}
