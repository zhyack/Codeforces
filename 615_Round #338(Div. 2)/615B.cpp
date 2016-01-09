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
bool visited[MAXN];
void dfs(int x,long long l){
    if (l*d[x] > ans) ans = l*d[x];
    visited[x] = true;
    for (vector<int>::iterator it = edge[x].begin();it != edge[x].end();it++){
        if (!visited[*it] && *it > x) dfs(*it,l+1);
    }
}
int main(){
    //ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin); //++++You fool, comment this line++++//
    while(T-- && ~(scanf("%d%d",&N,&M))){
        memset(visited,false,sizeof(visited));
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
        for (int i = 0;i <= N;i++) sort(edge[i].begin(),edge[i].end());
        for (int i = 1;i <= N;i++){
            if (!visited[i]) dfs(i,1);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
