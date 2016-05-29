#include <bits/stdc++.h>
using namespace std;

const int MAXN = 440;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;


struct Edge{
    int to,dis;
};

vector<Edge> edge[MAXN];
int spfa[MAXN];
bool exist[MAXN];
queue<int> que;

void ClearMap(int n){
    memset(exist,false,sizeof(exist));
    for (int i = 0;i <= n;i++) edge[i].clear();
    while(!que.empty()) que.pop();
}
void InsertEdge(int x,int y,int c){
    Edge tmp;
    tmp.dis = c;
    tmp.to = y; edge[x].push_back(tmp);
    tmp.to = x; edge[y].push_back(tmp);//bidirectional edge
}
//REMEMBER to ClearMap(N) before SPFA(N,S)
void SPFA(int n,int s){
    que.push(s);
    fill(spfa,spfa+n+1,INF);//ctrl the INF
    spfa[s] = 0;
    exist[s] = true;
    while(!que.empty()){
        int x = que.front();
        que.pop();
        vector<Edge>::iterator it;
        for (it = edge[x].begin();it != edge[x].end();it++){
            int y = it->to;
            int z = it->dis;
            if (spfa[x]+z < spfa[y]){
                spfa[y] = spfa[x]+z;
                if (!exist[y]) {
                    que.push(y);
                    exist[y] = true;
                }
            }
        }
        exist[x] = false;
    }
}
//single source shortest path fast algorithm,may not perform well when graph looks like grids.

int x,y;
vector<int> train[440];
vector<int> bus[440];
bool g[440][440];

int main(){
    while(T-- && ~(scanf("%d%d",&N,&M))){
        for (int i = 0;i < N;i++) train[i].clear();
        for(int i = 0;i < N;i++) bus[i].clear();
        memset(g,false,sizeof(g));
        for (int i = 0;i < M;i++){
            scanf("%d%d",&x,&y);
            g[x-1][y-1] = g[y-1][x-1] = true;
        }
        ClearMap(N);
        for (int i = 0;i < N;i++)
            for (int j = 0;j < i;j++){
                if (i != j && g[i][j] ^ g[0][N-1]) InsertEdge(i,j,1);
            }

        SPFA(N,0);
        if (spfa[N-1] == INF) puts("-1");
        else printf("%d\n",spfa[N-1]);
    }
    return 0;
}
