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

    ll x, q;
    cin >> x >> q;

priority_queue<ll> left;
priority_queue<ll, vector<ll>, greater<ll>> right;

    left.push(x);

    while(q--)
    {
        ll a, b;
        cin >>a>>b;

        if(a <= left.top())
        {
            left.push(a);
        }
        else
        {
            right.push(a);
        }
    if(b <= left.top())
        {
            left.push(b);
        }
        else
        {
            right.push(b);
        }
while(left.size() < right.size() + 1)
        {
            left.push(right.top());
            right.pop();
        }
while(left.size() > right.size() + 1)
        {
            right.push(left.top());
            left.pop();
        }
if(!right.empty() && left.top() > right.top())
        {
            ll x = left.top();
            ll y = right.top();

            left.pop();
            right.pop();

            left.push(y);
            right.push(x);
        }

        cout << left.top() << endl;
    }
}