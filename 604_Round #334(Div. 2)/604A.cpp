#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int s[5] = {500,1000,1500,2000,2500};
int m[10],w[10];
int hs,hw;
int ans;
int main(){
    //ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);   //++++You fool, comment this line++++//
    for (int i = 0;i < 5;i++) scanf("%d",m+i);
    for (int i = 0;i < 5;i++) scanf("%d",w+i);
    for (int i = 0;i < 5;i++) ans += max(s[i]/10*3,s[i]-s[i]/250*m[i]-w[i]*50);
    scanf("%d%d",&hs,&hw);
    ans += hs*100-hw*50;
    printf("%d\n",ans);
    return 0;
}
