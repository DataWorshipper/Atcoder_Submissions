#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int,int>>> adj(N + 1);

    for(int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    vector<vector<int>> vis(N + 1, vector<int>(1024, 0));

    queue<pair<int,int>> q;

    q.push({1, 0});
    vis[1][0] = 1;

    int ans = INT_MAX;

    while(!q.empty())
    {
        auto [node, xr] = q.front();
        q.pop();

        if(node == N)
        {
            ans = min(ans, xr);

           
            if(ans == 0)
            {
                cout << 0 << '\n';
                return 0;
            }
        }

        for(auto &[nxt, wt] : adj[node])
        {
            int new_xor = xr ^ wt;

            if(!vis[nxt][new_xor])
            {
                vis[nxt][new_xor] = 1;
                q.push({nxt, new_xor});
            }
        }
    }

    if(ans == INT_MAX)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}