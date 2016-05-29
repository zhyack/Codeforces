#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int a[MAXN];
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d",&N))){
		int n = 0;
		for (int i = 0;i < N;i++){
			a[n] = 1;
			while(n && a[n] == a[n-1]){
				a[n-1]++;
				n--;
			}
			n++;
		}
		for (int i = 0;i < n;i++) printf("%d ",a[i]);
		putchar('\n');
	}
	return 0;
}
