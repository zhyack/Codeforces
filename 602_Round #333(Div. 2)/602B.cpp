#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;

struct qnode{
    int val,num;
}tmp;

deque <qnode> qmax,qmin;

int main(){
    while(T-- && ~(scanf("%d",&N))){
        qmax.clear();
        qmin.clear();
        int ans = 0;
        int l = 1;
        for (int i = 1;i <= N;i++){
            scanf("%d",&tmp.val);
            tmp.num = i;
            while(!qmax.empty() && tmp.val > qmax.back().val) qmax.pop_back();
            qmax.push_back(tmp);
            while(!qmin.empty() && tmp.val < qmin.back().val) qmin.pop_back();
            qmin.push_back(tmp);
            while(qmax.front().val-qmin.front().val > 1){
                if (qmax.front().num > qmin.front().num){
                    l = max(l,qmin.front().num+1);
                    qmin.pop_front();
                }
                else if (qmax.front().num < qmin.front().num){
                    l = max(l,qmax.front().num+1);
                    qmax.pop_front();
                }
                else{
                    l = max(l,qmax.front().num+1);
                    qmin.pop_front(), qmax.pop_front();
                }
            }
            ans = max(ans,i-l+1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
