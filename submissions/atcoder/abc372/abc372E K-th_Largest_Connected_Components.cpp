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
void mergeset(set<ll>&a,set<ll>&b)
{
    for(auto it:b)
    {
        a.insert(it);
    }
    if(a.size()<=10)
    {
        return;
    }
    while(a.size() > 10)
{
    a.erase(a.begin());
}

}
class DSU
{public:
  v<ll>parent;
  v<ll>rank;
  v<set<ll>>comp;
  public:
  DSU(ll n)
  {
      parent.resize(n+1);
      rank.resize(n+1);
      comp.resize(n+1);
      for(ll i=1;i<=n;i++)
      {
          parent[i]=i;
          comp[i].insert(i);
      }
  }
  public:
  ll findparent(ll node)
  {
      if (node==parent[node])
      return node;
      return parent[node]=findparent(parent[node]);
  }
  public:
  void merge(ll u,ll v)
  {
    ll pu=findparent(u);
    ll pv=findparent(v);
    if(pu==pv)
    return;
    ll ru=rank[pu];
    ll rv=rank[pv];
    if(ru<rv)
    {
        parent[pu]=pv;
        mergeset(comp[pv],comp[pu]);
    }
    else if (ru>rv)
    {
        parent[pv]=pu;
        mergeset(comp[pu],comp[pv]);
    }
    else
    {
       parent[pv]=pu;
    mergeset(comp[pu],comp[pv]);
    rank[pu]++;
    }
  }
};
int main()
{   
    fast_io;
    ll N,Q;
    cin>>N>>Q;
    DSU dsu(N);
    while(Q--)
    {
        ll type;
        cin>>type;
        if(type==1)
        {
            ll u,v;
            cin>>u>>v;
            dsu.merge(u,v);
        }
        else
        {
            ll v,k;
            cin>>v>>k;
           
             
            ll p=dsu.findparent(v);
            
            auto &arr=dsu.comp[p];
            if(arr.size()<k)
            {
                cout<<-1<<endl;
                continue;
            }
            auto idx=arr.rbegin();
            advance(idx,k-1);
            cout<<*idx<<endl;
               
            
        }
    }
    
}