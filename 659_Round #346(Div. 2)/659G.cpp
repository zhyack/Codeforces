#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int h[MAXN];
long long v1,v2,ans;
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d",&N))){
		for (int i = 1;i <= N;i++) scanf("%d",h+i);
		h[0] = 1;
		v1 = 1, v2 = 1;
		ans = 0;
		for (int i = 1;i <= N;i++){
			if (h[i-2]>h[i-1]) h[i-2] = h[i-1];
			int r = min(h[i],h[i-1])-1;
			long long tv1 = 0,tv2 = 0;
			if (r < h[i-2]) tv1 = (v1*r+1)%INF;
			else tv1 = (v1*(h[i-2]-1)%INF+v2*(r-h[i-2]+1)%INF+1)%INF;
			if (h[i] > h[i-1]) tv2 = 1;

			if (h[i] > h[i-1])  ans = (ans+tv2*(h[i]-h[i-1])%INF)%INF;
			ans = (ans + tv1*(min(h[i],h[i-1])-1)%INF)%INF;
			v1 = tv1,	 v2 = tv2;
		}
		printf("%d\n",ans);
	}
	return 0;
}
