#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;

long long lbound[MAXN],rbound[MAXN];
stack<long long> st;
long long h[MAXN];
long long l,r;

int main(){
	while(T-- && ~(scanf("%d%d",&N,&M))){
		for (int i = 0;i < N;i++) scanf("%I64d",h+i);
		for (int i = N-1;i > 0;i--) h[i] = abs(h[i]-h[i-1]);
		memset(lbound,0,sizeof(lbound));
		memset(rbound,0,sizeof(rbound));
		while(!st.empty()) st.pop();

		h[N] = INF;
		for (int i = 1;i <= N;i++){
			while(!st.empty() && h[st.top()]<h[i]){
				rbound[st.top()] = i-1;
				st.pop();
			}
			st.push(i);
		}
		st.pop();

		h[0] = INF;
		for (int i = N-1;i >=0;i--){
			while(!st.empty() && h[st.top()]<=h[i]){
				lbound[st.top()] = i+1;
				st.pop();
			}
			st.push(i);
		}
		st.pop();

		while(M--){
			scanf("%I64d%I64d",&l,&r);
			long long ans = 0;
			for (int i = l;i < r;i++)
				ans += h[i]*(i-max(lbound[i],l)+1)*(min(rbound[i],r-1)-i+1);
			printf("%I64d\n",ans);
		}
	}
	return 0;
}
