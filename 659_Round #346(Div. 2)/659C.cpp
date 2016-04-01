#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
set<int> s;
int x;
vector<int> ans;
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d%d",&N,&M))){
		s.clear();
		ans.clear();
		for (int i = 0;i < N;i++){
			scanf("%d",&x);
			s.insert(x);
		}
		x = 1;
		while(M>=x){
			if (s.find(x) == s.end()){
				ans.push_back(x);
				M-=x;
			}
			x++;
		}
		printf("%d\n",ans.size());
		for (vector<int>::iterator it = ans.begin();it != ans.end();it++) printf("%d ",*it);
		putchar('\n');
	}
	return 0;
}
