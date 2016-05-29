#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int a[MAXN];
map<long long,int> s;
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d",&N))){
		for(int i = 0;i < N;i++) scanf("%d",a+i);
		long long sum=0;
		int cnt=0;
		int st = 0;
		s.clear();
		s[0]=1;
		for (int i = 0;i < N;i++){
			sum += a[i];
			if (s.find(sum)==s.end()) s[sum] = 1;
			else s[sum]++;
		}
		for (map<long long,int>::iterator it = s.begin();it!=s.end();it++){
			if (it->first==0) cnt = max(cnt,it->second-1);
			else cnt = max(cnt,it->second);
		}
		printf("%d\n",N-cnt);
	}
	return 0;
}
