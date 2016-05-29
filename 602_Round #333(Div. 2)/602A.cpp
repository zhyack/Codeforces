#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
long long nx,bx,ny,by,x,y;
long long tmp;
int main(){
    while(T-- && ~(scanf("%I64d%I64d",&nx,&bx))){
        x = 0;
        for (int i = 0;i  < nx;i++){
            scanf("%I64d",&tmp);
            x = x*bx+tmp;
        }
        scanf("%I64d%I64d",&ny,&by);
        y = 0;
        for (int i = 0;i  < ny;i++){
            scanf("%I64d",&tmp);
            y = y*by+tmp;
        }
        if (x > y) puts(">");
        else if (x < y) puts("<");
        else puts("=");
    }
    return 0;
}
