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
    ll N,M;
    cin>>N>>M;
    v<ll>a(N+1);
   
    for(ll i=1;i<=N;i++)
    {
        cin>>a[i];
    }
    v<v<ll>>adj(N+1);
    v<ll>indegree(N+1,0);
    ll t=M;
    while(t--)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        indegree[v]++;
    }
    queue<ll>q;
    for(ll i=1;i<=N;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    v<ll>dp(N+1,0);
    for(ll i=1;i<=N;i++)
    {
        dp[i]=LLONG_MAX;
    }
    while(q.size()>0)
    {
        ll node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            dp[it]=min(dp[it],min(dp[node],a[node]));
            indegree[it]--;
            if(indegree[it]==0)
            q.push(it);
        }
    }
    ll ans=LLONG_MIN;
    for(ll i=1;i<=N;i++){
       
     
        ans=max(ans,a[i]-dp[i]);
    }
    cout<<ans<<endl;
    
    
}