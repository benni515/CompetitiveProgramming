struct node {
	node* left = NULL;
	node* right = NULL;
	int atl, atr, val;
	int lazy = 0;
	int mn,mx;
	node(node* l, node* r, int v, int al, int ar) {
		left = l; right = r; val = v;
		atl = al; atr = ar; mn = v; mx = v;
	}
	void lazyupdate(int l, int r, int by) {
		if(lazy != 0) propagate();
		if(l > atr || r < atl) return;
		if(l <= atl && atr <= r) {
			val += (atr-atl+1)*by;
			mx += by; mn += by;
			if(left != NULL) {
				left->lazy += by;
				right->lazy += by;
			}
			return;
		}
		left->lazyupdate(l,r,by);
		right->lazyupdate(l,r,by);
		mn = min(left->mn, right->mn);
		mx = max(left->mx, right->mx);
		val = left->val+right->val;
	}
	int lazyquery(int l, int r) {
		if(l > atr || r < atl) return 0;
		if(lazy != 0) propagate();
		if(l <= atl && atr <= r) return val;
		return left->lazyquery(l,r)+right->lazyquery(l,r);
	}
	int lazylowest(int l, int r) {
		if(l > atr || r < atl) return INF;
		if(lazy != 0) propagate();
		if(l <= atl && atr <= r) return mn;
		return min(left->lazylowest(l,r), right->lazylowest(l,r));
	}
	int lazyhighest(int l, int r) {
		if(l > atr || r < atl) return 0;
		if(lazy != 0) propagate();
		if(l <= atl && atr <= r) return mx;
		return max(left->lazyhighest(l,r), right->lazyhighest(l,r));
	}
	void propagate() {
		val += (atr-atl+1)*lazy;
		mn += lazy;
		mx += lazy;
		if(left != NULL) {
			right->lazy += lazy;
			left->lazy += lazy;
		}
		lazy = 0;
	}
};
node* build(int l, int r) {
	if(l > r) return NULL;
	if(l == r) return new node(NULL, NULL, 0, l, r);
	int m = (l+r)/2;
	node* left = build(l,m,arr);
	node* right = build(m+1,r,arr);
	node* cur = new node(left,right,0,l,r);
	return cur;
}
