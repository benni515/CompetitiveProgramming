#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end();++it)

// This can generate all prime numbers upp to 10**8
// If you need higher prime numbers then just make the bitset larger
// if bit is set then it isn't a prime else it is

int main() {
	cin.sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	// Bitset is better than bool array becouse it uses less memory
	// All bits are turned off in the begining 
	bitset<100000901> prime;
	prime.set(1);
	int cnt = 0;
	for(int p = 2; p<=n;p++) {
		if(!prime.test(p)) { // check if bit is set
			cnt++;
			// set all bits that are a multiple of the prime number
			for(int i = p*2; i<=n;i+=p) prime.set(i); 
		} 
	}
	// number of primes from 0 to N
	cout << cnt << endl;
	rep(i,0,q) {
		int hold;
		cin >> hold;
		// 1 if it is a prime else 0
		if(!prime[hold]) cout << 1 << endl;
		else cout << 0 << endl;
	}
}

