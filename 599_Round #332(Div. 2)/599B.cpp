#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;

stack<int> s[MAXN];
bool mult;
bool ok;
int f[MAXN],b[MAXN],a[MAXN];
int main(){
    while(T-- && (~scanf("%d%d",&N,&M))){
        for (int i = 0;i <= N;i++)
            while(!s[i].empty()) s[i].pop();
        for (int i = 0;i < N;i++){
            scanf("%d",f+i);
            s[f[i]].push(i);
        }
        ok = true;
        mult = false;
        for (int i = 0;i < M;i++){
            scanf("%d",b+i);
            if (s[b[i]].empty()) ok = false;
            else if (s[b[i]].size()>1) mult = true;
            else a[i] = s[b[i]].top();
        }
        if (!ok) puts("Impossible");
        else if (mult) puts("Ambiguity");
        else{
            puts("Possible");
            for (int i = 0;i < M;i++) printf("%d ",a[i]+1);
            putchar('\n');
        }
    }
    return 0;
}
