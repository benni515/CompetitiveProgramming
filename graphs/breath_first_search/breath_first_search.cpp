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
int dist[10005];
vector<int> edg[10005]; // key is node from where you are, first is the distance to node, second the node

int main() {
	cin.sync_with_stdio(false);

	int s = 0; // Starting index
	int end = 7; // End index

	// memset everything
	memset(vis,false,sizeof(vis));
	rep(i,0,10005) dist[i] = INF;
	rep(i,0,10005) edg[i].clear();

	queue<int> q;
	q.push(s);
	dist[s] = 0;
	vis[s] = true;
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		rep(i,0,edg[cur].size()) {
			int nx = edg[cur][i];
			if(!vis[nx]) {
				dist[nx] = dist[cur]+1;
				vis[nx] = 1;
				q.push(nx);
			}
		}
	}
	int m = dist[end];
	if(m == INF) cout << "Impossible" << endl; // no path
	else cout << m << endl; // Its the lengthh
	return 0;
}

