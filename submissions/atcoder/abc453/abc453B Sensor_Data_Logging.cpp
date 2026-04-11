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
    ll t,x;
    cin>>t>>x;
    v<ll>a(t+1);
    f(a,t+1);
    cout<<0<<" "<<a[0]<<endl;
    ll last=a[0];
    for(ll i=1;i<=t;i++)
    {
        if(abs(a[i]-last)>=x)
        {
            cout<<i<<" "<<a[i]<<endl;
            last=a[i];
        }
    }
    
    
  
}
