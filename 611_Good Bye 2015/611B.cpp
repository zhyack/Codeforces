#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
unsigned long long N,M,T = INF,Cases = 0;

int main(){
    //ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);   //++++You fool, comment this line++++//
    while(T-- && ~(scanf("%I64d%I64d",&N,&M))){
        unsigned long long p,q,ans = 0;
        p = 1;
        while(p <= M*2){
            q = 1;
            while(q+q-1 < p){
                unsigned long long x = p^q;
                if (x>=N && x <= M) ans++;
                q <<= 1;
            }
            p = (p<<1)+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
