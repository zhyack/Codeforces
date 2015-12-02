#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;
const int MOD = 1e9+7;
const double eps = 1e-10;
int N,M,T = MOD,Cases = 0;
long long p,k;
long long ans;
bool visited[MAXN];
long long loopcnt[MAXN];
int looplen;
void dfs(long long x){
    if (visited[x]) return;
    looplen++;
    visited[x] = true;
    dfs((x*k)%p);
}

long long ppp(long long x,long long y){
    long long ret = 1;
    while(y--) ret = (ret*x)%MOD;
    return ret;
}

int main(){
    //ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);   //++++You fool, comment this line++++//
    while(T-- && ~(scanf("%I64d%I64d",&p,&k))){
        if (k==0){
            ans = ppp(p,p-1);
            printf("%I64d\n",ans);
            continue;
        }
        memset(visited,false,sizeof(visited));
        memset(loopcnt,0,sizeof(loopcnt));
        for (int i = 1;i < p;i++){
            if (!visited[i]){
                looplen = 0;
                dfs((long long)i);
                loopcnt[looplen]++;
            }
        }
        if (k == 1) ans = p;
        else ans = 1;
        for (int i = 1;i < p;i++){
            ans = (ans * (ppp((((long long)i)*loopcnt[i]+1)%MOD,loopcnt[i]))) %MOD;
            //printf("%d,%d\n",i,loopcnt[i]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
