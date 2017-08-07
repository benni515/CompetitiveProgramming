#include <bits/stdc++.h>
using namespace std;
#define range(i, a, b) for (int i = (a); i < (b); ++i)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
const int INF = ~(1<<31);

class UnionFind 
{
    private:
        vi p;
    public:
        UnionFind(int n) {
            range(i, 0, n) p.push_back(i);
        }
        int find(int i) {
            if (p[i] == i) return i;
            return p[i] = find(p[i]);
        }
        bool joined(int i, int j) {
            return find(i) == find(j);
        }
        void unionset(int i, int j) {
            if (!joined(i, j)) p[find(j)] = find(i);
        }
};

int main(void)
{
    // https://open.kattis.com/problems/islandhopping
    int n;
    cin >> n;
    cout << fixed << showpoint << setprecision(10);
    range(_, 0, n) {
        int m;
        cin >> m;
        vector<pair<float, float>> islands;
        range(i, 0, m) {
            float x, y;
            cin >> x >> y;
            islands.push_back(make_pair(x, y));
        }
        vector<pair<double, ii>> edges;
        //Generate all possible pairs of islands and weights (distance)
        range(i, 0, m) {
            range(j, i, m) {
                pair<float, float> a = islands[i];
                pair<float, float> b = islands[j];
                double d = sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
                edges.push_back(make_pair(d, ii(i, j)));
            }
        }
        //Here be MST magic
        UnionFind ds(m);
        sort(edges.begin(), edges.end());
        double cost = 0;
        int s = (int)edges.size();
        range(i, 0, s) {
            int x = edges[i].second.first;
            int y = edges[i].second.second;
            if (!ds.joined(x, y)) {
                cost += edges[i].first;
                ds.unionset(x, y);
            }
        }
        cout << cost << endl;
    }
    return 0;
}

