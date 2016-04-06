#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int a,b;
char s[MAXN];
long long tpre[MAXN*2];
int l,r,m;

bool check(int len){
	for (int r = 1;r <= len;r++){
		int l = len-r;
		int y = N+r,x = N-l+1;
		long long tmp = (min(r-1,l)+(l+r-1))*a+tpre[y]-tpre[x-1];
		if (M >= tmp) return true;
	}
	return false;
}

int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d%d%d%d",&N,&a,&b,&M))){
		getchar();
		gets(s);
		tpre[0] = 0;
		for (int i = 1;i <= N*2;i++){
			int j = (i-1)%N;
			if (s[j] == 'w') tpre[i] = b+1;
			else tpre[i] = 1;
			tpre[i]+=tpre[i-1];
		}
		if (tpre[1] > M){
			printf("%d\n",0);
			continue;
		}
		l = 1,r = N;
		while(l < r){
			m = (l+r+1)/2;
			if (check(m)) l=m;
			else r = m-1;
		}
		printf("%d\n",l);
	}
	return 0;
}
