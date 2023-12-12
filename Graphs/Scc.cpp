#include "Graph.cpp"
vector<vector<int>> Scc(Graph &G) {
    vector<bool> vis(G.n, false);
    vector<vector<int>> Inv(G.n, vector<int>());

    vector<ii> order;
    vector<int> hold;


	auto dfs = [&](auto self, int u, int &at) -> void {
        vis[u] = true;
        at++;
        for(auto edge : G.edges[u]) if(!vis[edge.v]) self(self, edge.v, at);
        at++;
        order.push_back(ii(at, u));
    };

	auto dfs2 = [&](auto self, int u) -> void {
        vis[u] = true;
        hold.push_back(u);
        for(auto v : Inv[u]) if(!vis[v]) self(self, v);
    };

    int curr = 0;
    for(int u = 0; u < n; u++) {
        if(!vis[u]) dfs(dfs, u, curr);
        for(auto edge : G.edges[u]) Inv[edge.v].pb(u);
    }
    vis = vector<bool>(G.n, false);
    sort(order.rbegin(), order.rend());
    vector<vector<int>> SCC;
    for(int i = 0; i < n; i++) {
        if(!vis[order[i].second]) dfs2(dfs2, order[i].second);
        if(hold.size() != 0) {
            if(hold.size() == 1) {
                for(auto edge : G.edges[order[i].second]) {
                    if(edge.v == order[i].second) SCC.push_back(hold);
                }
            } else {
                SCC.push_back(hold);
            }
        }
        hold.clear();
    }

    return SCC;
}


