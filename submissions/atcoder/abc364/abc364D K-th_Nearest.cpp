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
ll f1(vector<ll>& a, ll b, ll k)
{
    ll low = 0;
    ll high = 2e8;
    ll ans = -1;

    while(low <= high)
    {
        ll mid = low + (high - low) / 2;

        ll cnt =
            upper_bound(a.begin(), a.end(), b + mid)
          - lower_bound(a.begin(), a.end(), b - mid);

        if(cnt >= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}
int main()
{   
    fast_io;
    ll N,Q;
    cin>>N>>Q;
    v<ll>a(N);
    f(a,N);
    sort(all(a));
    while(Q--)
    {
        ll b,k;
        cin>>b>>k;
        cout<<f1(a,b,k)<<endl;
        
    }
    
    
    
}