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

int main() {
	cin.sync_with_stdio(false);
	long long m;
	cin >> m;
	set<long long> l;
	for(long long i = 1; i*i <= m; i++) {
		if(m%i == 0) {
			l.insert(i);	
			l.insert(m/i);
		}
	}
	iter(it,l) cout << *it-1 << " ";
	cout << endl;
	return 0;
}

