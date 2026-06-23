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
    ll W,H;
    cin>>W>>H;
    ll N;
    cin>>N;
    v<pair<ll,ll>>arr;
    
    ll c=N;
    while(c--)
    {
        ll p,q;
        cin>>p>>q;
        arr.pb({p,q});
    }
    ll A;
    cin>>A;
    v<ll>a;
    a.pb(0);
    for(ll i=1;i<=A;i++)
    {   
        ll f;
        cin>>f;
        a.pb(f);
    }
    a.pb(W);
    
     ll B;
    cin>>B;
    v<ll>b;
    b.pb(0);
    for(ll i=1;i<=B;i++)
    {
        ll f;
        cin>>f;
        b.pb(f);
    }
    b.pb(H);
    map<v<ll>,ll>mpp;
    for(auto it:arr)
    {
        ll x=it.first;
        ll y=it.second;
        auto idx_x=upper_bound(a.begin(),a.end(),x);
        auto idx_y=upper_bound(b.begin(),b.end(),y);
        v<ll>res;
        res.pb(*idx_x);
        res.pb(*(idx_x-1));
        res.pb(*(idx_y-1));
        res.pb(*(idx_y));
        mpp[res]++;

    }
    ll h=0;
    ll l=N;
    for(auto it:mpp)
    {
        h=max(h,it.second);
        l=min(l,it.second);
    }
    if(mpp.size()<(A+1)*(B+1))
    {
        l=0;
    }
    cout<<l<<" "<<h<<endl;
    
    
}