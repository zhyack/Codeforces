#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int arr[MAXN];
char a[MAXN],b[MAXN];
long long zeros[MAXN],ones[MAXN];
int main(){
    //ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin); //++++You fool, comment this line++++//
    //scanf("%d",&T);
    while(T-- && gets(a+1) && gets(b+1)){
        a[0] = b[0] = '?';
        N = strlen(a)-1;
        M = strlen(b)-1;

        memset(ones,0,sizeof(ones));
        memset(zeros,0,sizeof(zeros));
        for (int i = 1;i <= M;i++){
            if (b[i] == '1') ones[i] = ones[i-1]+1,zeros[i] = zeros[i-1];
            else ones[i] = ones[i-1],zeros[i] = zeros[i-1]+1;
        }
        int sp = M-N;
        long long ans = 0;
        for (int i = 1;i <= N;i++){
            int j = i+sp;
            if (a[i] == '0') ans+=ones[j]-ones[i-1];
            else ans += zeros[j]-zeros[i-1];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
