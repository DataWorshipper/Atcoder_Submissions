#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Fenwick
{
    vector<ll> bit;
    int n;

public:
    Fenwick(int sz)
    {
        n = sz;
        bit.assign(n + 1, 0);
    }

    void update(int idx, ll val)
    {
        while(idx <= n)
        {
            bit[idx] ^= val;
            idx += (idx & -idx);
        }
    }

    ll query(int idx)
    {
        ll ans = 0;

        while(idx > 0)
        {
            ans ^= bit[idx];
            idx -= (idx & -idx);
        }

        return ans;
    }

    ll rangeQuery(int l, int r)
    {
        return query(r) ^ query(l - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<ll> A(N + 1);

    Fenwick bit(N);

    for(int i = 1; i <= N; i++)
    {
        cin >> A[i];
        bit.update(i, A[i]);
    }

    while(Q--)
    {
        int T, X;
        ll Y;

        cin >> T >> X >> Y;

        if(T == 1)
        {
            A[X] ^= Y;
            bit.update(X, Y);
        }
        else
        {
            cout << bit.rangeQuery(X, Y) << '\n';
        }
    }

    return 0;
}