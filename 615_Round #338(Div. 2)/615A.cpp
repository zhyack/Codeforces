#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
bool exist[MAXN];
int x;
int main(){
    //ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin); //++++You fool, comment this line++++//
    while(T-- && ~(scanf("%d%d",&N,&M))){
        memset(exist,false,sizeof(exist));
        for (int i = 0;i < N;i++){
            int n;
            scanf("%d",&n);
            while(n--){
                scanf("%d",&x);
                exist[x] = true;
            }
        }
        bool ans = true;
        for (int i = 1;i <= M;i++) ans = ans && exist[i];
        if (ans) puts("YES");
        else puts("NO");
    }
    return 0;
}
