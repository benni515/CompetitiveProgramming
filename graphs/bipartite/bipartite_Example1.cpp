#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end();++it)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
const int INF = ~(1<<31);
const double pi = acos(-1);

struct BpGraph {
	vvi adj;
	vi owner;
	vector<bool> done;
	
	BpGraph(int n, int m) {
		adj = vvi(n);
		done = vector<bool>(n);
		owner = vi(m);
		rep(i,0,m) owner[i] = -1;
	}
	void addEdge(int a, int b) {
		adj[a].push_back(b);
	}
	int alternating_path(int left) {
		if(done[left]) return 0;
		done[left] = true;
		rep(i,0,adj[left].size()) {
			int right = adj[left][i];
			if(owner[right] == -1 || alternating_path(owner[right])) {
				owner[right] = left;
				return 1;
			}
		}
		return 0;
	}
	int clear(int m) {
		rep(i,0,m) owner[i] = -1;
	}
	vector<int> getconnections(int n, int m) {
		vector<int> ans;
		rep(i,0,n) ans.push_back(owner[i]);
		return ans;
	}
	int maximum_matching(int n, int m) {
		int res = 0;	
		rep(i,0,n) {
			rep(a,0,n) done[a] = 0;
			res += alternating_path(i);
		}
		return res;
	}
};

int main() {
	cin.sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	BpGraph bp(n,n);
	rep(i,0,m) {
		int a,b;
		cin >> a >> b;
		a--;b--;
		bp.addEdge(a,b);
		bp.addEdge(b,a);
	} 
	if(bp.maximum_matching(n,n) != n)  cout << "Impossible" << endl;
	else {
		vector<int> ans = bp.getconnections(n,n);	
		rep(i,0,ans.size()) cout << ans[i]+1 << endl;
	}
	return 0;
}
