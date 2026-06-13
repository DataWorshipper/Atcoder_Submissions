#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> dijkstra(int src, vector<vector<pair<int,ll>>> &adj)
{
    int n = adj.size() - 1;

    vector<ll> dist(n + 1, (ll)4e18);

    priority_queue<
        pair<ll,int>,
        vector<pair<ll,int>>,
        greater<pair<ll,int>>
    > pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if(d != dist[u]) continue;

        for(auto &[v, w] : adj[u])
        {
            if(dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<pair<int,ll>>> adj(N + 1);

    for(int i = 0; i < N - 1; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<ll> D(N + 1);

    for(int i = 1; i <= N; i++)
        cin >> D[i];

    auto d1 = dijkstra(1, adj);

    int A = 1;
    ll best = -1;

    for(int i = 1; i <= N; i++)
    {
        if(d1[i] + D[i] > best)
        {
            best = d1[i] + D[i];
            A = i;
        }
    }

    auto distA = dijkstra(A, adj);

    int B = -1;
    best = -1;

    for(int i = 1; i <= N; i++)
    {
        if(i == A) continue;

        if(distA[i] + D[i] > best)
        {
            best = distA[i] + D[i];
            B = i;
        }
    }

    auto distB = dijkstra(B, adj);

    for(int i = 1; i <= N; i++)
    {
        if(i == A)
        {
            cout << distB[i] + D[B] << '\n';
        }
        else if(i == B)
        {
            cout << distA[i] + D[A] << '\n';
        }
        else
        {
            cout << max(distA[i] + D[A],
                        distB[i] + D[B]) << '\n';
        }
    }

    return 0;
}