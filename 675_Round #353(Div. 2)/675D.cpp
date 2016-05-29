#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;
const int INF = 1e9+7;
const double eps = 1e-10;
int N,M,T = INF,Cases = 0;
int a[MAXN];
int f[MAXN];
bool l[MAXN];
bool r[MAXN];
struct node{
	int val;
	int index;
	node(int v,int i){
		val = v;
		index = i;
	}
	bool operator <(const node &t)const{
		return val<t.val;
	}
}tmp(0,0);
set<node> s;
int main(){
	//ios_base::sync_with_stdio(0);

	//freopen("input.txt", "r", stdin),cerr << "Attention, SB!!!\nAttention, SB!!!\n" << endl;	//++++You fool, comment this line++++//
	//scanf("%d",&T);
	while(T-- && ~(scanf("%d",&N))){
		for (int i = 0;i < N;i++) scanf("%d",a+i);
		memset(l,true,sizeof(l));
		memset(r,true,sizeof(r));
		s.clear();
		tmp.val = a[0];
		tmp.index = 0;
		s.insert(tmp);
		set<node>::iterator it;
		for (int i = 1;i < N;i++){
			tmp.val = a[i];
			tmp.index = i;
			s.insert(tmp);
			it = s.find(tmp);
			if (it != s.begin()){
				it--;
				if (r[it->index]){
					r[it->index] = false;
					f[i] = it->val;
					continue;
				}
				it++;
			}
			it++;
			if (it!=s.end()){
				if (l[it->index]){
					l[it->index] = false;
					f[i] = it->val;
				}
			}
		}
		for (int i = 1;i < N;i++) printf("%d ",f[i]);
		putchar('\n');
	}
	return 0;
}
