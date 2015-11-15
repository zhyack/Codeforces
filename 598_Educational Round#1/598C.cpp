#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
const int INF = 1e9+7;
const double eps = 1e-10;

int N,M,T = INF,Cases = 0;

typedef struct Point
{
    long double x;
    long double y;
    int num;
}Point;
bool PointCmp(Point a,Point b)
{
    return atan2(a.x,a.y) < atan2(b.x,b.y);
}
Point p[MAXN];
double x,y;
int main(){
    while(T-- && ~(scanf("%d",&N))){
        for (int i= 0;i < N;i++){
            scanf("%lf%lf",&x,&y);
            p[i].x = x,p[i].y = y,p[i].num = i+1;
        }
        sort(p,p+N,PointCmp);
        p[N] = p[0];
        long double ang = 10*acos(-1.0);
        int a1 = -1,a2= -1;
        for (int i = 0;i < N;i++){
        	long double tmpang = atan2(p[i+1].x,p[i+1].y)-atan2(p[i].x,p[i].y);
        	if (tmpang < 0) tmpang += 2*acos(-1.0);
            if (tmpang < ang ){
                ang = tmpang;
                a1 = p[i].num;
                a2 = p[i+1].num;
            }
        }
        printf("%d %d\n",a1,a2);
    }
    return 0;
}
