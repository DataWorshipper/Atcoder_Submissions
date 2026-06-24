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
ll f1(ll mask,v<v<ll>>&a,ll N)
{   
    ll score=0;
    for(ll i=0;i<N;i++)
    {   ll ba=(mask>>i)&1;
        for(ll j=i+1;j<N;j++)
        {
            ll bb=(mask>>j)&1;
            if(ba==1 &&bb==1)
            {
                score+=a[i][j];
            }
        }
    }
    return score;
}
int main()
{   
    fast_io;
    ll N;
    cin>>N;
    v<v<ll>>a(N,v<ll>(N));
    for(ll i=0;i<N;i++)
    {
        for(ll j=0;j<N;j++)
        {
            cin>>a[i][j];
        }
    }
    unordered_map<ll,ll>mpp;
    for(ll mask=0;mask<(1<<N);mask++)
    {
        mpp[mask]=f1(mask,a,N);
    }
    v<ll>dp(1<<N,0);
   
    for(ll mask=0;mask<(1<<N);mask++)
    {
        dp[mask]=mpp[mask];
        for(ll sub=mask;sub;sub=(sub-1)&mask)
        {
            dp[mask]=max(dp[mask],dp[sub]+dp[mask^sub]);
        }
    }
    cout<<dp[(1<<N)-1]<<endl;
    
    
}