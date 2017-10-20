struct union_find {
	vi p;
	union_find(int n) : p(n) { rep(i,0,n) p[i] = i; }
	int find(int a) { return p[a] == a ? a : p[a] = find(p[a]); }
	bool joined(int a, int b) { return find(a) == find(b);}
	void unite(int a, int b) { p[find(a)] = find(b); }
};
