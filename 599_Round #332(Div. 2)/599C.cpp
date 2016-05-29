#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;

int h[MAXN];
int lmax[MAXN],rmin[MAXN];

int main(){
    while(T-- && ~(scanf("%d",&N))){
        for (int i = 0;i < N;i++) scanf("%d",h+i);
        if (N == 1){
            puts("1");
            continue;
        }
        memset(lmax,0,sizeof(lmax));
        memset(rmin,0,sizeof(rmin));
        int ans = 0;
        lmax[0] = h[0];
        for (int i = 1;i < N;i++) lmax[i] = max(lmax[i-1],h[i-1]);
        rmin[N-1] = h[N-1];
        for (int i = N-2;i > 0;i--) rmin[i] = min(rmin[i+1],h[i]);
        for (int i = 1;i < N;i++)   if (lmax[i] <= rmin[i]) ans++;
        printf("%d\n",ans+1);
    }
    return 0;
}
