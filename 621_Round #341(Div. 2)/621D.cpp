#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
struct node{
	double val;
	bool nan;
	string disc;
	int num;
	bool operator <(const node &A)const{
		if (nan){
			if (A.nan) return num < A.num;
			else return false;
		}
		if (A.nan) return true;
		return val - A.val > eps || abs(val - A.val)<eps && num < A.num;
	}
}a[MAXN];
double x,y,z;
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%lf%lf%lf",&x,&y,&z))){
		for (int i = 0;i <= 12;i++) a[i].num = i,a[i].nan = false;;
		bool an = false;
		if (x < 1 && y < 1 && z < 1) an = true;

		if (an) a[1].val = pow(x,pow(y,z));
		else if (x < 1) a[1].nan = true;
		else a[1].val = z*log(y)+log(log(x));
		a[1].disc = "x^y^z";

		if (an) a[2].val = pow(x,pow(z,y));
		else if (x < 1) a[2].nan = true;
		else a[2].val = y*log(z)+log(log(x));
		a[2].disc = "x^z^y";

		if (an) a[3].val = pow(pow(x,y),z);
		else if (x < 1) a[3].nan = true;
		else a[3].val = log(z*y*log(x));
		a[3].disc = "(x^y)^z";

		if (an) a[4].val = pow(pow(x,z),y);
		else if (x < 1) a[4].nan = true;
		else a[4].val = log(z*y*log(x));
		a[4].disc = "(x^z)^y";

		if (an) a[5].val = pow(y,pow(x,z));
		else if (y < 1) a[5].nan = true;
		else a[5].val = z*log(x)+log(log(y));
		a[5].disc = "y^x^z";

		if (an) a[6].val = pow(y,pow(z,x));
		else if (y < 1) a[6].nan = true;
		else a[6].val = x*log(z)+log(log(y));
		a[6].disc = "y^z^x";

		if (an) a[7].val = pow(pow(y,x),z);
		else if (y < 1) a[7].nan = true;
		else a[7].val = log(z*x*log(y));
		a[7].disc = "(y^x)^z";

		if (an) a[8].val = pow(pow(y,z),x);
		else if (y < 1) a[8].nan = true;
		else a[8].val = log(z*x*log(y));
		a[8].disc = "(y^z)^x";

		if (an) a[9].val = pow(z,pow(x,y));
		else if (z < 1) a[9].nan = true;
		else a[9].val = y*log(x)+log(log(z));
		a[9].disc = "z^x^y";

		if (an) a[10].val = pow(z,pow(y,x));
		else if (z < 1) a[10].nan = true;
		else a[10].val = x*log(y)+log(log(z));
		a[10].disc = "z^y^x";

		if (an) a[11].val = pow(pow(z,x),y);
		else if (z < 1) a[11].nan = true;
		else a[11].val = log(y*x*log(z));
		a[11].disc = "(z^x)^y";

		if (an) a[12].val = pow(pow(z,y),x);
		else if (z < 1) a[12].nan = true;
		else a[12].val = log(y*x*log(z));
		a[12].disc = "(z^y)^x";

		sort(a+1,a+13);
		puts(a[1].disc.c_str());
	}
	return 0;
}
