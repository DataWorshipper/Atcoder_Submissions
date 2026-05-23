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

    ll t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        ll n = s.size();

        v<ll> freq(26, 0);

        for(char c : s)
        {
            freq[c - 'a']++;
        }

        ll mx = *max_element(all(freq));

        if(mx > (n + 1) / 2)
        {
            cout << "No\n";
            continue;
        }

        v<pair<ll,char>> arr;

        for(ll i = 0; i < 26; i++)
        {
            if(freq[i])
            {
                arr.pb({freq[i], char('a' + i)});
            }
        }

        sort(rall(arr));

        string ans(n, ' ');

        ll idx = 0;

        for(auto it : arr)
        {
            ll f = it.first;
            char ch = it.second;

            while(f--)
            {
                ans[idx] = ch;

                idx += 2;

                if(idx >= n)
                {
                    idx = 1;
                }
            }
        }

        bool ok = true;

        for(ll i = 1; i < n; i++)
        {
            if(ans[i] == ans[i - 1])
            {
                ok = false;
                break;
            }
        }

        if(ok)
        {
            cout << "Yes\n";
            cout << ans << '\n';
        }
        else
        {
            cout << "No\n";
        }
    }
}