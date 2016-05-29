#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
char s[MAXN];
int cnt[26];
int main(){
    while(T-- && gets(s)){
        N = strlen(s);
        memset(cnt,0,sizeof(cnt));
        for (int i = 0;i < N;i++) cnt[s[i]-'a']++;
        for (int i = 0;i < 26;i++){
            if (cnt[i]&1){
                for (int j = 25;j > i;j--){
                    if (cnt[j]&1){
                        cnt[i]++;
                        cnt[j]--;
                        break;
                    }
                }
            }
        }
        int l = 0,r = N-1;
        for (int i = 0;i < 26;i++) for (int j = 0;j < cnt[i]/2;j++) s[l++] = s[r--] = 'a'+i;
        for (int i = 0;i < 26;i++) if (cnt[i]&1) s[l++] = 'a'+i;
        puts(s);
    }
    return 0;
}
