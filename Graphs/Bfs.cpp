#include "Graph.cpp"
vector<int> Bfs(Graph &G, int root) {
	vector<int> Dist(G.n, -1);
	Dist[root] = 0;
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int at = q.front();
		q.pop();
		for(auto edge : G.edges[at]) {
			int v = edge.v;
			if(Dist[v] == -1) {
				Dist[v] = Dist[at] + 1;
				q.push(v);
			}
		}
	}
	return Dist;
}
