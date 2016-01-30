#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
struct disnode{
	long long dis;
	int dot;
	bool operator <(const disnode &A) const{
		return dis < A.dis;
	}
};
disnode dis1[MAXN],dis2[MAXN];
long long a,b,c,d,x,y;
long long dis(long long x1,long long y1,long long x2,long long y2){
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
bool exist[MAXN];
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d%I64d%I64d%I64d%I64d",&N,&a,&b,&c,&d))){
		for (int i = 1;i <= N;i++){
			scanf("%I64d%I64d",&x,&y);
			dis1[i].dis = dis(a,b,x,y);
			dis2[i].dis = dis(c,d,x,y);
			dis1[i].dot = dis2[i].dot = i;
		}
		dis1[0].dis = dis2[0].dis = 0;
		dis1[0].dot = dis2[0].dot = 0;
		sort(dis1,dis1+N+1);
		sort(dis2,dis2+N+1);
		memset(exist,false,sizeof(exist));
		int j = N;
		long long ans = 1e15;
		for (int i = 0;i <= N;i++){
			exist[dis1[i].dot] = true;
			while(j >= 0 && exist[dis2[j].dot]) j--;
			ans = min(ans,dis1[i].dis+dis2[j].dis);

		}
		printf("%I64d\n",ans);
	}
	return 0;
}
