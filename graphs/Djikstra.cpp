vii edg[10005];
int djikstra(int s, int e) {
	bool vis[10005];
	int dist[10005]; 
	memset(vis,false,sizeof(vis));
	rep(i,0,10005) dist[i] = INF;
	priority_queue<ii,vii,greater<ii>> pq;
	pq.push(ii(0,s));
	dist[s] = 0;
	while(!pq.empty()) {
		ii cur = pq.top();
		pq.pop();
		if(vis[cur.sc]) continue;
		vis[cur.sc] = true;
		rep(i,0,edg[cur.sc].size()) {
			ii nx = edg[cur.sc][i];
			if(!vis[nx.sc]) {
				dist[nx.sc] = min(dist[nx.sc], dist[cur.sc]+nx.fs);
				pq.push(ii(dist[nx.sc], nx.sc));
			}
		}
	}
	if(dist[e] == INF) cout << "Impossible" << endl; // no path
	else cout << dist[e] << endl; // Its the lengthh
}

