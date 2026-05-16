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
string s;
cin>>s;
ll ans=0;
for(ll i=0;i<s.size();i++)
{
    if(s[i]=='C')
    {
        ll left=i+1;
        ll right=(s.size()-i);
        ll maxi=min(left,right);
        ans+=maxi;
    }
}
cout<<ans<<endl;

}
