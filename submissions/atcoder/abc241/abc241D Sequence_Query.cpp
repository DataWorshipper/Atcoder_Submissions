#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    multiset<long long> ms;

    while (Q--) {
        int t;
        cin >> t;

        if (t == 1) {
            long long x;
            cin >> x;
            ms.insert(x);
        }
        else if (t == 2) {
            long long x;
            int k;
            cin >> x >> k;

            auto it = ms.upper_bound(x);

            bool ok = true;
            for (int i = 0; i < k; i++) {
                if (it == ms.begin()) {
                    ok = false;
                    break;
                }
                --it;
            }

            if (!ok) cout << -1 << '\n';
            else cout << *it << '\n';
        }
        else {
            long long x;
            int k;
            cin >> x >> k;

            auto it = ms.lower_bound(x);

            bool ok = true;

            if (it == ms.end()) ok = false;

            for (int i = 1; i < k && ok; i++) {
                ++it;
                if (it == ms.end()) {
                    ok = false;
                    break;
                }
            }

            if (!ok) cout << -1 << '\n';
            else cout << *it << '\n';
        }
    }

    return 0;
}