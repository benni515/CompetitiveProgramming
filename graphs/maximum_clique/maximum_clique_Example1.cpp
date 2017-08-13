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

/* Codeforces 
 * Round 428 div 2
 * problem E
 * */

bool edg[45][45];
bool used[45];
int cnt=0,bst=0,n;

void bc(int i) {
	if(i >= n) {
		bst = max(bst,cnt);
		return;
	}
	bool flag = false;
	rep(j,0,i) {
		if(used[j] && !edg[i][j]) {
			flag = true;
			break;
		}
	}
	if(!flag) { // can use
		used[i] = true;
		cnt++;
		bc(i+1);
		cnt--;
	}
	if(cnt+n-i > bst) {
		used[i] = false;
		bc(i+1);
	}
}

int main() {
	cin.sync_with_stdio(false);
	double e;
	cin >> n >> e;
	rep(i,0,n) rep(a,0,n) cin >> edg[i][a];
	bc(0);
	double be = bst;
	double edges = bst*(bst-1)/2;
	double split = e/be;
	cout << setprecision(16) << fixed << split*split*edges << endl;
	return 0;
}

