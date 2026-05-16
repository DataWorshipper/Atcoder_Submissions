#include <bits/stdc++.h>
using namespace std;

#define v vector
#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define f(arr, n) for(ll i = 0; i < n; i++) cin >> arr[i];

vector<ll> sieve(ll sieve_size)
{
    vector<ll> s(sieve_size + 1, 1);

    s[0] = s[1] = 0;

    for(ll i = 2; i * i <= sieve_size; i++)
    {
        if(s[i] == 1)
        {
            for(ll j = i * i; j <= sieve_size; j += i)
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

    ll h, w;
    cin >> h >> w;

    v<v<ll>> ans(h, v<ll>(w, 0));

    for(ll i = 0; i < h; i++)
    {
        for(ll j = 0; j < w; j++)
        {
            ll row = i;
            ll col = j;

            ll cnt = 0;

            for(ll x = 0; x < h; x++)
            {
                for(ll y = 0; y < w; y++)
                {
                    if(abs(row - x) + abs(col - y) == 1)
                    {
                        cnt++;
                    }
                }
            }

            ans[i][j] = cnt;
        }
    }

    for(ll i = 0; i < h; i++)
    {
        for(ll j = 0; j < w; j++)
        {
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }
}