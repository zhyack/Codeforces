#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
long long N,M,K,T = INF,Cases = 0;

int main(){
    //ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin); //++++You fool, comment this line++++//
    while(T-- && ~(scanf("%I64d%I64d%I64d",&N,&M,&K))){
        long long now = 1;
        int cnt = 0;
        while(now <= M/K){
            if (now >= N) printf("%I64d ",now),cnt++;
            now = now * K;
        }
        if (now >= N) printf("%I64d ",now),cnt++;
        if (cnt == 0) puts("-1");
        else putchar('\n');
    }
    return 0;
}
