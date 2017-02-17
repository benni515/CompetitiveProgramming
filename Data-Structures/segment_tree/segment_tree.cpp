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

struct node {
	node* left = NULL;
	node* right = NULL;
	int sum, mx, mn, atr, atl;
	node(node* l, node* r, int v, int al, int ar) {
		left = l;
		right = r;
		sum = v; mx = v; mn = v;
		atl = al;
		atr = ar;
	}
	void change(int at, int to) { // changes index of at into value of to
		if(at > atr || at < atl) return;
		if(at == atr && at == atl) {
			sum = to; mx = to; mn = to;
			return;
		}
		left->change(at,to);
		right->change(at,to);
		update();
	}
	void add(int at, int by) { // adds by to the index of at
		if(at > atr || at < atl) return;
		if(at == atr && at == atl) {
			sum+=by;mx+=by;mn+=by;
			return;
		}
		left->add(at,by);
		right->add(at,by);
		update();
	}
	void update() { // Changes everything when done
		sum = left->sum+right->sum;
		mx = min(left->mn, right->mn);
		mx = max(left->mx, right->mx);
	}
	int qsum(int l, int r) { // gets the some from range l to r
		if(l > atr || r < atl) return 0;
		if(l <= atl && atr <= r) return sum;
		return left->qsum(l,r)+right->qsum(l,r);
	}
	int qmn(int l, int r) { // gets the min value from l to r
		if(l > atr || r < atl) return INF;
		if(l <= atl && atr <= r) return mn;
		return min(left->qmn(l,r),right->qmn(l,r));
	}
	int qmx(int l, int r) { // gets the max value from l to r
		if(l > atr || r < atl) return 0;
		if(l <= atl && atr <= r) return mx;
		return max(left->qmx(l,r), right->qmx(l,r));
	}
};

// There are many ways to build a segment tree, this builds a segment tree
// of length r with 0 at all nodes, you can use a vector, or just your own integer value
// also it does not update sums, max and min value for parents of nodes
node* build(int l, int r) {
	if(l > r) return NULL;
	if(l == r) return new node(NULL,NULL,0,l,r);
	int m = (l+r)/2;
	node* left = build(l,m);
	node* right = build(m+1,r);
	node* cur = new node(left,right,0,l,r);
	return cur;
}

int main() {
	return 0;
}

