#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
vector <int> edge[MAXN];
long long d[MAXN];
int x,y;
long long ans;
long long dp[MAXN];
int main(){
    //ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin); //++++You fool, comment this line++++//
    while(T-- && ~(scanf("%d%d",&N,&M))){
        memset(dp,false,sizeof(dp));
        for (int i = 0;i <= N;i++) edge[i].clear();
        memset(d,0,sizeof(d));
        ans = 0;
        for (int i = 0;i < M;i++){
            scanf("%d%d",&x,&y);
            edge[x].push_back(y);
            edge[y].push_back(x);
            d[x]++;
            d[y]++;
        }
        for (int i = 1;i <= N;i++){
            dp[i] = 1;
            for (vector<int>::iterator it = edge[i].begin();it != edge[i].end();it++)
                if (*it < i) dp[i] = max(dp[i],dp[*it]+1);
            ans = max(ans,dp[i]*d[i]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
