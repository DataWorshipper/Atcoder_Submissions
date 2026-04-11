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
 
 ll dfs(ll index,ll pos,ll n,v<ll>&a)
 {
     if(index==n)
     {
         return 0;
     }
     
     ll right=a[index]+pos;
     ll ans_r=dfs(index+1,right,n,a);
     if(pos<0 &&right>=0||pos>0 &&right<=0)
     {
         ans_r=max(ans_r,1+dfs(index+1,right,n,a));
     }
     ll left=pos-a[index];
     ll ans_l=dfs(index+1,left,n,a);
      if(pos<0 &&left>=0||pos>0 &&left<=0)
     {
         ans_l=max(ans_l,1+dfs(index+1,left,n,a));
     }
     return  max(ans_l,ans_r);
     
 }
 
int main()
{   
    fast_io;
ll n;
cin>>n;
v<ll>a(n);
f(a,n);
for(ll i=0;i<n;i++)
{
    a[i]*=2;
}
ll ans=dfs(0,1,n,a);
cout<<ans<<endl;


}
