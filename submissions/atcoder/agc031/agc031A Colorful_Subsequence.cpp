/*
    Author    : MishkatIT
    Created   : Friday 05-06-2026 17:14:50
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
    int n; cin >> n;
    string s; cin >> s;
    vector<int> f(26);
    for (auto& i : s) {
        f[i - 'a']++;
    }
    ll ans = 1;
    for (int i = 0; i < 26; i++) {
        if (f[i]) {
            ans = (ans * (f[i] + 1)) % mod;
        }
    }
    cout << ans - 1 << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solve();
    return 0;
}