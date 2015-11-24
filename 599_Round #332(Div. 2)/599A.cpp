#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
long long d1,d2,d3;
int main(){
	while(T-- && ~(scanf("%I64d%I64d%I64d",&d1,&d2,&d3))){
		printf("%I64d\n",min(d1+d1+d2+d2,min(d1+d3+d1+d3,min(d1+d3+d2,d2+d3+d2+d3))));
	}
	return 0;
}
