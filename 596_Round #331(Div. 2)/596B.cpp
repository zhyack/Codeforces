#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
long long a,b[MAXN];
long long ans;
int main(){
    while(T-- && ~(scanf("%d",&N))){
        for (int i = 0;i < N;i++) scanf("%I64d",b+i);
        a = 0;
        ans = 0;
        for (int i = 0;i < N;i++){
            if (a != b[i]) ans += (a-b[i])>=0?(a-b[i]):(b[i]-a);
            a = b[i];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
