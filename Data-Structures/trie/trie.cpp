#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
typedef pair<int,int> ii;

// Trie Structrue, binary search tree for characters
// Alot more Needs to be added, Currently can only find how many string start with something

struct node {
	map<char,node*> down;
	int cnt = 0;
	void add(string j, int at) { // Call this with the string you want to add and 0 add("ben",0)
		if(at == j.size()) return;
		if(down.find(j[at]) == down.end()) down[j[at]] = new node;
		down[j[at]]->cnt++;
		down[j[at]]->add(j,at+1);
	}
	int startswith(string j, int at) { // Call this with the string you want to find and 0
		if(at == j.size()) return cnt;
		if(down.find(j[at]) == down.end()) return 0;
		return down[j[at]]->startswith(j,at+1);
	}
};

int main() {
	return 0;
}

