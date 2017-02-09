#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
typedef pair<int,int> ii;

// lcm stands for least common multiple, which is the lowest number that is a multiple of both a,b
// lcm needs gcd to work
// to perform lcm on 3 integers you simply do lcm(a,lcm(b,c))

int gcd(int a, int b) { return b == 0 ? a : gcd(b,a%b); }

int lcm(int a, int b) { return a / gcd(a,b) * b; }

int main() {
	return 0;
}

