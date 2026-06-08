#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 998244353;

string s;
int n;
vector<vector<ll>> dp;

ll f(int idx, int prev)
{
    if(idx == n)
        return 1;

    if(dp[idx][prev + 1] != -1)
        return dp[idx][prev + 1];

    ll ans = f(idx + 1, prev); // skip

    int cur = s[idx] - 'a';

    if(prev == -1 || cur != prev)
    {
        ans += f(idx + 1, cur);
        ans %= MOD;
    }

    return dp[idx][prev + 1] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    n = s.size();

    dp.assign(n, vector<ll>(4, -1));

    cout << (f(0, -1) - 1 + MOD) % MOD << '\n';
}