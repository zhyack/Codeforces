#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;

char g[MAXN][MAXN];
int R,C;
int qx[MAXN*100];
int qy[MAXN*100];
int visited[MAXN][MAXN];
int viscnt;
int ans[MAXN*MAXN];
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
void dfs(int x,int y){
    if (g[x][y] == '*'){
        ans[viscnt]++;
        return;
    }
    visited[x][y] = viscnt;
    for (int i = 0;i < 4;i++){
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if (visited[nx][ny] == 0 && g[x][y] != '+') dfs(nx,ny);
    }
}
int main(){
    while(T-- && ~(scanf("%d%d%d",&R,&C,&N))){
        memset(g,'+',sizeof(g));
        getchar();
        for (int i = 1;i <= R;i++) gets(g[i]+1);
        for (int i= 0;i < N;i++) scanf("%d%d",qx+i,qy+i);
        memset(visited,0,sizeof(visited));
        viscnt = 0;
        memset(ans,0,sizeof(ans));
        for (int i = 1;i <= R;i++)
            for (int j = 1;j <= C;j++)
                if (visited[i][j] == 0 && g[i][j] == '.'){
                    viscnt++;
                    dfs(i,j);
                }
        for (int i = 0;i < N;i++)   printf("%d\n",ans[visited[qx[i]][qy[i]]]);
    }
    return 0;
}
