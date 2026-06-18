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

class TrieNode
{   public:
    v<TrieNode*>arr;
    ll cnt;
    public:
    TrieNode()
    {
        arr.resize(26,nullptr);
        cnt=0;
    }
};

class Trie
{   public:
  TrieNode* root;
  public:
  Trie()
  {
      root=new TrieNode();
  }
  void insert(string &s)
  { 
      TrieNode* node=root;
      for(ll i=0;i<s.size();i++)
      {
          ll idx=s[i]-'a';
          if(node->arr[idx]!=nullptr)
            {
                node=node->arr[idx];
                node->cnt++;
            }
            else
            {
            node->arr[idx]=new TrieNode();
            node=node->arr[idx];
            node->cnt++;
            }
      }
  }
  
};
ll ans=0;
void dfs(TrieNode* node)
{
    ll x = node->cnt;
    ans += x*(x-1)/2;

    for(int i=0;i<26;i++)
    {
        if(node->arr[i]!=nullptr)
            dfs(node->arr[i]);
    }
}
int main()
{   
    fast_io;
    ll n;
    cin>>n;
    v<string>in(n);
    for(ll i=0;i<n;i++)
    {
        cin>>in[i];
    }
    Trie obj;
    for(ll i=0;i<n;i++)
    {
        obj.insert(in[i]);
    }
    dfs(obj.root);
    cout<<ans<<endl;
    
    
}