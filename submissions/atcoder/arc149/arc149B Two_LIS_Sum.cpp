#include <bits/stdc++.h>
using namespace std;
#define v vector
#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io;

    int n;
    cin >> n;

    v<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    v<pair<int,int>> p(n);

    for (int i = 0; i < n; i++) {
        p[i] = {a[i], b[i]};
    }

    sort(p.begin(), p.end());

    v<int> temp;
    temp.push_back(p[0].second);

    for (int i = 1; i < n; i++) {
        int x = p[i].second;

        if (x > temp.back()) {
            temp.push_back(x);
        }
        else {
            int idx = lower_bound(temp.begin(), temp.end(), x) - temp.begin();
            temp[idx] = x;
        }
    }

    cout << n + (int)temp.size() << '\n';

    return 0;
}