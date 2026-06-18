#include <bits/stdc++.h>
using namespace std;
#define v vector
#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define f(arr, n) for(ll i = 0; i < n; i++) cin >> arr[i];

const ll MOD = 1e9+7;;
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
    ll n,k;
    cin>>n>>k;
    v<ll>a(n);
    f(a,n);
    v<v<ll>>dp(n,v<ll>(k+1,0));
    v<v<ll>>pref(n,v<ll>(k+1,0));
    for(ll x=0;x<=a[0];x++)
    {
        dp[0][x]=1;
    }
    pref[0][0]=dp[0][0];
    for(ll x=1;x<=k;x++)
    {
        pref[0][x]=(pref[0][x-1]+dp[0][x])%MOD;
    }
    
    for(ll i=1;i<n;i++)
    {
        for(ll x=0;x<=k;x++)
        {   
            if(x-a[i]-1>=0)
            dp[i][x]=(pref[i-1][x]-pref[i-1][x-a[i]-1]+MOD)%MOD;
            else
            dp[i][x]=(pref[i-1][x])%MOD;
            if(x==0)
            pref[i][x]=(dp[i][x])%MOD;
            else
            pref[i][x]=(pref[i][x-1]+dp[i][x])%MOD;
        }
    }
    cout<<dp[n-1][k]%MOD<<endl;
     
}