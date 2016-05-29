#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;

char s[MAXN];
char ans[MAXN];
int pos[MAXN];
int l,r,k;
int main(){
    if(T-- && gets(s)){
        scanf("%d",&M);
        N = strlen(s);
        for (int i = 0;i < N;i++) pos[i] = i+1;
        while(M--){
            scanf("%d%d%d",&l,&r,&k);
            for (int i = 0;i < N;i++)
                if (pos[i]>=l && pos[i] <= r) pos[i] = (pos[i]-l+k)%(r-l+1)+l;
        }
        memset(ans,0,sizeof(ans));
        for (int i = 0;i < N;i++) ans[pos[i]-1] = s[i];
        puts(ans);
    }
    return 0;
}
