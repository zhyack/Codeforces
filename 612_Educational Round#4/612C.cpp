#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
char str[MAXN];
stack<int> s;
int ans;
int main(){
    //ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin); //++++You fool, comment this line++++//
    while(T-- && gets(str)){
        N = strlen(str);
        ans = 0;
        bool imp = false;
        while(!s.empty()) s.pop();
        for (int i= 0;i < N;i++){
            int cov = 0;
            if (str[i] == '(') cov = 1;
            else if (str[i] == '[') cov = 2;
            else if (str[i] == '{') cov = 3;
            else if (str[i] == '<') cov = 4;
            else if (str[i] == ')') cov = 5;
            else if (str[i] == ']') cov = 6;
            else if (str[i] == '}') cov = 7;
            else cov = 8;
            if (cov > 4){
                if (s.empty() || s.top()>4){
                    imp = true;
                    break;
                }
                else{
                    if (cov-4 != s.top()) ans++;
                    s.pop();
                }
            }
            else s.push(cov);
        }
        if (imp || !s.empty()){
            puts("Impossible");
            continue;
        }
        printf("%d\n",ans);
    }
    return 0;
}
