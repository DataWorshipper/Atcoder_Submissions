/*
    Author    : MishkatIT
    Created   : Saturday 06-06-2026 22:53:45
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ld = long double;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int inf = 1e9;
const ll linf = 1e18;

void Solve() {
    ll n, l, r;
    cin >> n >> l >> r;

    ll ans = 0;

    auto fun = [&](int i) {
        ll mn = 1LL << i;
        ll mx = 1LL << (i + 1);
        mx--;
        mn = max(mn, l);
        mx = min(mx, r);
        if (mn > mx) return 0LL;
        return mx - mn + 1;
    };

    for (int i = 60; i >= 0; i--) {
        if (n & (1LL << i)) {
            ans += fun(i);
        }
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solve();
    return 0;
}