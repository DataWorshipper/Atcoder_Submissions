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
const ll MOD=998244353;
ll dp[101][101][101];
ll f1(ll taken,ll index,ll rem,v<ll>&a,ll len)
{
    if(index==a.size())
    {
        if(taken==len && rem==0)
        {
            return 1;
        }
        else
        return 0;
    }
    if(dp[taken][index][rem]!=-1)
    return dp[taken][index][rem];
    ll take=f1(taken+1,index+1,(rem+a[index])%len,a,len)%MOD;
    ll not_take=f1(taken,index+1,rem,a,len)%MOD;
    return dp[taken][index][rem]=(take+not_take)%MOD;
}
int main()
{   
    fast_io;
    ll n;
    cin>>n;
    v<ll>a(n);
    f(a,n);
    ll ans=0;
    for(ll len=1;len<=n;len++)
    {
        memset(dp,-1,sizeof(dp));
        ans=(ans+f1(0,0,0,a,len))%MOD;
      
        
    }
    cout<<ans%MOD<<endl;
    
    
    
}