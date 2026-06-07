#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 998244353;

ll dp[81][81][81];

ll LEN;
vector<ll> A;
unordered_map<ll, vector<int>> pos;

ll f(int taken, int prev, int curr)
{
    if (taken == LEN) return 1;

    ll &ans = dp[taken][prev][curr];
    if (ans != -1) return ans;

    ans = 0;

    ll target = 2LL * A[curr] - A[prev];

    auto it = pos.find(target);
    if (it == pos.end()) return ans;

    auto &v = it->second;

    auto start = upper_bound(v.begin(), v.end(), curr);

    for (auto itr = start; itr != v.end(); ++itr)
    {
        int nxt = *itr;
        ans = (ans + f(taken + 1, curr, nxt)) % MOD;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    A.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        pos[A[i]].push_back(i);
    }

    vector<ll> answer(N + 1, 0);

    answer[1] = N;

    for (int len = 2; len <= N; len++)
    {
        LEN = len;

        memset(dp, -1, sizeof(dp));

        ll curAns = 0;

        for (int prev = 0; prev < N; prev++)
        {
            for (int curr = prev + 1; curr < N; curr++)
            {
                curAns = (curAns + f(2, prev, curr)) % MOD;
            }
        }

        answer[len] = curAns;
    }

    for (int len = 1; len <= N; len++)
    {
        cout << answer[len] % MOD;
        if (len != N) cout << ' ';
    }
    cout << '\n';

    return 0;
}