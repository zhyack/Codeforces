#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;

string s,sub;
string a,b;

int main(){
    cin >> s;
    N = s.length();
    int p = 0;
    a = b = "";
    bool num = true;
    int st = 0;
    while(p <= N){
        if (p == N || s[p] == ',' || s[p] == ';'){
            if (st == p){
                b += ',';
            }
            else{
                sub = s.substr(st,p-st)+',';
                if (!num || num && sub[0] == '0' && sub.length() > 2) b+=sub;
                else a+=sub;
            }
            st = p+1;
            num = true;
        }
        else if (s[p] < '0' || s[p] > '9') num = false;
        p++;
    }
    if (a != "") a = "\""+a.substr(0,a.length()-1)+"\"";
    else a = "-";
    if (b != "") b = "\""+b.substr(0,b.length()-1)+"\"";
    else b = "-";
    cout << a << endl << b << endl;
    return 0;
}
