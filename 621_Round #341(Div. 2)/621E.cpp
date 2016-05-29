#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int MOD = 1e9+7;
const double eps = 1e-10;
int N,B,K,X,x,M,T =MOD,Cases = 0;

struct Matrix{
	static const int matn = 210;
	long long m[matn][matn];
}mat,tmp,C,ans;

Matrix operator *(const Matrix &A,const Matrix &B){
	memset(C.m,0,sizeof(C.m));
	for (int i = 0;i < X;i++)
		for (int j = 0;j < X;j++)
			for (int k = 0;k < X;k++)
				C.m[i][j] = (C.m[i][j]+A.m[i][k]*B.m[k][j])%MOD;
	return C;
}

Matrix MatrixMul(int n){
	if (n == 1) return mat;
	tmp = MatrixMul(n/2);
	if (n%2) return tmp*tmp*mat;
	else return tmp*tmp;
}
//Matrix A^n%mod

int a[10];

int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d%d%d%d",&N,&B,&K,&X))){
		memset(a,0,sizeof(a));
		for (int i= 0;i < N;i++){
			scanf("%d",&x);
			a[x]++;
		}
		memset(mat.m,0,sizeof(mat.m));
		for (int i = 0;i < X;i++)
			for (int j = 0;j < X;j++)
				for (int k = 1;k <= 9;k++)
					if ((i*10+k)%X == j) mat.m[i][j]=(mat.m[i][j]+a[k])%MOD;
		ans = MatrixMul(B);
		printf("%I64d\n",ans.m[0][K]);
	}
	return 0;
}
