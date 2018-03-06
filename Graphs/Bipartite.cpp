struct BpGraph {
	vvi adj;
	vi owner;
	vector<bool> done;
	BpGraph(int n, int m) {
		adj = vvi(n);
		done = vector<bool>(n);
		owner = vi(m,-1);
	}
	void addEdge(int a, int b) { adj[a].push_back(b); }
	int alternating_path(int left) {
		if(done[left]) return 0;
		done[left] = true;
		rep(i,0,adj[left].size()) {
			int right = adj[left][i];
			if(owner[right] == -1 || alternating_path(owner[right])) {
				owner[right] = left;
				return 1;
			}
		}
		return 0;
	}
	int clear(int m) { owner.assign(m,-1); }
	vi getconnections(int n, int m) {
		vi ans;
		rep(i,0,n) ans.push_back(owner[i]);
		return ans;
	}
	int maximum_matching(int n, int m) {
		int res = 0;	
		rep(i,0,n) {
			rep(a,0,n) done[a] = 0;
			res += alternating_path(i);
		}
		return res;
	}
};
