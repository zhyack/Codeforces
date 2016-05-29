#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int a[MAXN];
int main(){
    //ios_base::sync_with_stdio(0);

   // freopen("input.txt", "r", stdin);   //++++You fool, comment this line++++//
    while(T-- && ~(scanf("%d",&N))){
        int sum = 0;
        for (int i = 0;i < N;i++){
            scanf("%d",a+i);
            sum += a[i];
        }
        sort(a,a+N);
        int per = sum / N,om = sum%N;
        int ans = 0;
        for (int i = N-1;i >= 0;i--){
            if (om){
                om--;
                if (a[i] > per+1) ans += a[i]-per-1;
            }
            else{
                if (a[i] > per) ans += a[i]-per;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
