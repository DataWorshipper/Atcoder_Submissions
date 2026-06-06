#include <bits/stdc++.h>
using namespace std;

#define v vector
#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back

int main()
{
    fast_io;

    ll n, m;
    cin >> n >> m;

    v<ll> p(n + 1), val(n + 1);

    for (ll i = 1; i <= n; i++)
    {
        cin >> p[i] >> val[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    vector<vector<ll>> dp2(n + 2, vector<ll>(m + 1, 0));

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (j >= p[i])
            {
                dp[i][j] = max(
                    dp[i][j],
                    dp[i - 1][j - p[i]] + val[i]
                );
            }
        }
    }

    for (ll i = n; i >= 1; i--)
    {
        for (ll j = 0; j <= m; j++)
        {
            dp2[i][j] = dp2[i + 1][j];

            if (j >= p[i])
            {
                dp2[i][j] = max(
                    dp2[i][j],
                    dp2[i + 1][j - p[i]] + val[i]
                );
            }
        }
    }

    ll X = dp[n][m];

    string ans = "";

    for (ll i = 1; i <= n; i++)
    {
        bool without = false;
        bool with = false;

        for (ll j = 0; j <= m; j++)
        {
            ll cur = dp[i - 1][j] + dp2[i + 1][m - j];

            if (cur == X)
            {
                without = true;
                break;
            }
        }

        if (p[i] <= m)
        {
            for (ll j = 0; j + p[i] <= m; j++)
            {
                ll cur = dp[i - 1][j] + dp2[i + 1][m - p[i] - j];

                if (cur == X - val[i])
                {
                    with = true;
                    break;
                }
            }
        }

        if (!without && with)
            ans += 'A';
        else if (without && with)
            ans += 'B';
        else
            ans += 'C';
    }

    cout << ans << '\n';

    return 0;
}