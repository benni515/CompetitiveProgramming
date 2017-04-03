#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
typedef pair<int,int> ii;
typedef vector<int> vi;

// This is a solution to the problem Bensín on ioi.kattis.algo.is

int const INF = ~(1<<31);
#define MAX_N 500000
#define LOG_TWO_N  19

class RMQ {
    private:
        int _A[MAX_N], SpT[MAX_N][LOG_TWO_N];
    public:
        RMQ(int n, vi A) {
            rep(i,0,n) {
                _A[i] = A[i];
                SpT[i][0] = i;
            }
            for(int j = 1; (1<<j) <= n; j++) {
                for(int i = 0; i + (1<<j) - 1 < n; i++) {
                    if(_A[SpT[i][j-1]] < _A[SpT[i+(1<<(j-1))][j-1]]) SpT[i][j] = SpT[i][j-1]; 
                    else SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
                }
            }
        }
        int query(int i, int j) {
            int k = (int)floor(log((double)j-i+1) / log(2.0));
            if(_A[SpT[i][k]] <= _A[SpT[j-(1<<k)+1][k]]) return _A[SpT[i][k]];
            else return _A[SpT[j-(1<<k)+1][k]];
        }
};

int main() {
	cin.sync_with_stdio(false);
	vector<ii> gs;
	long long s, g;
	cin >> s >> g;
    vi arr;
	long long pos, cost;
	rep(i,0,s) {
		cin >> pos >> cost;
		gs.push_back(ii(pos,cost));
        arr.push_back(cost);
	}
    RMQ rmq = RMQ(s,arr);
	long long at = 0;
	long long mn = 0;
	long long bs = g;
	while(true) {
        if(at == s-1) {
            cout << mn << endl;
            return 0;
        }
        // binary search
        int lowerthan = gs[at].first+bs+1;
        int lo = at+1, hi = s-1;
        int res = INF;
        while(lo <= hi) {
            int mid = (lo+hi)/2;
            if(gs[mid].first < lowerthan) {
                res = mid;
                lo = mid+1;
            } else hi = mid-1;
        }
        int dist = 0;
        int hold = INF;
        if(res != INF) {
            hold = rmq.query(at+1, res);
        }
        if(res == INF || (hold >= gs[at].second && hold != INF)) {
        	// if whe didn't find anything better whe fuel upp full and move one forward
            if(gs[s-1].first-gs[at].first <= bs) {
                int dadist = abs(gs[s-1].first-gs[at].first);
                if(dadist <= g) {
                    cout << mn << endl;
                    return 0;
                } else {
                    mn += abs(dadist-g)*gs[at].second;
                    cout << mn << endl;
                    return 0;
                }
            }
			dist = gs[at+1].first - gs[at].first;
			long long bn = bs - g;
			mn += (bn)*gs[at].second;
			g = bs-dist;
			at += 1;
        } else {
            // binary end
            long long dist = 0;
            bool nf = true;
            rep(i,at+1,s) {
                dist = gs[i].first - gs[at].first;
                if(dist <= bs) { // it is possible to reach the next station
                    long long cost = (dist-g); // the gas whe need to reach
                    if(i == s-1) { // this is the last station so whe are just going there
                        if(cost <= 0) { // whe dont need to pay to get to last
                            cout << mn << endl;
                            return 0;
                        } else { // whe need to pay to get there
                            mn += (cost)*gs[at].second;
                            cout << mn << endl;
                            return 0;
                        }
                    
                    }
                    if(gs[i].second < gs[at].second) { // if the gas price on i is better than on at
                        if(cost <= 0) { // whe dont have to pay anything
                            g = abs(cost);
                            at = i;
                            nf = false;
                            break;
                        } else { // whe are going to have to pay for this
                            mn += (cost)*gs[at].second;
                            g = 0;
                            at = i;
                            nf = false;
                            break;
                        }
                    } 
                } else break;
            }
        }
	}
	return 0;
}

// setja upp binary search til að vita hversu langt við meigum fara

