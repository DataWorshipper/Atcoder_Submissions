/*
    Author    : MishkatIT
    Created   : Friday 05-06-2026 17:24:28
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
    map<ll, ll> mp;
    mp[0] = 1;
    ll pref = 0;
    ll ans = 0;
    for (auto&  i : v) {
        pref += i;
        ans += mp[pref];
        mp[pref]++;
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solve();
    return 0;
}