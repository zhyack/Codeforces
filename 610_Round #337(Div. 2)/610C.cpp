#include <bits/stdc++.h>
using namespace std;

const int MAXN = 610;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
char g[MAXN][MAXN];
int main(){
    //ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin); //++++You fool, comment this line++++//
    g[0][0] = '+';
    for (int k = 1;k <= 9;k++){
        int st = (1<<(k-1));
        int en = (1<<k);
        for (int i = st;i < en;i++)
            for (int j = 0;j < st;j++)
                g[i][j] = g[j][i] = g[i-st][j];
        for (int i = st;i < en;i++)
            for (int j = st;j < en;j++)
                if (g[i-st][j-st] == '+') g[i][j] = '*';
                else g[i][j] = '+';
    }
    while(T-- && ~(scanf("%d",&N))){
        int st = 0,en = (1<<N);
        for (int i = st;i < en;i++){
            for (int j = st;j < en;j++) putchar(g[i][j]);
            putchar('\n');
        }
    }
    return 0;
}
