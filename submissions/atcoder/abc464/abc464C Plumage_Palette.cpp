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

    ll N, M;
    cin >> N >> M;

    v<ll> A(N), D(N), B(N);

    for(ll i = 0; i < N; i++)
    {
        cin >> A[i] >> D[i] >> B[i];
    }

    v<v<ll>> changes(M + 1);

    v<ll> freq(N + 1, 0);

    ll distinct = 0;

    for(ll i = 0; i < N; i++)
    {
        ll cur;

        if(D[i] == 1)
        {
            cur = B[i];
        }
        else
        {
            cur = A[i];
            changes[D[i]].pb(i);
        }

        freq[cur]++;

        if(freq[cur] == 1)
        {
            distinct++;
        }
    }

    for(ll day = 1; day <= M; day++)
    {
        for(auto idx : changes[day])
        {
            freq[A[idx]]--;

            if(freq[A[idx]] == 0)
            {
                distinct--;
            }

            freq[B[idx]]++;

            if(freq[B[idx]] == 1)
            {
                distinct++;
            }
        }

        cout << distinct << endl;
    }

    return 0;
}