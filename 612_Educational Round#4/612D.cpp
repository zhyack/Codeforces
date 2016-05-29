#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
map<int,int> mii;
int l[MAXN],r[MAXN];
int a[MAXN*2];
int n;
int c[MAXN*2];
int po[MAXN*2];
int ans[MAXN][2];
int anscnt;

int lowbit(int x){
	return x&(-x);
}

void add(int x,int val){
	while(x < MAXN*2){
		c[x]+=val;
		x += lowbit(x);
	}
}

int sum(int x){
	int ret = 0;
	while(x > 0){
		ret += c[x];
		x -= lowbit(x);
	}
	return ret;
}

int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin);	//++++You fool, comment this line++++//
	while(T-- && ~(scanf("%d%d",&N,&M))){
		for (int i = 0;i < N;i++){
			scanf("%d%d",l+i,r+i);
			a[i*2] = l[i];
			a[i*2+1] = r[i];
		}
		sort(a,a+N*2);
		n = unique(a,a+N*2)-a;
		mii.clear();
		memset(c,0,sizeof(c));
		memset(po,0,sizeof(po));
		for (int i = 0;i < n;i++) mii[a[i]] = i+1;
		for (int i = 0;i < N;i++){
			l[i] = mii[l[i]],r[i] = mii[r[i]];
			po[r[i]]++;
			add(l[i],1);
			add(r[i],-1);
		}
		int p = 1,q;
		anscnt = 0;
		while(p <= n){
			int seg = sum(p);
			if (seg >= M){
				q = p;
				while(seg >= M){
					q++;
					seg = sum(q);
				}
				ans[anscnt][0] = p-1;
				ans[anscnt][1] = q-1;
				anscnt++;
				p = q+1;
			}
			else if (seg+po[p] >= M){
				ans[anscnt][0] = ans[anscnt][1] = p-1;
				anscnt++;
				p++;
			}
			else p++;
		}
		printf("%d\n",anscnt);
		for (int i = 0;i < anscnt;i++) printf("%d %d\n",a[ans[i][0]],a[ans[i][1]]);
	}
	return 0;
}
