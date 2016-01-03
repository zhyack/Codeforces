#include <bits/stdc++.h>
using namespace std;

const int MAXN = 510;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,K,T = INF,Cases = 0;
char g[MAXN][MAXN];
int heng[MAXN][MAXN];
int shu[MAXN][MAXN];
int tmp[MAXN][MAXN];
int main(){
    //ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin); //++++You fool, comment this line++++//
    while(T-- && ~(scanf("%d%d",&N,&M))){
        memset(g,'#',sizeof(g));
        getchar();
        for (int i = 1;i <= N;i++) gets(g[i]+1);
        memset(tmp,0,sizeof(tmp));
        memset(heng,0,sizeof(heng));
        memset(shu,0,sizeof(shu));
        for (int i = 1;i <= N;i++)
            for (int j = 1;j <= M;j++)
                if (g[i][j] == '.' && g[i][j-1] == '.') tmp[i][j] = tmp[i][j-1]+1;
                else tmp[i][j] = tmp[i][j-1];
        for (int i = 1;i <= N;i++)
            for (int j = 1;j <= M;j++)
                heng[i][j] = heng[i-1][j]+tmp[i][j];
        memset(tmp,0,sizeof(tmp));
        for (int i = 1;i <= N;i++)
            for (int j = 1;j <= M;j++)
                if (g[i][j] == '.' && g[i-1][j] == '.') tmp[i][j] = tmp[i-1][j]+1;
                else tmp[i][j] = tmp[i-1][j];
        for (int i = 1;i <= N;i++)
            for (int j = 1;j <= M;j++)
                shu[i][j] = shu[i][j-1]+tmp[i][j];

        scanf("%d",&K);
        while(K--){
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            int ans = 0;
            if (a+1 <= c){
                a++;
                ans += shu[c][d]+shu[a-1][b-1]-shu[a-1][d]-shu[c][b-1];
                a--;
            }
            if (b+1 <= d){
                b++;
                ans += heng[c][d]+heng[a-1][b-1]-heng[a-1][d]-heng[c][b-1];
                b--;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
