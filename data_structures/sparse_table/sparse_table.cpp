#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); i++)
typedef pair<int,int> ii;
typedef vector<int> vi;

int const INF = ~(1<<31);
#define MAX_N 500000 // the max value of the array
#define LOG_TWO_N  19 // log2 of the max value rounded up

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

}


