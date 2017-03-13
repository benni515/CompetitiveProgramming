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

// This is a solution to a problem on open.kattis.com
// Problem ID: moviecollection

struct node {
	node* left = NULL;
	node* right = NULL;
	int sum, atr, atl;
	node(node* l, node* r, int v, int al, int ar) {
		left = l;
		right = r;
		sum = v; 
		atl = al;
		atr = ar;
	}
	void change(int at, int to) {
		if(at > atr || at < atl) return;
		if(at == atr && at == atl) {
			sum = to;
			return;
		}
		left->change(at,to);
		right->change(at,to);
		sum = left->sum+right->sum;
	}
	int qsum(int l, int r) {
		if(l > atr || r < atl) return 0;
		if(l <= atl && atr <= r) return sum;
		return left->qsum(l,r)+right->qsum(l,r);
	}
};

node* build(int l, int r) {
	if(l > r) return NULL;
	if(l == r) return new node(NULL, NULL, 0, l, r);
	int m = (l+r)/2;
	node* left = build(l,m);
	node* right = build(m+1,r);
	node* cur = new node(left,right,left->sum+right->sum,l,r);
	return cur;

}

int main() {
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	rep(i,0,n) {
		int m,q;
		cin >> m >> q;
		node* root = build(0,200001);
		unordered_map<int,int> k;
		int index = 0;
		for(int a = m; a >= 1; a--) {
			root->change(a-1,1);
			k[a] = index;
			index++;
		}
		rep(a,0,q) {
			int query;
			cin >> query;
			int at = k[query];
			k[query] = index;
			index++;
			cout << root->qsum(at+1,200001) << " ";
			root->change(at,0);
			root->change(index-1, 1);
		}
		cout << endl;
	}
	return 0;
}

