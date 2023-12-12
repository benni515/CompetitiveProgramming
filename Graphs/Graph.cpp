struct Edge {
	int v,w;

	Edge(int _v, int _w = 1) : v(_v), w(_w) {}
};

struct Graph {
	int n;
	bool directed, weighted;
	vector<vector<Edge>> edges;

	Graph(int _n, bool _directed = false, bool _weighted = false) 
		: n(_n), directed(_directed), weighted(_weighted) {
		edges = vector<vector<Edge>>(n, vector<Edge>());
	}

	void add_edge(int u, int v, int w = 1) {
		edges[u].push_back(Edge(v,w));
		if(!directed) edges[v].push_back(Edge(u,w));
	}
};
