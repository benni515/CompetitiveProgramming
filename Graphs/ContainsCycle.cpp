#include "Graph.cpp"
bool ContainsCycle(Graph &G) {

    vector<bool> visited(G.n, false), in_path(G.n, false);
    bool cycle = false;

    void dfs(int at) {
        if(cycle) return;
        visited[at] = true;
        inpath[at] = true;
        for(auto edge : G.edges[at]) {
            if(inpath[edge.v]) {
                cycle = true;
                return;
            }
            if(!visited[edge.v]) dfs(edge.v);
        }
        inpath[at] = false;
    }

    for(int i = 0; i < G.n; i++) {
        if(!visited[i]) dfs(i);
    }

    return cycle;
}
