#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end();++it)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = ~(1<<31);
const double pi = acos(-1);

// Open.kattis.com
// Shortestpath1
// Good Example of how the code works

bool vis[10005]; // bool to check if visited
int dist[10005]; // for best distance
vector<ii> edg[10005]; // key is node from where you are, first is the distance to node, second the node

int main() {
	cin.sync_with_stdio(false);
	int n,m,q,s;
	int o = 0;
	while(cin >> n >> m >> q >> s) {
		if(n+m+q+s == 0) break;
		if(o != 0) cout << endl;
		o++;
		// memset everything
		memset(vis,false,sizeof(vis));
		rep(i,0,10005) dist[i] = INF;
		rep(i,0,10005) edg[i].clear();
		rep(i,0,m) {
			int from,to,cost;
			cin >> from >> to >> cost;
			edg[from].push_back(ii(cost,to));
		}

		priority_queue<ii,vector<ii>,greater<ii>> pq;
		pq.push(ii(0,s));
		dist[s] = 0;
		while(!pq.empty()) {
			ii cur = pq.top();
			pq.pop();
			if(vis[cur.second]) continue;
			vis[cur.second] = true;
			rep(i,0,edg[cur.second].size()) {
				ii nx = edg[cur.second][i];
				if(!vis[nx.second]) {
					dist[nx.second] = min(dist[nx.second], dist[cur.second]+nx.first);
					pq.push(ii(dist[nx.second], nx.second));
				}
			}
		}
		int end;
		rep(i,0,q) {
			cin >> end;
			int ans = dist[end];
			if(ans == INF) cout << "Impossible" << endl;
			else cout << ans << endl;
		}
	}
	return 0;
}

