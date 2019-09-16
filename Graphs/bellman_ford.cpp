vi bellman_ford(vector<pair<ii,int>> &edges, int n, int u) {
    vi D(n);
    rep(i,0,n) D[i] = INF;
    D[u] = 0;
    rep(i,0,n) {
        bool changed = false;
        rep(j,0,size(edges)) {
            if(D[edges[j].fs.fs] != INF) {
                int new_val = D[edges[j].fs.fs]+edges[j].sc;
                if(new_val < D[edges[j].fs.sc]) {
                    changed = true;
                    D[edges[j].fs.sc] = new_val;
                }
            }
        }
        if(!changed) break;
    }
    rep(i,0,n) {
        rep(j,0,size(edges)) {
            if(D[edges[j].fs.fs] != INF) {
                int new_val = 0;
                if(D[edges[j].fs.fs] == -INF) new_val = -INF;
                else new_val = D[edges[j].fs.fs]+edges[j].sc;
                if(new_val < D[edges[j].fs.sc]) {
                    D[edges[j].fs.sc] = -INF;
                    D[edges[j].fs.fs] = -INF;
                }
            }
        }
    }
    return D;
}
