#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int LIM = 1000000;

vector<vector<int>> adj;
vector<bool> vis;
int ans = 0;

void dfs(int u)
{
    if (ans == LIM)
        return;

    ans++;

    vis[u] = true;

    for (int v : adj[u])
    {
        if (!vis[v])
            dfs(v);
    }

    vis[u] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    adj.resize(N + 1);
    vis.assign(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    cout << ans << "\n";

    return 0;
}