#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
typedef pair<int,int> ii;

// Iceland.kattis.com
// Símanúmer

// This is a basic example of how the trie can find words that start with some string

struct node {
	map<char,node*> down;
	int cnt = 0;
	void add(string j, int at) {
		if(at == j.size()) return;
		if(down.find(j[at]) == down.end()) down[j[at]] = new node;
		down[j[at]]->cnt++;
		down[j[at]]->add(j,at+1);
	}
	int startswith(string j, int at) {
		if(at == j.size()) return cnt;
		if(down.find(j[at]) == down.end()) return 0;
		return down[j[at]]->startswith(j,at+1);
	}
};

int main() {
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	node *root = new node;
	string j;
	rep(i,0,n) {
		cin >> j;
		root->add(j,0);
	}
	cin >> n;
	rep(i,0,n) {
		cin >> j;
		cout << root->startswith(j,0) << endl;
	}
	

	return 0;
}

