// O(V+E)
void dfs(int at) {
    if(cycle) return;
    visited[at] = true;
    inpath[at] = true;
	iter(it,edge[at]) {
		if(inpath[*it]) {
			cycle = true;
			return;
		}
		if(!visited[*it]) dfs(*it);
	}
    inpath[at] = false;
}

bool check() {
    memset(visited,0,sizeof(visited));
    memset(inpath,0,sizeof(inpath));
    rep(i,0,n) if(!visited[i]) {
        cycle = false;
        dfs(i);
        if(cycle) return false;
    }
    return true;
}
