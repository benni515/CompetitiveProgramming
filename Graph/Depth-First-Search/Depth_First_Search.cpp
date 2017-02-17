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

vector<int> edg[10005]; // for each edge with some index, this holds all the connections
bool vis[10005]; // knows if a node has been visited

void dfs(int n) { // call with index of node you are going to dfs
	if(vis[n]) return; // if vis then return
	vis[n] = true; // mark visited
	rep(i,0,edg[n].size()) { // dfs all nodes that are neighboors of that edge
		dfs(edg[n][i]);
	}
	
}

int main() {
	cin.sync_with_stdio(false);
	// if you want to dfs a whole net
	int n = 10; // how many nodes are there
	rep(i,0,n) dfs(i); // dfs every index
	return 0;
}

