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
ll binpow(ll base, ll exp)
{
ll res = 1;
base %= MOD;

while(exp > 0)
{
    if(exp & 1)
        res = (res * base) % MOD;

    base = (base * base) % MOD;
    exp >>= 1;
}

return res;


}

int main()
{   
    fast_io;
    ll n,m,k;
    cin>>n>>m>>k;
    if(k==0)
    {
        cout<<binpow(m,n)%MOD;
        return 0;
    }
    v<v<ll>>dp(n,v<ll>(m+1,0));
    v<v<ll>>pref(n,v<ll>(m+1,0));
    dp[0][0]=0;
    for(ll x=1;x<=m;x++)
    {
        dp[0][x]=1;
    }
    pref[0][0]=dp[0][0];
    for(ll x=1;x<=m;x++)
    {
        pref[0][x]=(pref[0][x-1]+dp[0][x])%MOD;
    }
    for(ll i=1;i<n;i++)
    {
        for(ll x=1;x<=m;x++)
        {   
            if(x-k>=1)
            dp[i][x]=(dp[i][x]+pref[i-1][x-k]-pref[i-1][0]+MOD)%MOD;
           
          if(x+k <= m)
            dp[i][x] =(dp[i][x]+ pref[i-1][m] - pref[i-1][x+k-1]+MOD)%MOD;

            
            
            pref[i][x]=(pref[i][x-1]+dp[i][x])%MOD;
        }
    }
    
    ll sum=0;
    for(ll x=1;x<=m;x++)
    {
        sum=(sum+dp[n-1][x])%MOD;
    }
    cout<<sum<<endl;
    
    
}