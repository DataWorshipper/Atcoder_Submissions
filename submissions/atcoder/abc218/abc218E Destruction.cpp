#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);

        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find_parent(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find_parent(parent[u]);
    }

    bool unite(int u, int v) {
        u = find_parent(u);
        v = find_parent(v);

        if(u == v) return false;

        if(sz[u] < sz[v]) swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<array<long long, 3>> edges;

    long long ans = 0;

    for(int i = 0; i < m; i++) {

        long long a, b, c;
        cin >> a >> b >> c;

        edges.push_back({c, a, b});

        if(c > 0) ans += c;
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);

    for(auto &e : edges) {

        long long c = e[0];
        int a = e[1];
        int b = e[2];

        if(dsu.unite(a, b)) {

            if(c > 0) {
                ans -= c;
            }
        }
    }

    cout << ans << '\n';
}