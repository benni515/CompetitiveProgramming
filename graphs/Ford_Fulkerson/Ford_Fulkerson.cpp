#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = ~(1<<31);
const double pi = acos(-1);

int g[300][300];
int rg[300][300];
int f[300], max_flow, path_flow;
int p[300];

int n = 300;
int s,t,u,v,w;

int bfs(int s, int t) {
    bool visited[300];
    memset(visited,0,sizeof(visited));
    visited[s] = true;
    queue<int> q;
    q.push(s);
    p[s] = -1;
    f[s] = INF;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        rep(v,0,300) {
            if(!visited[v] && rg[u][v] > 0) {
                q.push(v);
                p[v] = u;
                visited[v] = true;
                f[v] = min(f[u], rg[u][v]);
            }
        }
    }
    return (visited[t]?f[t]:0);
}

int forFulkerson(int s, int t) {
    max_flow = 0;
    while(path_flow = bfs(s,t)) {
        for(v=t; v != s; v = p[v]) {
            u = p[v];
            rg[u][v] -= path_flow;
            rg[v][u] += path_flow;
        }
        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    cin.sync_with_stdio(false);
    return 0;
}


