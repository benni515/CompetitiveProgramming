#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
typedef pair<int,int> ii;
typedef vector<int> vi;

// union_find data structure
// vi p is a vector that holds where they point
// find get index of a node and returns the SUPER node that controlls it
// unite, puts index a and b together in a set, and all things in theyre sets join aswell

// to check if to indexes are in the same set, find(a) == find(b), if true then same set
// 0 1 2 3 4 5 6 
// 0 3 2 3 4 3 6
//

struct union_find {
	vi p;
	int cc;
	vi edg[100010];
	union_find(int n) : p(n) {
		rep(i,0,n) p[i] = i; 
		rep(i,0,n) edg[i].push_back(i);
	}
	int find(int a) { return p[a] == a ? a : p[a] = find(p[a]); }
	bool joined(int a, int b) { return find(a) == find(b);}
	void unite(int a, int b) {
		if(joined(a,b)) return;
		cc--;
		vi ne = edg[find(a)];
		rep(i,0,ne.size()) edg[find(b)].push_back(ne[i]);
		p[find(a)] = find(b);
	}
};

int main() {
	return 0;
}



