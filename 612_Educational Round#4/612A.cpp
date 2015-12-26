#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,P,Q,T = INF,Cases = 0;
string s;
int a,b;
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin);	//++++You fool, comment this line++++//
	while(T-- && cin >> N >> P >> Q){
		cin >> s;
		b = -1;
		for (a = 0;a <= N/P;a++)
			if ((N-a*P)%Q == 0){
				b = (N-a*P)/Q;
				break;
			}
		if (b == -1){
			cout << b << endl;
			continue;
		}
		else{
			cout << a+b << endl;
			for (int i = 0;i < a;i++) cout << s.substr(i*P,P) << endl;
			for (int i = 0;i < b;i++)
				cout << s.substr(a*P+i*Q,Q)<< endl;
		}
	}
	return 0;
}
