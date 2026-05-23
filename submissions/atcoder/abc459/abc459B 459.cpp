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

    ll n;
    cin >> n;

    ll d = n;

    v<string> arr;

    while(d--)
    {
        string s;
        cin >> s;
        arr.pb(s);
    }

    for(ll i = 0; i < n; i++)
    {
        char ch = arr[i][0];

        if(ch=='a' || ch=='b' || ch=='c')
            cout << 2;

        else if(ch=='d' || ch=='e' || ch=='f')
            cout << 3;

        else if(ch=='g' || ch=='h' || ch=='i')
            cout << 4;

        else if(ch=='j' || ch=='k' || ch=='l')
            cout << 5;

        else if(ch=='m' || ch=='n' || ch=='o')
            cout << 6;

        else if(ch=='p' || ch=='q' || ch=='r' || ch=='s')
            cout << 7;

        else if(ch=='t' || ch=='u' || ch=='v')
            cout << 8;

        else
            cout << 9;
    }

}