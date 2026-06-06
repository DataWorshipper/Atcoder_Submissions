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

ll k;

ll cnt(v<ll>& a)
{
    unordered_map<ll,ll> mp;
    mp.reserve(a.size() * 4);

    mp[0] = 1;

    ll p = 0;
    ll ans = 0;

    for(auto x : a)
    {
        p += x;

        auto it = mp.find(p - k);

        if(it != mp.end())
            ans += it->second;

        mp[p]++;
    }

    return ans;
}

int main()
{
    fast_io;

    ll h,w;
    cin >> h >> w >> k;

    v<string> g(h);

    for(ll i=0;i<h;i++)
        cin >> g[i];

    if(h > w)
    {
        v<string> ng(w,string(h,'0'));

        for(ll i=0;i<h;i++)
        {
            for(ll j=0;j<w;j++)
            {
                ng[j][i] = g[i][j];
            }
        }

        g = move(ng);
        swap(h,w);
    }

    ll ans = 0;

    for(ll t=0;t<h;t++)
    {
        v<ll> a(w,0);

        for(ll b=t;b<h;b++)
        {
            for(ll c=0;c<w;c++)
            {
                a[c] += g[b][c] - '0';
            }

            ans += cnt(a);
        }
    }

    cout << ans << endl;
}