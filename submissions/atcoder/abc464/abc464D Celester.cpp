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

    ll T;
    cin >> T;

    while(T--)
    {
        ll N;
        cin >> N;

        string S;
        cin >> S;

        v<ll> X(N);
        v<ll> Y(N - 1);

        f(X, N);
        f(Y, N - 1);

        v<v<ll>> dp(N + 1, v<ll>(2, 0));

        for(ll idx = N - 1; idx >= 1; idx--)
        {
            ll cur = (S[idx] == 'S');

            for(ll prev = 0; prev < 2; prev++)
            {
                ll gain1 = 0;

                if(prev == 0 && cur == 1)
                    gain1 += Y[idx - 1];

                ll ans1 = gain1 + dp[idx + 1][cur];

                ll nxt = cur ^ 1;

                ll gain2 = -X[idx];

                if(prev == 0 && nxt == 1)
                    gain2 += Y[idx - 1];

                ll ans2 = gain2 + dp[idx + 1][nxt];

                dp[idx][prev] = max(ans1, ans2);
            }
        }

        ll first = (S[0] == 'S');

        ll ans1 = dp[1][first];

        ll ans2 = -X[0] + dp[1][first ^ 1];

        cout << max(ans1, ans2) << "\n";
    }
}