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

/* Problem 
 * Cs Academy
 * Round 41	
 * Problem D
 * */

struct node {
	node* left = NULL;
	node* right = NULL;
	int atl, atr, val;
	int lazy = 0;
	node(node* l, node* r, int v, int al, int ar) {
		left = l;
		right = r;
		val = v;
		atl = al;
		atr = ar;
	}
	void lazyupdate(int l, int r, int by) {
		if(l > atr || r < atl) return;
		if(lazy != 0) propagate();
		if(l <= atl && atr <= r) {
			val += (atr-atl+1)*by;
			if(left != NULL) {
				left->lazy += by;
				right->lazy += by;
			}
			return;
		}
		left->lazyupdate(l,r,by);
		right->lazyupdate(l,r,by);
		val = left->val+right->val;
	}
	int lazyquery(int l, int r) {
		if(l > atr || r < atl) return 0;
		if(lazy != 0) propagate();
		if(l <= atl && atr <= r) return val;
		return left->lazyquery(l,r)+right->lazyquery(l,r);
	}
	void propagate() {
		val += (atr-atl+1)*lazy;
		if(left != NULL) {
			right->lazy += lazy;
			left->lazy += lazy;
		}
		lazy = 0;
	}
};

node* build(int l, int r, vi &arr) {
	if(l > r) return NULL;
	if(l == r) return new node(NULL, NULL, arr[l], l, r);
	int m = (l+r)/2;
	node* left = build(l,m,arr);
	node* right = build(m+1,r,arr);
	node* cur = new node(left,right,left->val+right->val,l,r);
	return cur;
}

int main() {
	cin.sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vi nums(n), com(m);
	rep(i,0,n) cin >> nums[i];
	rep(i,0,m) cin >> com[i];
	sort(nums.rbegin(), nums.rend());
	node* root = build(0,n-1,nums);
	int at = 0;
	rep(i,0,m) {
		int moves = com[i];
		if(moves > n) break;
		moves--;
		int num = root->lazyquery(moves,moves);
		if(num == 0) break;
		int first = INF, second = -1;
		int lo = 0, hi = n-1;
		while(lo <= hi) {
			int mid = (lo+hi)/2;
			int nam = root->lazyquery(mid,mid);
			if(nam <= num) {
				if(nam == num) first = min(mid,first);
				hi = mid-1;
			} else {
				lo = mid+1;
			}
		}
		lo = 0, hi = n-1;
		while(lo <= hi) {
			int mid = (lo+hi)/2;
			int nam = root->lazyquery(mid,mid);
			if(nam >= num) {
				if(nam == num) second = max(second,mid);
				lo = mid+1;
			} else {
				hi = mid-1;
			}
		}
		if(first != 0) {
			root->lazyupdate(0,first-1,-1);
		}
		int change = moves-first;
		root->lazyupdate(second-change,second,-1);
		at++;
	}
	cout << at << endl;

	return 0;
}















