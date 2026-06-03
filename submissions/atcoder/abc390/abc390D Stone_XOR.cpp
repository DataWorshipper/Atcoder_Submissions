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
v<ll>groups;
unordered_set<ll>s;
void dfs(ll idx,v<ll>&a)
{
    if(idx==a.size())
    {
        ll xr=0;
        for(auto it:groups)
        xr^=it;
        s.insert(xr);
        return;
    }
    

    for(ll i=0;i<groups.size();i++)
    {
        groups[i]+=a[idx];
        dfs(idx+1,a);
        groups[i]-=a[idx];
    }
    groups.pb(a[idx]);
    dfs(idx+1,a);
    groups.pop_back();
}
int main()
{   
    fast_io;
    ll n;
    cin>>n;
    v<ll>a(n);
    f(a,n);
   
    dfs(0,a);
    cout<<s.size()<<endl;
    
}