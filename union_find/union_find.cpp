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

struct union_find {
	vi p;
	union_find(int n) : p(n) {rep(i,0,n) p[i] = i;}
	int find(int x) { return p[x] == x ? x : p[x] = find(p[x]);}
	int unite(int a, int b) {p[find(a)] = find(b);}
};

int main() {

	union_find u(15); // created a union with the size of 15
	
	return 0;
}

