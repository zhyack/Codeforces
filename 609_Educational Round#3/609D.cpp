#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200020;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,K,S,T = INF,Cases = 0;

struct gadgets{
	int num;
	long long money;
}d[MAXN],p[MAXN],tmp;
int cla,dcnt,pcnt;
bool cmp(gadgets A,gadgets B){
	return A.money < B.money;
}
int a[MAXN],b[MAXN],dmin[MAXN],pmin[MAXN];
int ansdcnt,anspcnt;

bool check(int day){
	long long dminval = a[dmin[day]],pminval = b[pmin[day]];
	long long m = S;
	int dp = 0,pp = 0;
	ansdcnt = anspcnt = 0;
	while(dp+pp < K){
		if (dp < dcnt && pp < pcnt && d[dp].money*dminval <= p[pp].money*pminval){
			m-=d[dp].money*dminval;
			dp++;
		}
		else if (dp < dcnt && pp < pcnt){
			m-=p[pp].money*pminval;
			pp++;
		}
		else if (dp < dcnt){
			m-=d[dp].money*dminval;
			dp++;
		}
		else{
			m-=p[pp].money*pminval;
			pp++;
		}
		if (m < 0) return false;
	}
	ansdcnt = dp;
	anspcnt = pp;
	if (m >= 0) return true;
	else return false;
}

int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin);	//++++You fool, comment this line++++//
	while(T-- && ~(scanf("%d%d%d%d",&N,&M,&K,&S))){
		for (int i = 0;i < N;i++) scanf("%d",a+i);
		for (int i = 0;i < N;i++) scanf("%d",b+i);
		a[N] = b[N] = 0;
		dmin[0] = pmin[0] = 0;
		for (int i = 1;i <= N;i++){
			if (a[dmin[i-1]] > a[i]) dmin[i] = i;
			else dmin[i] = dmin[i-1];
			if (b[pmin[i-1]] > b[i]) pmin[i] = i;
			else pmin[i] = pmin[i-1];
		}
		dcnt = pcnt = 0;
		for (int i = 0;i < M;i++){
			scanf("%d%d",&cla,&tmp.money);
			tmp.num = i+1;
			if (cla == 1) d[dcnt++] = tmp;
			else p[pcnt++] = tmp;
		}
		sort(d,d+dcnt,cmp);
		sort(p,p+pcnt,cmp);

		int l = 0,r = N;
		while(l < r){
			int mid = (l+r)/2;
			if (check(mid)) r = mid;
			else l = mid+1;
		}
		if (l == N) puts("-1");
		else{
			printf("%d\n",l+1);
			check(l);
			for (int i = 0;i < ansdcnt;i++) printf("%d %d\n",d[i].num,dmin[l]+1);
			for (int i = 0;i < anspcnt;i++) printf("%d %d\n",p[i].num,pmin[l]+1);
		}
	}
	return 0;
}
