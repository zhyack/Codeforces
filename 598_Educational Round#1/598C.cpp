#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
const int INF = 1e9+7;
const double eps = 1e-10;

int N,M,T = INF,Cases = 0;

typedef struct Point
{
    long long x;
    long long y;
    int num;
}Point;
bool PointCmp(Point a,Point b)
{
    if(a.y==0&&a.x>0)
            {
                if(b.y==0&&b.x>0) return a.num<b.num;
                return true;
            }
    else if(b.y==0&&b.x>0) return false;
    if(a.y*b.y<0) return a.y>b.y;
    int det = a.x  * b.y  - b.x  * a.y ;
    if (det < 0)
        return true;
    if (det > 0)
        return false;
    return a.num < b.num;
}
Point p[MAXN];
int x,y;
int main(){
    while(T-- && ~(scanf("%d",&N))){
        for (int i= 0;i < N;i++){
            scanf("%d%d",&x,&y);
            p[i].x = x,p[i].y = y,p[i].num = i+1;
        }
        sort(p,p+N,PointCmp);
        p[N] = p[0];
        long double co = -1.5;
        int a1 = -1,a2= -1;
        for (int i = 0;i < N;i++){
            long double tmpco = double (p[i].x*p[i+1].x+p[i].y*p[i+1].y) /  double(sqrt(p[i].x*p[i].x+p[i].y*p[i].y)*sqrt(p[i+1].x*p[i+1].x+p[i+1].y*p[i+1].y));
            if (tmpco > co){
                co = tmpco;
                a1 = p[i].num;
                a2 = p[i+1].num;
            }
        }
        printf("%d %d\n",a1,a2);
    }
    return 0;
}
