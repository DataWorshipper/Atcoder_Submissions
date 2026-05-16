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
const ll N = 3000005;

vector<ll> fact(N), invfact(N);

ll binexp(ll a, ll b)
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

void inv()
{
    fact[0] = 1;

    for(ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
invfact[N - 1] = binexp(fact[N - 1], MOD - 2);

    for(ll i = N - 2; i >= 0; i--)
    {
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
    }
}

ll ncr(ll n, ll r)
{
    if(r < 0 || r > n)
    {
        return 0;
    }
return (((fact[n] * invfact[r]) % MOD) * invfact[n - r]) % MOD;
}

int main()
{
    fast_io;
    inv();
ll x1, x2, x3;
    cin >> x1 >> x2 >> x3;
ll m = x2 + 1;
    ll ans = 0;

    for(ll k = 1; k <= min(x1, m); k++)
    {
        ll cur = ncr(m, k);
        cur = (cur * ncr(x1 - 1, k - 1)) % MOD;
        cur = (cur * ncr(x3 + m - k - 1, x3)) % MOD;
        ans = (ans + cur) % MOD;
    }

    cout << ans << endl;
}