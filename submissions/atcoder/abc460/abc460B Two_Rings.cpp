#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long x1, y1, r1;
        long long x2, y2, r2;

        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;

        long long dx = x1 - x2;
        long long dy = y1 - y2;

        long long d2 = dx * dx + dy * dy;

        long long mn = (r1 - r2) * (r1 - r2);
        long long mx = (r1 + r2) * (r1 + r2);

        cout << (mn <= d2 && d2 <= mx ? "Yes" : "No") << '\n';
    }

    return 0;
}