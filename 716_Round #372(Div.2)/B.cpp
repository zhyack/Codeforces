#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;
const int INF = 1e9+7;
int N,M,T = INF;
int l,r;
char s[MAXN];
bool exist[30];
int main(){
	//freopen("input.txt","r",stdin);
	//scanf("%d",&T);
	while(~(scanf("%s",s)) && T--){
		l = r = 0;
		N = strlen(s);
		if (N<26){
			puts("-1");
			continue;
		}
		memset(exist,false,sizeof(exist));
		bool find = false;
		while(r < N){
			while(r<N && (s[r]=='?' or !exist[s[r]-'A'])){
				if (s[r]!='?') exist[s[r]-'A'] = true;
				r++;
			}
			if (r-l >= 26){
				find = true;
				break;
			}
			if (r>=N) break;
			while(s[l] != s[r]){
				if (s[l]!='?') exist[s[l]-'A'] = false;
				l++;
			}
			l++;r++;
		}
		if (find){
			r = l+26;
			memset(exist,false,sizeof(exist));
			for (int i = l;i < r;i++){
				if (s[i] != '?')
					exist[s[i]-'A'] = true;
			}
			stack<int> ss;
			while(!ss.empty()) ss.pop();
			for (int i = 0;i < 26;i++){
				if (!exist[i]) ss.push(i);
			}
			for (int i = l;i < r;i++){
				if (s[i] == '?'){
					s[i] = ss.top()+'A';
					ss.pop();
				}
			}
			for (int i = 0;i < N;i++){
				if (s[i] == '?') s[i] = 'A';
			}
			puts(s);
		}
		else puts("-1");
	}
	
	return 0;
}