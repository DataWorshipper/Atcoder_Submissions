#include <bits/stdc++.h>
using namespace std;

#define v vector
#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const ll LOG_MAX=20;

class DSU
{
    public:

    v<ll> parent,rank1;

    DSU(ll n)
    {
        parent.assign(n+1,0);
        rank1.assign(n+1,0);

        for(ll i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }

    ll find_parent(ll node)
    {
        if(node==parent[node])
        {
            return node;
        }

        return parent[node]=find_parent(parent[node]);
    }

    void unite(ll u,ll v1)
    {
        ll pu=find_parent(u);
        ll pv=find_parent(v1);

        if(pu==pv)
        {
            return;
        }

        ll ru=rank1[pu];
        ll rv=rank1[pv];

        if(ru>rv)
        {
            parent[pv]=pu;
        }
        else if(rv>ru)
        {
            parent[pu]=pv;
        }
        else
        {
            parent[pu]=pv;
            rank1[pv]++;
        }
    }
};

void dfs(ll node,
         ll parent,
         v<v<ll>>&up,
         v<v<ll>>&mx,
         v<v<pair<ll,ll>>>&adj,
         v<ll>&depth,
         ll weight)
{
    up[node][0]=parent;

    mx[node][0]=weight;

    for(auto child:adj[node])
    {
        ll v1=child.first;
        ll w=child.second;

        if(v1==parent)
        {
            continue;
        }

        depth[v1]=depth[node]+1;

        dfs(v1,node,up,mx,adj,depth,w);
    }
}

ll get_max(ll u,
           ll v1,
           v<v<ll>>&up,
           v<v<ll>>&mx,
           v<ll>&depth)
{
    ll ans=0;

    if(depth[u]<depth[v1])
    {
        swap(u,v1);
    }

    ll diff=depth[u]-depth[v1];

    for(ll j=LOG_MAX-1;j>=0;j--)
    {
        if(diff&(1LL<<j))
        {
            ans=max(ans,mx[u][j]);

            u=up[u][j];
        }
    }

    if(u==v1)
    {
        return ans;
    }

    for(ll j=LOG_MAX-1;j>=0;j--)
    {
        if(up[u][j]!=up[v1][j])
        {
            ans=max(ans,mx[u][j]);

            ans=max(ans,mx[v1][j]);

            u=up[u][j];

            v1=up[v1][j];
        }
    }

    ans=max(ans,mx[u][0]);

    ans=max(ans,mx[v1][0]);

    return ans;
}

int main()
{
    fast_io;

    ll n,m,q;

    cin>>n>>m>>q;

    v<v<ll>> edges;

    for(ll i=0;i<m;i++)
    {
        ll a,b,w;

        cin>>a>>b>>w;

        edges.pb({a,b,w});
    }

    sort(all(edges),[&](auto &a,auto &b)
    {
        return a[2]<b[2];
    });

    DSU dsu(n);

    v<v<pair<ll,ll>>> adj(n+1);

    for(auto it:edges)
    {
        ll a=it[0];
        ll b=it[1];
        ll w=it[2];

        if(dsu.find_parent(a)!=dsu.find_parent(b))
        {
            dsu.unite(a,b);

            adj[a].pb({b,w});

            adj[b].pb({a,w});
        }
    }

    v<v<ll>> up(n+1,v<ll>(LOG_MAX));

    v<v<ll>> mx(n+1,v<ll>(LOG_MAX));

    v<ll> depth(n+1,0);

    dfs(1,1,up,mx,adj,depth,0);

    for(ll j=1;j<LOG_MAX;j++)
    {
        for(ll i=1;i<=n;i++)
        {
            up[i][j]=up[up[i][j-1]][j-1];

            mx[i][j]=max(
                mx[i][j-1],
                mx[up[i][j-1]][j-1]
            );
        }
    }

    while(q--)
    {
        ll u,v1,w;

        cin>>u>>v1>>w;

        ll best=get_max(u,v1,up,mx,depth);

        if(w<best)
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
}