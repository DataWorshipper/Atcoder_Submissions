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
cin>>n;
v<ll>a(n);
f(a,n);
unordered_map<ll,ll>mpp;
for(auto it:a)
{
    mpp[it]++;
}
v<ll>b;
ll c=0;
ll sum=0;
for(auto it:mpp)
{
    if(it.second>=2)
    {
        b.pb(it.second);
        sum+=it.second;
    }
    else
    c++;
    
}
ll ans=0;
for(auto it:b){
    ll term=it*(it-1)/2;
    term*=(sum+c-it);
    ans+=term;
    
}
cout<<ans<<endl;
}
