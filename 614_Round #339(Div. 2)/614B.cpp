#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int zerocnt;
string notzero;
string s;
bool zero;

bool cvalid(string s){
    if (s[0] != '1') return false;
    int n = s.length();
    int cnt = 0;
    for (int i = 0;i < n;i++) if (s[i] == '0') cnt++;
    if (cnt != n-1) return false;
    return true;
}

int main(){
    //ios_base::sync_with_stdio(0);

    freopen("input.txt", "r", stdin);   //++++You fool, comment this line++++//
    cin >> N;
    zero = false;
    notzero = "1";
    zerocnt = 0;
    for (int i = 0;i < N;i++){
        cin >> s;
        if (s == "0") zero  = true;
        else if (cvalid(s)) zerocnt += s.length()-1;
        else notzero = s;
    }
    if (zero){
        cout << "0" << endl;
        return 0;
    }
    	cout << notzero;
    for (int i = 0;i < zerocnt;i++) cout << 0;
    cout << endl;
    return 0;
}
