#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
string s;
int l,r;
int main(){
    //ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);   //++++You fool, comment this line++++//
    cin >> N;
    cin >> s;
    int ans = 0;
    int cnt;
    char c;
    for (l = 1;l < N;l++) if (s[l] == s[l-1]) break;
    for (r = N-2;r >= l;r--) if (s[r] == s[r+1]) break;
    if (r < l) r = N-1;
    for (int i = l;i <= r;i++)
        if (s[i] == '0') s[i] = '1';
        else s[i] = '0';
    cnt = 1;
    for (int i = 1;i < N;i++){
        if (s[i] != c){
            c = s[i];
            cnt++;
        }
    }
    ans = max(ans,cnt);
    printf("%d\n",ans);
    return 0;
}
