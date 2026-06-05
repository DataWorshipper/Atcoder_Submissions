/*
    Author    : MishkatIT
    Created   : Friday 05-06-2026 17:28:21
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
    string x;
    cin >> x;
    int boss = 0;
    for (auto& i : x) {
        boss += i - '0';
    }
    int ans = x.front() - '0' - 1;
    ans += (x.size() - 1) * 9;
    ans = max(ans, boss);
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solve();
    return 0;
}