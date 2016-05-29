#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int a[MAXN*2];
int main(){
    //ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin); //++++You fool, comment this line++++//
    while(T-- && ~(scanf("%d",&N))){
        int m = INF;
        for (int i = 0;i < N;i++){
            scanf("%d",a+i);
            a[N+i] = a[i];
            if (a[i] < m) m = a[i];
        }
        a[N*2] = 0;
        int l = 0,r = 0;
        long long ans = 0;
        while(l < N*2){
            if (a[l]>m){
                r = l;
                while(a[r]>m) r++;
                if (r-l>ans) ans = r-l;
                l = r;
            }
            else l++;
        }
        ans += (long long)(m)*(long long)(N);
        printf("%I64d\n",ans);
    }
    return 0;
}
