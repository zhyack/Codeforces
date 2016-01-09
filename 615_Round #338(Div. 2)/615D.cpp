#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
const int MOD = 1e9+7;
const double eps = 1e-10;
int N,M,T = MOD,Cases = 0;

long long quickpow(long long n, long long m, long long mod = 0){
    if(m < 0) return 0;
    long long ans = 1;
    long long k = n;
    while(m){
        if(m & 1) {
            ans *= k;
            if(mod) ans %= mod;
        }
        k *= k;
        if(mod) k %= mod;
        m >>= 1;
    }
    return ans;
}

int a[MAXN],b[MAXN],c[MAXN];

int main(){
    //ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin); //++++You fool, comment this line++++//
    while(T-- && ~(scanf("%d",&N))){
        for (int i = 0;i < N;i++) scanf("%d",a+i);
        sort(a,a+N);
        memset(c,0,sizeof(c));
        b[0] = a[0];
        c[0] = 1;
        int n= 0;
        for (int i = 1;i < N;i++){
            if (a[i] != a[i-1]) {
                n++;
                b[n] = a[i];
            }
            c[n]++;
        }
        n++;
        long long pre = 1;
        long long ans = 1;
        for (int i = 0;i < n;i++){
            long long mi = pre;
            for (int j = i+1;j < n;j++)
                mi = (mi * (c[j]+1))%(MOD-1);
            pre  = (pre*(c[i]+1))%(MOD-1);
            for (int k = 1;k <= c[i];k++)
                ans = ans * quickpow(quickpow(b[i],k,MOD) %MOD, mi,MOD) % MOD;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
