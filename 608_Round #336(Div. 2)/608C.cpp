#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
struct beacons{
    int a,b;
    bool operator <(const beacons &B) const{
        return a < B.a;
    }
}s[MAXN];
int dp[MAXN];
int main(){
    //ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin); //++++You fool, comment this line++++//
    while(T-- && ~(scanf("%d",&N))){
        for (int i = 0;i < N;i++) scanf("%d%d",&s[i].a,&s[i].b);
        sort(s,s+N);
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for (int i = 0;i < N;i++){
            beacons tmp;
            tmp.a = s[i].a-s[i].b-1;
            int pos = upper_bound(s,s+N,tmp)-s;
            if (pos == 0) dp[i] = 1;
            else dp[i] = dp[pos-1]+1;
            ans = max(ans,dp[i]);
        }
        printf("%d\n",N-ans);
    }
    return 0;
}
