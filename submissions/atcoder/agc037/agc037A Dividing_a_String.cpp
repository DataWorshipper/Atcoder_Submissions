/*
    Author    : MishkatIT
    Created   : Friday 05-06-2026 16:20:03
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
    string str; cin >> str;
    int ans = 0;
    string last;
    string cur;
    for (auto& i : str) {
        cur += i;
        if (cur != last) {
            ans++;
            last = cur;
            cur.clear();
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