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

bool vis[10005]; // bool to check if visited
int dist[10005]; // for best distance
vector<ii> edg[10005]; // key is node from where you are, first is the distance to node, second the node

int main() {
	cin.sync_with_stdio(false);

	int s = 0; // Starting index
	int q = 7; // End index

	// memset everything
	memset(vis,false,sizeof(vis));
	rep(i,0,10005) dist[i] = INF;
	rep(i,0,10005) edg[i].clear();

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
	int m = dist[q];
	if(m == INF) cout << "Impossible" << endl; // no path
	else cout << m << endl; // Its the lengthh
	return 0;
}

