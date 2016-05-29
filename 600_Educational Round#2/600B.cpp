#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;

int a[MAXN],b[MAXN],c[MAXN];

int main(){
    while(T-- && ~(scanf("%d%d",&N,&M))){
        for (int i = 0;i < N;i++) scanf("%d",a+i);
        for (int i = 0;i < M;i++) scanf("%d",b+i);
        sort(a,a+N);
        for (int i = 0;i < M;i++) c[i] = upper_bound(a,a+N,b[i])-a;
        for (int i = 0;i < M;i++) printf("%d ",c[i]);
        putchar('\n');
    }
    return 0;
}
