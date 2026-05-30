#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> A(N), B(M);

    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;

    sort(A.begin(), A.end());

    multiset<long long> ms(B.begin(), B.end());

    int ans = 0;

    for (int i = 0; i < N && !ms.empty(); i++) {
        auto it = ms.begin();

        if (*it <= 2 * A[i]) {
            ans++;
            ms.erase(it);
        }
    }

    cout << ans << '\n';
    return 0;
}