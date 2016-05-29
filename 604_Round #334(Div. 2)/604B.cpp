#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int a[MAXN];
bool visited[MAXN];
bool check(int s){
    int r = N-1;
    int cnt = 0;
    memset(visited,false,sizeof(visited));
    for (int i = 0;i < N;i++){
        if (!visited[i]){
            cnt++;
            visited[i] = true;
            while(r > i && a[r]+a[i] > s) r--;
            if (r > i) visited[r--] = true;
        }
    }
    return cnt <= M;
}
int main(){
    //ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);   //++++You fool, comment this line++++//
    while(T-- && ~(scanf("%d%d",&N,&M))){
        for (int i = 0;i < N;i++) scanf("%d",a+i);
        if (N == 1){
            printf("%d\n",a[0]);
            continue;
        }
        int l = a[N-1],r = a[N-1]+a[N-2];
        while(l < r){
            int mid = (l+r)/2;
            if (check(mid)) r = mid;
            else l = mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}
