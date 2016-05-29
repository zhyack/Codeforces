#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2210;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
char s[MAXN],s1[MAXN],s2[MAXN],tmp[MAXN];
int ans[MAXN][2];
int anscnt;
int ll,rr;

int next[MAXN];

void findNext(char *strB,int next[]){
	int M = strlen(strB);
	int j = -1;
	next[0] = -1;
	for (int i = 1;i < M;i++){
		while(j>=0 && strB[j+1]!=strB[i]) j = next[j];
		if (strB[j+1] == strB[i]) j++;
		next[i] = j;
	}
}

int kmp(char *strB,char *strA,int next[]){
	findNext(strB,next);
	int N = strlen(strA);
	int M = strlen(strB);
	if (M > N) return -1;
	int j = -1;
	for (int i = 0;i < N;i++){
		while(j>=0 && strB[j+1]!=strA[i]) j = next[j];
		if (strB[j+1] == strA[i]) j++;
		if (j == M-1) {
			j = next[j];
			return i;
		}
	}
	return -1;
}
//O(N+M) kmp algorithm to get whether strB is a substring of strA
//and how many they are.

bool check(int st,int en){
	int n = en-st+1;
	for (int i = 0;i < n;i++) tmp[i] = s[st+i];
	tmp[n] = 0;
	int t;
	t = kmp(tmp,s1,next);
	if (~t){
		rr = t;
		ll = t-n+1;
		return true;
	}
	t = kmp(tmp,s2,next);
	if (~t){
		rr = N-t-1;
		ll = N-(t-n+1)-1;
		return true;
	}
	return false;
}

int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin);	//++++You fool, comment this line++++//
	while(T-- && ~(scanf("%s%s",s1,s))){
		N = strlen(s1);
		M = strlen(s);
		for (int i = 0;i < N;i++) s2[i] = s1[N-i-1];
		s2[N] = 0;
		bool ok = true;
		for (int i = 0;i < M;i++){
			bool exist = false;
			for (int j = 0;j < N;j++){
				if (s1[j] == s[i]){
					exist = true;
					break;
				}
			}
			if (!exist){
				ok = false;
				break;
			}
		}
		if (!ok){
			puts("-1");
			continue;
		}

		int st = 0;
		memset(ans,0,sizeof(ans));
		anscnt = 0;
		while(st < M){
			int l = st,r = M-1;
			while(l < r){
				int m = (l+r+1)/2;
				if (check(st,m)) l = m;
				else r = m-1;
			}
			check(st,l);
			ans[anscnt][0] = ll+1;
			ans[anscnt][1] = rr+1;
			anscnt++;
			st = l+1;
		}
		printf("%d\n",anscnt);
		for (int i = 0;i < anscnt;i++) printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}
