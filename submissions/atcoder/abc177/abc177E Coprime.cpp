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
    ll n;
    cin>>n;
    unordered_map<ll,ll>freq;
     unordered_map<ll,ll>cnt;
    v<ll>a(n);
    ll g=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        g=gcd(g,a[i]);
        freq[a[i]]++;
    }
    ll mn=*max_element(all(a));
    for(ll i=1;i<=mn;i++)
    {
        for(ll d=i;d<=mn;d+=i)
        cnt[i]+=freq[d];
    }
    bool flag=true;
    for(ll i=2;i<=mn;i++)
    {
        if(cnt[i]>1)
        {
            flag=false;
            break;
        }
    }
    
    if(flag)
    {
          cout<<"pairwise coprime"<<endl;
          return 0;
    }
     else if(g==1 && flag==false)
    {
        cout<<"setwise coprime"<<endl;
        return 0;
    }
    else
    {
        cout<<"not coprime"<<endl;
    }
    
}