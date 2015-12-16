#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int pos[MAXN];
int a[MAXN];
int main(){
    //ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);   //++++You fool, comment this line++++//
    while(T-- && ~(scanf("%d",&N))){
        for (int i = 0;i < N;i++) scanf("%d",a+i);
        for (int i = 0;i < N;i++) pos[a[i]] = i+1;
        int cnt = 0;
        int ans = 0;
        pos[0] = 0;
        for (int i = 1;i <= N+1;i++){
            if (pos[i] > pos[i-1]) cnt++;
            else{
                if (cnt > ans) ans = cnt;
                cnt = 1;
            }
        }
        printf("%d\n",N-ans);
    }
    return 0;
}
