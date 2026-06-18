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
    ll n,k;
    cin>>n>>k;
    v<ll>a(n);
    f(a,n);
    ll m=*max_element(all(a));
    unordered_map<ll,ll>freq;
    for(auto it:a)
    {
        freq[it]++;
    }
    unordered_map<ll,ll>cnt;
    for(ll d=1;d<=m;d++)
    {
        for(ll x=d;x<=m;x+=d)
        {
            cnt[d]+=freq[x];
        }
    }
    unordered_map<ll,ll>mpp;
    for(ll d=1;d<=m;d++)
    {
        if(cnt[d]<k)
        continue;
        else
        {
            for(ll x=d;x<=m;x+=d)
            {
                mpp[x]=d;
            }
        }
    }
    for(ll i=0;i<n;i++)
    {
        cout<<mpp[a[i]]<<endl;
    }
    
    
    
}