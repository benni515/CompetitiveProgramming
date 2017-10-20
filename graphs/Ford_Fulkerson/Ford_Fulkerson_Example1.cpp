#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-5;

/*
 * Website : open.kattis.com
 * ProblemId: marchofpenguins
 */

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



int penguinsat[300];
int icejumps[300];

int gh[300][300];
int rgh[300][300];

int prep(int end) {
    int theend = 251;
    int thestart = 252;
    memset(g,0,sizeof(g));
    memset(rg,0,sizeof(rg));
    rep(i,0,300) rep(a,0,300) {
        g[i][a] = gh[i][a];
        rg[i][a] = rgh[i][a];
    }
    g[end][theend] = rg[theend][end] = 100000;
    rep(i,0,300) {
        g[thestart][i] = rg[i][thestart] = penguinsat[i];
    }
    return forFulkerson(theend,thestart);
}

double dist(dd a, dd b) {
    return sqrt(pow(a.fs-b.fs,2)+pow(a.sc-b.sc,2));
}

int main() {
    cin.sync_with_stdio(false);
    memset(penguinsat,0,sizeof(penguinsat));
    memset(icejumps,0,sizeof(icejumps));

    int peng = 0;
    double d;
    cin >> n >> d;
    vector<dd> k(n);
    rep(i,0,n) {
        cin >> k[i].fs >> k[i].sc >> penguinsat[i] >> icejumps[i];
        peng += penguinsat[i];
    }

    rep(i,0,n) {
        gh[i][i+110] = rgh[i+110][i] = icejumps[i]; 
    }

    rep(i,0,n) {
        rep(a,0,n) {
            if(i == a) continue;
            if(dist(k[i],k[a])  <= d-EPS) {
                gh[i+110][a] = rgh[a][i+110] = icejumps[i];
            }
        }
    }
    vi ans;
    rep(i,0,n) {
        int get = prep(i);
        if(get == peng) ans.push_back(i);
    }
    if(ans.size() == 0) {
        cout << -1 << endl;
        return 0;
    }
    iter(it,ans) cout << *it << " ";
    cout << endl;
    return 0;
}
