/*
    Author    : MishkatIT
    Created   : Saturday 06-06-2026 22:20:01
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
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    ll cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        a[i] += cur;
        ll rem = a[i] % b[i];
        if (rem) {
            cur += b[i] - rem;
        }
    }
    cout << cur;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solve();
    return 0;
}