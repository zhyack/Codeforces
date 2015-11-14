#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
long long n,ans;
long long a[60];
int main(){
    a[0] = 1;
    for (int i = 1;i < 60;i++) a[i] = a[i-1]<<1;
    scanf("%d",&T);
    while(T-- && ~(scanf("%I64d",&n))){
        ans = n*(n+1)/2+2;
        int j;
        for (j = 0;j < 60 && a[j] <= n;j++) ;
        ans -= a[j]*2;
        printf("%I64d\n",ans);
    }
    return 0;
}
