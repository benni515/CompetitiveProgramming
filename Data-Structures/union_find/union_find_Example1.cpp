#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
typedef pair<int,int> ii;
typedef vector<int> vi;


// Open.Kattis.com
// Unionfind

struct union_find {
	vi p;
	union_find(int n) : p(n) {rep(i,0,n) p[i] = i;}
	int find(int x) { return p[x] == x ? x : p[x] = find(p[x]);}
	void unite(int a, int b) {p[find(a)] = find(b);}
	bool joined(int a, int b) {return find(a) == find(b);}
};

int main() {
	int n,q;
	cin >> n >> q;
	union_find u(n); // created a union with the size of 15
	char k;
	int f,f2;
	rep(i,0,q) {
		cin >> k >> f >> f2;
		if(k == '?') cout << (u.joined(f,f2) ? "yes" : "no") << endl;
		else u.unite(f,f2);
	}
	return 0;
}
