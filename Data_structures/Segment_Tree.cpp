struct node {
    int val;
    node(int _val) { val = _val; };
};
struct segment_tree {
    int sz, n;
    vector<node> t;
    segment_tree(int _n) : sz(_n*4), n(_n) {
        rep(i,0,sz) t.pb(node(0));
    }
    void build(vi &a, int v=1, int tl=0, int tr=-1) {
        if(tr == -1) tr = n-1;
        if(tl == tr) {
            t[v].val = a[tl];
        } else {
            int tm = (tl+tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = node(t[v*2].val+t[v*2+1].val);
        }
    }
    node query(int l, int r, int v=1, int tl=0, int tr=-1) {
        if(tr == -1) tr = n-1;
        if(l > r) return node(0);
        if(l == tl && r == tr) return t[v];
        int tm = (tl+tr)/2;
        return node( query(l,min(r,tm), v*2, tl, tm).val
                + query(max(l,tm+1), r, v*2+1, tm+1, tr).val);
    
    }
    void update(int pos, int new_val, int v=1, int tl=0, int tr=-1) {
        if(tr == -1) tr = n-1;
        if(tl == tr) t[v].val = new_val;
        else {
            int tm = (tl+tr)/2;
            if(pos <= tm) update(pos, new_val, v*2, tl, tm);
            else update(pos, new_val, v*2+1, tm+1, tr);
            t[v].val = t[v*2].val + t[v*2+1].val;
        }
    }
};
