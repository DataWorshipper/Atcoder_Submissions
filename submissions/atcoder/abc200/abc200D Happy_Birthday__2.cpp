#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int lim = min(N, 8);

    vector<int> seen(200, -1);

    for (int mask = 1; mask < (1 << lim); mask++) {
        int rem = 0;

        for (int i = 0; i < lim; i++) {
            if (mask & (1 << i)) {
                rem = (rem + A[i]) % 200;
            }
        }

        if (seen[rem] == -1) {
            seen[rem] = mask;
        } else {
            int mask1 = seen[rem];
            int mask2 = mask;

            vector<int> B, C;

            for (int i = 0; i < lim; i++) {
                if (mask1 & (1 << i)) B.push_back(i + 1);
                if (mask2 & (1 << i)) C.push_back(i + 1);
            }

            cout << "Yes\n";

            cout << B.size();
            for (int x : B) cout << ' ' << x;
            cout << '\n';

            cout << C.size();
            for (int x : C) cout << ' ' << x;
            cout << '\n';

            return 0;
        }
    }

    cout << "No\n";
    return 0;
}