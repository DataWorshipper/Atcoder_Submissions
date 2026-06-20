#include <bits/stdc++.h>
using namespace std;
#define v vector
#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define f(arr, n) for(ll i = 0; i < n; i++) cin >> arr[i];

const ll MOD = 998244353;
const ll MAXD = 1000005;

vector<ll> sieve(ll sieve_size)
{
    vector<ll> s(sieve_size + 1, 1);
    s[0] = s[1] = 0;  

    for (ll i = 2; i * i <= sieve_size; i++)
    {
        if (s[i] == 1)
        {
            for (ll j = i * i; j <= sieve_size; j += i)  
            {
                s[j] = 0;
            }
        }
    }
    return s;
}
int main()
{   
    fast_io;
    ll n,m,Y;
    cin>>n>>m>>Y;
    v<v<pair<ll,ll>>>adj(n+2);
    ll S=n+1;
    ll t=m;
    while(t--)
    {
        ll u,v,z;
        cin>>u>>v>>z;
        adj[u].pb({v,z});
        adj[v].pb({u,z});
    }
   v<ll> X(n+1);

for(ll i=1;i<=n;i++)
    cin>>X[i];
    
    for(ll i=1;i<=n;i++)
    {
        adj[i].pb({S,X[i]+Y});
        adj[S].pb({i,X[i]});
    }
    using pll=pair<ll,ll>;
    priority_queue<pll,vector<pll>,greater<pll>>pq;
    pq.push({1,0});
    v<ll>dist(n+2,LLONG_MAX);
    dist[1]=0;
    while(!pq.empty())
    {
        pair<ll,ll>p1=pq.top();
        pq.pop();
        ll node=p1.first;
        for(auto nei:adj[node])
        {
            ll child=nei.first;
            ll wt=nei.second;
            if(dist[node]+wt<dist[child])
            {
                dist[child]=dist[node]+wt;
                pq.push({child,dist[node]+wt});
            }
        }
        
    }
    for(ll i=2;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    
    
        
    
}