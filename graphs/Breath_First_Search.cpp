int bfs(int s, int e) {
	bool vis[10005];
	int dist[10005];
	vi edg[10005];
	memset(vis,false,sizeof(vis));
	rep(i,0,10005) dist[i] = INF;
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	vis[s] = true;
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		rep(i,0,edg[cur].size()) {
			int nx = edg[cur][i];
			if(!vis[nx]) {
				dist[nx] = dist[cur]+1;
				vis[nx] = 1;
				q.push(nx);
			}
		}
	}
	if(dist[e] == INF) cout << "Impossible" << endl;
	else cout << dist[e] << endl;
}
