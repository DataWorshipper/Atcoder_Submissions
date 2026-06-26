#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    fast_io;

    ll N, M, K;
    cin >> N >> M >> K;

    vector<vector<pair<ll,ll>>> adj(N + 1);

    for(ll i = 0; i < M; i++)
    {
        ll u, v, a;
        cin >> u >> v >> a;

        adj[u].push_back({v, a});
        adj[v].push_back({u, a});
    }

    vector<ll> hasSwitch(N + 1, 0);

    for(ll i = 0; i < K; i++)
    {
        ll x;
        cin >> x;
        hasSwitch[x] = 1;
    }

    vector<vector<ll>> dist(N + 1, vector<ll>(2, LLONG_MAX));

    deque<pair<ll,ll>> dq;

    dist[1][0] = 0;
    dq.push_front({1, 0});
      while(!dq.empty())
    {
        auto [node, parity] = dq.front();
        dq.pop_front();
        for(auto it:adj[node])
        {
            ll neigh=it.first;
            ll pass=it.second;
            if(hasSwitch[node])
            {
                if(dist[node][parity^1]>dist[node][parity])
                {
                    dist[node][parity^1]=dist[node][parity];
                    dq.push_front({node,parity^1});
                }
            }
            
            if(parity==0 && pass==1)
            {
                if(dist[neigh][parity]>dist[node][parity]+1)
                {
                     dist[neigh][parity]=dist[node][parity]+1;
                    dq.push_back({neigh,parity});
                }
            }
             else if(parity==1 && pass==0)
            {
                if(dist[neigh][parity]>dist[node][parity]+1)
                {
                     dist[neigh][parity]=dist[node][parity]+1;
                    dq.push_back({neigh,parity});
                }
            }
            
            
            
        }
    }
    
    ll ans = min(dist[N][0], dist[N][1]);

    if(ans == LLONG_MAX)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
    
    
    }