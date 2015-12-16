#include <bits/stdc++.h>
using namespace std;

const int MAXN = 550;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int a0,b0;
bool g[MAXN][MAXN];
char s[100020];
int overcnt;
int ans[100020];
int main(){
    //ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);   //++++You fool, comment this line++++//
    while(T-- && ~(scanf("%d%d%d%d",&N,&M,&a0,&b0))){
        getchar();
        gets(s);
        int n = strlen(s);
        int a = a0,b = b0;
        memset(g,false,sizeof(g));
        g[a0][b0] = true;
        overcnt = 1;
        ans[0] = 1;
        for (int i = 0;i < n;i++){
            if (s[i] == 'U' && a>1) a--;
            else if (s[i] == 'D' && a<N) a++;
            else if (s[i] == 'L' && b>1) b--;
            else if (s[i] == 'R' && b<M) b++;
            if (g[a][b]) ans[i+1] = 0;
            else ans[i+1] = 1,overcnt++;
            g[a][b] = true;
        }
        ans[n] += N*M-overcnt;
        for (int i = 0;i <= n;i++) printf("%d ",ans[i]);
        putchar('\n');
    }
    return 0;
}
