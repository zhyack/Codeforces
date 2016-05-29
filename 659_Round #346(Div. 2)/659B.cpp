#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
struct member{
	string name;
	int score;
	bool operator <(const member &t)const{
		return score>t.score;
	}
}tmp;
vector<member> vm[MAXN];
char s[21];
int region,score;
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d%d",&N,&M))){
		for (int i = 0;i <= M;i++) vm[i].clear();
		for (int i = 0;i <N;i++){
			scanf("%s%d%d",s,&region,&score);
			tmp.name = s;
			tmp.score = score;
			vm[region].push_back(tmp);
		}
		for (int i = 1;i <= M;i++) sort(vm[i].begin(),vm[i].end());
		for (int i = 1;i <= M;i++){
			if (vm[i].size()>2 && vm[i][1].score == vm[i][2].score) puts("?");
			else printf("%s %s\n",vm[i][0].name.c_str(),vm[i][1].name.c_str());
		}
	}
	return 0;
}
