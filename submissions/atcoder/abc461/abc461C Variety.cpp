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
    ll n,k,m;
    cin>>n>>k>>m;
    map<ll,multiset<ll>>mpp;
    ll d=n;
    while(d--)
    {
        ll c,v;
        cin>>c>>v;
        mpp[c].insert(v);
    }
  using pll = pair<ll,ll>;
    priority_queue<pll,vector<pll>,greater<pll>>pq;
    for(auto it:mpp)
    {
        pq.push({*it.second.rbegin(), it.first});
        if(pq.size()>m)
        pq.pop();
    }
    unordered_map<ll,ll>mpp2;
    ll sum=0;
    while(pq.size()>0)
    {
        pair<ll,ll>p1=pq.top();
        mpp2[p1.second]=1;
        sum+=p1.first;
        pq.pop();
    }
    for(auto &it : mpp)
{
    if(mpp2[it.first])
    {
        it.second.erase(prev(it.second.end()));
    }
}
    v<ll>arr;
    for(auto it:mpp)
    {
         multiset<ll>ms=it.second;
         for(auto el:ms)
         {
             arr.pb(el);
         }
    }
    sort(arr.rbegin(),arr.rend());
    ll need=k-m;
    for(ll cnt=0;cnt<need;cnt++)
    {
        sum+=arr[cnt];
    }
    cout<<sum<<endl;
    
    
    
}