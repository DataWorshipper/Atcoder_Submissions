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
void gen(ll idx,v<ll>&subset,set<ll>&ans,v<ll>&arr)
{
    if(idx==arr.size())
    {
        ll sum=0;
        for(auto it:subset)
        {
            sum+=it;
        }
        ans.insert(sum);
        return;
    }
    subset.pb(arr[idx]);
    gen(idx+1,subset,ans,arr);
    subset.pop_back();
    gen(idx+1,subset,ans,arr);
    
}
int main()
{   
    fast_io;
    ll n,t;
    cin>>n>>t;
    v<ll>a(n);
    f(a,n);
    ll mid=n/2;
    v<ll>left(a.begin(),a.begin()+mid);
    v<ll>right(a.begin()+mid,a.end());
    set<ll>subset_l,subset_r;
    v<ll>curr;
    gen(0,curr,subset_l,left);
    gen(0,curr,subset_r,right);
    ll ans=LLONG_MIN;
    for(auto it:subset_l)
    {
        ll x=it;
        ll target=t-x;
        auto idx=subset_r.upper_bound(target);
        if(idx!=subset_r.begin())
        {
            --idx;
            ans=max(ans,x+*idx);
            
            
        }
    }
    cout<<ans<<endl;
    
    
}
