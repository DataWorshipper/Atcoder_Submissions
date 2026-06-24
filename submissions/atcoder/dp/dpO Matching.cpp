#include <bits/stdc++.h>
using namespace std;
#define v vector
#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const ll MOD = 1000000007;

ll n;
ll a[22][22];
ll dp[22][1 << 21];

ll solve(ll idx, ll mask)
{
    if(idx == n)
    {
        if(mask == (1LL << n) - 1) return 1;
        return 0;
    }

    if(dp[idx][mask] != -1)
        return dp[idx][mask];

    ll ans = 0;

    for(ll man = 0; man < n; man++)
    {
        if((mask & (1LL << man)) == 0)
        {
            if(a[idx][man] == 1)
            {
                ans = (ans +
                       solve(idx + 1,
                             mask | (1LL << man))) % MOD;
            }
        }
    }

    return dp[idx][mask] = ans;
}

int main()
{
    fast_io;

    cin >> n;

    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0) << "\n";

    return 0;
}