// Include RMQ
struct LCA {
	vi inv, invv, array, lm;
	vector<bool> vis;
	int num = 0;
	RMQ rmq = RMQ(1,vi(1,1));
	LCA(vector<vi> &edg, int n) : inv(n,0), invv(n,0), vis(n,0), lm(n,-1) {
		euler(edg, 0);
		rmq = RMQ(array.size(), array);
		rep(i,0,array.size()) lm[array[i]] = lm[array[i]] == -1 ? i : lm[array[i]];
	}
	int lca(int a, int b) {
		int first = lm[inv[a]], second = lm[inv[b]];
		if(first > second) swap(first,second);
		return invv[rmq.query(first,second)];
	}
	void euler(vector<vi> &edg, int at) {
		vis[at] = true;
		inv[at] = num;
		invv[num] = at;
		array.pb(num);
		num++;
		iter(it,edg[at]) {
			if(!vis[*it]) {
				euler(edg,*it);
				array.pb(inv[at]);
			}
		}
		array.pb(inv[at]);
	}
};
