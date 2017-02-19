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
// Money Matters

// simple dfs where you have to see if all segments of the net have a sum of zero

vector<int> edg[10005]; // for each edge with some index, this holds all the connections
bool vis[10005]; // knows if a node has been visited
int node[10005];

int dfs(int n) { // call with index of node you are going to dfs
	if(vis[n]) return 0; // if vis then return 0, becouse its visited
	int sum = node[n]; // get the sum of the node
	vis[n] = true; // mark visited
	rep(i,0,edg[n].size()) { // dfs all nodes that are neighboors of that edge
		sum += dfs(edg[n][i]); // add to sum the value of the neigboors
	}
	return sum; // return sum
}

int main() {
	cin.sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	rep(i,0,n) cin >> node[i]; // read the money for each node
	rep(i,0,m) {
		int a,b;
		cin >> a >> b;
		edg[a].push_back(b); // add the edge for both people
		edg[b].push_back(a);
	}
	rep(i,0,n) if(dfs(i) != 0) { // if the sum is not 0 then its not possible
			cout << "IMPOSSIBLE" << endl;
			return 0;
	}
	cout << "POSSIBLE" << endl;
	return 0;
}

