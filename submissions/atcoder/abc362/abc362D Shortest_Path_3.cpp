#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define v vector
#define pb push_back

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin>>N>>M;

    v<ll> A(N+1);

    for(int i=1;i<=N;i++)
        cin>>A[i];

    v<v<pair<int,ll>>> adj(N+1);

    for(int i=0;i<M;i++)
    {
        int u,v;
        ll b;

        cin>>u>>v>>b;

        adj[u].pb({v,b});
        adj[v].pb({u,b});
    }

    priority_queue<
        pair<ll,int>,
        vector<pair<ll,int>>,
        greater<pair<ll,int>>
    > pq;

    v<ll> dist(N+1,LLONG_MAX);

    dist[1]=A[1];

    pq.push({dist[1],1});

    while(!pq.empty())
    {
        auto [d,node]=pq.top();
        pq.pop();

        if(d>dist[node]) continue;

        for(auto [child,w]:adj[node])
        {
            ll nd = dist[node] + w + A[child];

            if(nd < dist[child])
            {
                dist[child]=nd;
                pq.push({nd,child});
            }
        }
    }

    for(int i=2;i<=N;i++)
        cout<<dist[i]<<" ";
}