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
	// An example vector of integers
	vector<int> k = {1,2,3,4,5,6,7,8,9,10};
	int size = k.size();
	// prefix needs to be alteast the size of the vector
	int prefix[20];
	int sum = 0;
	rep(i,0,size) {
		prefix[i] = sum;
		sum += k[i];
	}
	// This is an example of how you can calulate the numbers in the vector from 1 to something
	int from,to;
	cin >> from >> to;
	cout << prefix[to]-prefix[from-1] << endl;
	return 0;
}

