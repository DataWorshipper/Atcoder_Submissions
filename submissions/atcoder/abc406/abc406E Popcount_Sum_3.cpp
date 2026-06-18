#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;

const ll MOD = 998244353;

string bits;
int K;

pll dp[65][65];
bool vis[65][65];
ll pow2[65];

pll dfs(int pos, int ones, bool tight)
{
    if(ones > K) return {0, 0};

    if(pos == (int)bits.size())
    {
        if(ones == K) return {1, 0};
        return {0, 0};
    }

    if(!tight && vis[pos][ones])
        return dp[pos][ones];

    ll cnt = 0;
    ll sum = 0;

    int lim = tight ? bits[pos] - '0' : 1;

    int bitPos = (int)bits.size() - 1 - pos;

    for(int b = 0; b <= lim; b++)
    {
        auto child = dfs(
            pos + 1,
            ones + b,
            tight && (b == lim)
        );

        cnt = (cnt + child.first) % MOD;

        ll curSum = child.second;

        if(b)
        {
            curSum = (curSum +
                     child.first * pow2[bitPos]) % MOD;
        }

        sum = (sum + curSum) % MOD;
    }

    if(!tight)
    {
        vis[pos][ones] = true;
        dp[pos][ones] = {cnt, sum};
    }

    return {cnt, sum};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pow2[0] = 1;
    for(int i = 1; i < 65; i++)
        pow2[i] = (pow2[i - 1] * 2) % MOD;

    int T;
    cin >> T;

    while(T--)
    {
        long long N;
        cin >> N >> K;

        bits.clear();

        while(N)
        {
            bits.push_back((N & 1) + '0');
            N >>= 1;
        }

        if(bits.empty())
            bits = "0";

        reverse(bits.begin(), bits.end());

        memset(vis, 0, sizeof(vis));

        cout << dfs(0, 0, true).second % MOD << '\n';
    }

    return 0;
}