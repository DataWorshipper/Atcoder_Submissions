#include <bits/stdc++.h>
using namespace std;

#define v vector
#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define f(arr, n) for(ll i = 0; i < n; i++) cin >> arr[i];

typedef __int128 i128;

int main()
{
    fast_io;

    ll n, k;
    cin >> n >> k;

    v<ll> a(n);
    f(a, n);

    i128 lo = 1;
    i128 hi = 0;

    for (ll i = 0; i < n; i++)
    {
        hi = max(hi, (i128)a[i] + (i128)(i + 1) * k);
    }

    i128 ans = 0;

    while (lo <= hi)
    {
        i128 mid = lo + (hi - lo) / 2;

        i128 need = 0;

        for (ll i = 0; i < n; i++)
        {
            if ((i128)a[i] < mid)
            {
                need += (mid - a[i] + i) / (i + 1);

                if (need > k)
                    break;
            }
        }

        if (need <= k)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    auto print128 = [&](i128 x)
    {
        if (x == 0)
        {
            cout << 0;
            return;
        }

        string s;

        while (x)
        {
            s.push_back('0' + x % 10);
            x /= 10;
        }

        reverse(all(s));
        cout << s;
    };

    print128(ans);
    cout << '\n';
}