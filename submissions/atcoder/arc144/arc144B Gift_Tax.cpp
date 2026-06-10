#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> A(n);

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i];
    }

    auto check = [&](long long C) {
        long long need = 0;
        long long give = 0;

        for (auto x : A) {
            if (x < C) {
                need += (C - x + a - 1) / a;
            } else {
                give += (x - C) / b;
            }
        }

        return give >= need;
    };

    long long lo = *min_element(A.begin(), A.end());
    long long hi = sum / n;
    long long ans = lo;

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;

        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << '\n';
}