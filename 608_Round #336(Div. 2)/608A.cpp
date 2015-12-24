#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int arr[MAXN];
int f,t;
int main(){
    //ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin); //++++You fool, comment this line++++//
    //scanf("%d",&T);
    while(T-- && ~(scanf("%d%d",&N,&M))){
        memset(arr,0,sizeof(arr));
        for (int i = 0;i < N;i++){
            scanf("%d%d",&f,&t);
            arr[f] = max(arr[f],t);
        }
        int ans = 0;
        for (int i = M;i >= 0;i--){
            ans = max(arr[i],ans);
            ans++;
        }
        ans--;
        printf("%d\n",ans);
    }
    return 0;
}
