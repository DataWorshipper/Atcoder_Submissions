/*
    Author    : MishkatIT
    Created   : Friday 05-06-2026 17:21:08
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
    vector<int> v(n);
    for (auto& i : v) {
        cin >> i;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) {
            ans++;
            v[i] = 101;
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