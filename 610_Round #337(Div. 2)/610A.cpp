#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;

int main(){
    //ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);   //++++You fool, comment this line++++//
    while(T-- && ~(scanf("%d",&N))){
        if (N & 1){
            puts("0");
            continue;
        }
        else{
            N/=2;
            printf("%d\n",(N-1)/2);
        }
    }
    return 0;
}
