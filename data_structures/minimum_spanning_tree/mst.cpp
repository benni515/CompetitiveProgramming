#include <bits/stdc++.h>
using namespace std;
#define range(i, a, b) for (int i = (a); i < (b); ++i)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
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
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;

        vector<pair<int, ii>> edges;
        int u, v, w;
        range(i, 0, m) {
            cin >> u >> v >> w;
            edges.push_back(make_pair(w, ii(u, v)));
        }
        //Sort the edges by weight - MSTs are greedy
        sort(edges.begin(), edges.end());

        //Path cost
        int cost = 0;
        UnionFind ds(n);
        vii mst;

        range(i, 0, m) {
            pair<int, ii> front = edges[i];
            int x = front.second.first;
            int y = front.second.second;
            if (!ds.joined(x, y)) {
                //If either node is not in the MST - join them
                cost += front.first;
                ds.unionset(x, y);
            }
        }
        /*
            It's a minimum spanning TREE
            therefore if there are less than N-1 edges
            there is no minimum spanning tree
            i.e. the graph is disconnected (multiple components)
        */
        int x = (int)mst.size();
        if (x < (n - 1))
            cout << "Not a valid MST" << endl;
        else
            cout << cost << endl;
    }
    return 0;
}
