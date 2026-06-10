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
bool check(string &s, string &t)
{
    ll i=0;
    ll j=0;
    while(i<s.size() && j<t.size())
    {
        if(s[i]==t[j])
        {
            i++;
            j++;
        }
        else
        j++;
    }
    return i==s.size();
}
int main()
{   
    fast_io;
    ll n;
    cin>>n;
    string s,t;
    cin>>s>>t;
     string s_copy=s;
     string t_copy=t;
     sort(all(s_copy));
     sort(all(t_copy));
     if(s_copy!=t_copy)
     {
        cout<<-1<<endl;
        return 0;
     }
    
    ll lo=0;
    ll hi=n;
    ll ans=-1;
    while(lo<=hi)
    {
     ll mid=lo+(hi-lo)/2;
     string a=s.substr(mid);
     if(check(a,t)==true)
     {
      ans=mid;
      hi=mid-1;
     }
     else
     lo=mid+1;
    }
    cout<<ans<<endl;
    
    
}