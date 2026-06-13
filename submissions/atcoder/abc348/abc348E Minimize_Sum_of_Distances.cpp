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
v<ll>subtree;
v<ll>depth;
void dfs(ll node,ll parent, v<ll>&c,v<v<ll>>&adj,ll d)
{
    depth[node]=d;
    subtree[node]=c[node];
    for(auto child:adj[node])
    {
        if(child!=parent)
        {
            dfs(child,node,c,adj,d+1);
            subtree[node]+=subtree[child];
        }
    }
}

void dfs2(ll node,ll parent,v<v<ll>>&adj,ll tot, v<ll>&ans)
{   
    
    for(auto child:adj[node])
    {
        if(child!=parent)
        {
            ans[child]=ans[node]-subtree[child]+(tot-subtree[child]);
            dfs2(child,node,adj,tot,ans);
        }
    }
}
int main()
{   
    fast_io;
    ll n;
    cin>>n;
    v<v<ll>>adj(n+1);
    ll z=n-1;
    while(z--)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
  v<ll> c(n + 1);
for (ll i = 1; i <= n; i++) cin >> c[i];
    subtree.resize(n+1,0);
    depth.resize(n+1,0);
    dfs(1,-1,c,adj,0);
    v<ll>ans(n+1);
    ll temp=0;
    for(ll i=1;i<=n;i++)
    {
        temp+=(c[i]*depth[i]);
    }
    ans[1]=temp;
    ll tot=accumulate(c.begin(),c.end(),0LL);
    dfs2(1,-1,adj,tot,ans);
    ll m=LLONG_MAX;
    for(ll i=1;i<=n;i++)
    {
        m=min(m,ans[i]);
    }
    cout<<m<<endl;
    
    
    
    
    
}