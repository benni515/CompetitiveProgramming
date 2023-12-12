#include "Graph.cpp"
vector<int> djikstra(Graph &G, int source) {
    vector<bool> vis(G.n, false);
    vector<int> dist(G.n, INT_MAX);
	priority_queue<ii, vii, greater<ii>> pq;
	pq.push(ii(0,source));
	dist[s] = 0;
	while(!pq.empty()) {
		ii cur = pq.top();
		pq.pop();
		if(vis[cur.sc]) continue;
		vis[cur.sc] = true;
        for(auto edge : G.edges[cur.sc]) {
			if(!vis[edge.v] && dist[cur.sc] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[cur.sc] + edge.w;
				pq.push(ii(dist[edge.v], edge.v));
			}
		}
	}
    return dist;
}

