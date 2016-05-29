#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;

int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	long long a,b,c;
	while(T-- && ~(scanf("%I64d%I64d%I64d",&a,&b,&c))){
		if (b==a || (b-a)*c>0 && abs(b-a)%abs(c)==0) puts("YES");
		else puts("NO");
	}
	return 0;
}
