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
    ll n,d;
    cin>>n>>d;
    ll mx_t=1e6+5;
    v<ll>diff(mx_t,0);
    ll z=n;
    while(z--)
    {
        ll x,y;
        cin>>x>>y;
        ll r=y-d+1;
        if(x<=y-d)
        {
        diff[x]+=1;
        diff[r]-=1;
        }
        
    }
    ll curr=0;
    ll ans=0;
    for(ll i=0;i<(ll)diff.size();i++)
    {
       curr+=diff[i];
       if(curr>=2)
       {
           ans+=(curr)*(curr-1)/2;
       }
       
    }
    cout<<ans<<endl;
}