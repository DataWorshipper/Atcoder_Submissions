/*
    Author    : MishkatIT
    Created   : Saturday 06-06-2026 22:07:22
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
    int ans = 1;
    int last = v.front();
    char dir = '#';
    for (int i = 0; i < n; i++) {
        if (dir == '#') {
            if (v[i] > last) dir = 'u';
            else if (v[i] < last) dir = 'd';
        } else {
            if (dir == 'u') {
                if (v[i] < last) {
                    ans++;
                    dir = '#';
                } 
            } else {
                if (v[i] > last) {
                    ans++;
                    dir = '#';
                }
            }
        }
        last = v[i];
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solve();
    return 0;
}