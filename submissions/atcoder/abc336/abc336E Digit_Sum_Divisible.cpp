#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string N;
ll dp[15][2][2][136][136];
int targetSum;

ll f(int idx, int tight, int started, int curSum, int rem) {
    if (idx == N.size()) {
        return (started && curSum == targetSum && rem == 0);
    }

    if (dp[idx][tight][started][curSum][rem] != -1)
        return dp[idx][tight][started][curSum][rem];

    ll ans = 0;
    int limit = tight ? (N[idx] - '0') : 9;

    for (int d = 0; d <= limit; d++) {
        int newTight = tight && (d == limit);

        if (!started && d == 0) {
          
            ans += f(idx + 1, newTight, 0, curSum, rem);
        } else {
            if (curSum + d > targetSum) continue;

            int newRem = (rem * 10 + d) % targetSum;
            ans += f(idx + 1, newTight, 1,
                     curSum + d, newRem);
        }
    }

    return dp[idx][tight][started][curSum][rem] = ans;
}

int main() {
    cin >> N;

    ll ans = 0;

    for (targetSum = 1; targetSum <= 126; targetSum++) {
        memset(dp, -1, sizeof(dp));
        ans += f(0, 1, 0, 0, 0);
    }

    cout << ans << endl;

    return 0;
}