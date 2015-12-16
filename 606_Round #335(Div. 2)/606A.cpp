#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int mo,le;
int a[10],b[10];
int main(){
    //ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin); //++++You fool, comment this line++++//
    //while(T--){
        mo = le = 0;
        scanf("%d%d%d",a,a+1,a+2);
        scanf("%d%d%d",b,b+1,b+2);
        for (int i = 0;i < 3;i++){
            if (a[i] < b[i]) le += b[i]-a[i];
            else mo += (a[i]-b[i])/2;
        }
        if (mo < le) puts("No");
        else puts("Yes");
    //}
    return 0;
}
