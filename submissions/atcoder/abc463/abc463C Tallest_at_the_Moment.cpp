#include <bits/stdc++.h>
using namespace std;
#define v vector
#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define f(arr, n) for(ll i = 0; i < n; i++) cin >> arr[i];

const ll MOD = 998244353;
const ll MAXD = 1000005;

vector<ll> sieve(ll sieve_size)
{
    vector<ll> s(sieve_size + 1, 1);
    s[0] = s[1] = 0;

    for (ll i = 2; i * i <= sieve_size; i++)
    {
        if (s[i] == 1)
        {
            for (ll j = i * i; j <= sieve_size; j += i)
            {
                s[j] = 0;
            }
        }
    }
    return s;
}

int main()
{
    fast_io;

    ll N;
    cin >> N;

    vector<ll> H(N), L(N);

    for(ll i = 0; i < N; i++)
        cin >> H[i] >> L[i];

    vector<ll> suf(N);
    suf[N - 1] = H[N - 1];

    for(ll i = N - 2; i >= 0; i--)
        suf[i] = max(suf[i + 1], H[i]);

    ll Q;
    cin >> Q;

    while(Q--)
    {
        ll T;
        cin >> T;

        ll idx = lower_bound(all(L), T + 1) - L.begin();

        cout << suf[idx] <<endl;
    }

    return 0;
}