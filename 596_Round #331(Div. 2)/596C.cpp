#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
struct tpoint{
    int x,y;
    bool operator <(const tpoint &B)const{
        return x < B.x || x == B.x && y < B.y;
    }
}tp;
map<tpoint,int> mtp;
struct point{
    int x,y;
    bool operator <(const point &B)const{
        return y-x < B.y-B.x || y-x == B.y-B.x && (x < B.x || x == B.x && y < B.y);
    }
}p[MAXN];
point ans[MAXN];
struct wp{
    int w;
    int n;
}a[MAXN];
int num[MAXN];

bool cmpwp(wp a,wp b){
    return a.w < b.w || a.w == b.w && a.n < b.n;
}
int main(){
    while(T-- && ~(scanf("%d",&N))){
        for (int i = 0;i < N;i++) scanf("%d%d",&p[i].x,&p[i].y);
        for (int i = 0;i < N;i++) scanf("%d",&a[i].w),a[i].n = i;
        sort(p,p+N);
        sort(a,a+N,cmpwp);
        mtp.clear();
        for (int i = 0;i < N;i++){
            tp.x = p[i].x;
            tp.y = p[i].y;
            mtp[tp] = i;
        }
        bool ok = true;
        for (int i = 0;i < N;i++){
            if (p[i].y-p[i].x != a[i].w){
                ok = false;
                puts("NO");
                break;
            }
            ans[a[i].n] = p[i];
            tp.x = p[i].x;
            tp.y = p[i].y;
            mtp[tp] = a[i].n;
            num[i] = a[i].n;
        }
        if (!ok) continue;
        for (int i = 0;i < N;i++){
            tp.x = p[i].x+1;
            tp.y = p[i].y;
            if (mtp.find(tp)!=mtp.end() && mtp[tp] < num[i]){
                ok = false;
                puts("NO");
                break;
            }
            tp.x = p[i].x;
            tp.y = p[i].y+1;
            if (mtp.find(tp)!=mtp.end() && mtp[tp] < num[i]){
                ok = false;
                puts("NO");
                break;
            }
        }
        if (!ok) continue;
        puts("YES");
        for (int i = 0;i < N;i++) printf("%d %d\n",ans[i].x,ans[i].y);
    }
    return 0;
}
