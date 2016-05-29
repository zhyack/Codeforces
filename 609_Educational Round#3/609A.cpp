#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int a[MAXN];
int main(){
    //ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin); //++++You fool, comment this line++++//
    while(T-- && ~(scanf("%d%d",&N,&M))){
        for (int i = 0;i < N;i++) scanf("%d",a+i);
        sort(a,a+N);
        int sum = 0;
        for (int i = N-1;i>=0;i--){
            sum += a[i];
            if (sum >= M){
                printf("%d\n",N-i);
                break;
            }
        }
    }
    return 0;
}
