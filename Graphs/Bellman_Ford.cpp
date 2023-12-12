#include "Graph.cpp"
vector<int> bellman_ford(Graph &G, int source) {
    vector<int> Dist(G.n, INT_MAX);
    Dist[source] = 0;
    for(int turn = 0; turn < n; turn++) {
        bool changed = false;
        for(int u = 0; u < n; u++) {
            for(auto edge : G.edges[u]) {
                int v = edge.v;
                int w = edge.w;
                if(Dist[u] != INT_MAX && Dist[u] + w < Dist[v]) {
                    changed = true;
                    Dist[v] = Dist[u] + w;
                }
            }
        }
        if(!changed) break;
    }
    for(int turn = 0; turn < n; turn++) {
        for(int u = 0; u < n; u++) {
            for(auto edge : G.edges[u]) {
                int v = edge.v;
                int w = edge.w;
                if(Dist[u] != INT_MAX && Dist[u] + w < Dist[v]) {
                    Dist[v] = -INT_MAX;
                }
            }
        }
    }
    return Dist;
}
