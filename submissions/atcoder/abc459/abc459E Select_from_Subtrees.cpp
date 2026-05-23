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

ll fact[MAXD];
ll invfact[MAXD];

ll modpow(ll a, ll b)
{
    ll res = 1;

    while(b)
    {
        if(b & 1)
        {
            res = (res * a) % MOD;
        }

        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

ll ncr(ll n, ll r)
{
    if(r < 0 || r > n)
    {
        return 0;
    }

    ll num = 1;

    for(ll i = 0; i < r; i++)
    {
        num = (num * ((n - i) % MOD)) % MOD;
    }

    return (num * invfact[r]) % MOD;
}

v<v<ll>> adj;
v<ll> C, D;
v<ll> S, R;

bool ok;

void dfs(ll u)
{
    S[u] = C[u];
    R[u] = D[u];

    for(auto x : adj[u])
    {
        dfs(x);

        S[u] += S[x];
        R[u] += R[x];
    }

    if(R[u] > S[u])
    {
        ok = false;
    }
}

int main()
{   
    fast_io;

    fact[0] = 1;

    for(ll i = 1; i < MAXD; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    invfact[MAXD - 1] = modpow(fact[MAXD - 1], MOD - 2);

    for(ll i = MAXD - 2; i >= 0; i--)
    {
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
    }

    ll n;
    cin >> n;

    adj.resize(n + 1);
    C.resize(n + 1);
    D.resize(n + 1);
    S.resize(n + 1);
    R.resize(n + 1);

    for(ll i = 2; i <= n; i++)
    {
        ll p;
        cin >> p;

        adj[p].pb(i);
    }

    for(ll i = 1; i <= n; i++)
    {
        cin >> C[i];
    }

    for(ll i = 1; i <= n; i++)
    {
        cin >> D[i];
    }

    ok = true;

    dfs(1);

    if(!ok)
    {
        cout << 0 << '\n';
        return 0;
    }

    ll ans = 1;

    for(ll i = 1; i <= n; i++)
    {
        ll x = S[i] - R[i] + D[i];

        ans = (ans * ncr(x, D[i])) % MOD;
    }

    cout << ans << '\n';
}