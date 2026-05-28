#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, weight;
};

int main() {
    int a, b, x, y;
    if (!(cin >> a >> b >> x >> y)) return 0;

    vector<vector<Edge>> adj(201);

    for (int i = 1; i <= 100; ++i) {
        adj[i].push_back({i + 100, x});
        adj[i + 100].push_back({i, x});
    }

    for (int i = 1; i <= 99; ++i) {
        adj[i + 1].push_back({i + 100, x});
        adj[i + 100].push_back({i + 1, x});
    }

    for (int i = 1; i <= 99; ++i) {
        adj[i].push_back({i + 1, y});
        adj[i + 1].push_back({i, y});

        adj[i + 100].push_back({i + 101, y});
        adj[i + 101].push_back({i + 100, y});
    }

    int start_node = a;
    int end_node = b + 100;

    vector<int> dist(201, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start_node] = 0;
    pq.push({0, start_node});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;
        if (u == end_node) break;

        for (const auto& edge : adj[u]) {
            if (dist[u] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[u] + edge.weight;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }

    cout << dist[end_node] << "\n";

    return 0;
}