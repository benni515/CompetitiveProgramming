// include Union_Find.cpp
int mst(vector<pair<int,ii>> &edg, int size) {
    sort(edg.begin(), edg.end());
	int cost = 0;
	union_find ds(size);
	vii mst;
	rep(i,0,edg.size()) {
		int x = edg[i].sc.fs;
		int y = edg[i].sc.sc;
		if (!ds.joined(x, y)) {
			cost += edg[i].fs;
			ds.unite(x, y);
		}
	}
	return cost;
}
