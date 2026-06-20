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
bool check( v<pair<ll,ll>>&arr,ll d,ll k)
{
    ll lastr=-4e11;
    ll cnt=0;
    for(ll i=0;i<arr.size();i++)
    {
        ll right=arr[i].first;
        ll left=arr[i].second;
        if(left>=lastr+d)
        {
            lastr=right;
            cnt++;
        }
    }
    return cnt>=k;
    
}
int main()
{   
    fast_io;
    ll n,k;
    cin>>n>>k;
    v<pair<ll,ll>>arr;
    for(ll i=0;i<n;i++)
    {
        ll l,r;
        cin>>l>>r;
        arr.pb({r,l});
    }
    sort(all(arr));
    ll low=1;
    ll high=1e9;
    ll ans=-1;
    while(low<=high)
    {
        ll mid=low+(high-low)/2;
        if(check(arr,mid,k))
        {
            ans=mid;
            low=mid+1;
        }
        else
        high=mid-1;
    }
    cout<<ans<<endl;
}