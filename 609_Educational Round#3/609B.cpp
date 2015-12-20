#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int b[11];
int tmp;
int main(){
    //ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin); //++++You fool, comment this line++++//
    while(T-- && ~(scanf("%d%d",&N,&M))){
        memset(b,0,sizeof(b));
        for (int i = 0;i < N;i++){
            scanf("%d",&tmp);
            b[tmp]++;
        }
        int ans = 0;
        for (int i = 1;i <= M;i++)
            for (int j = i+1;j <= M;j++)
                ans += b[i]*b[j];
        printf("%d\n",ans);
    }
    return 0;
}
