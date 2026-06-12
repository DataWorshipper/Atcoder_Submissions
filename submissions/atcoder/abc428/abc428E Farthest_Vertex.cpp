#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define v vector
#define pb push_back

v<v<int>> adj;
int n;

void dfs(int node, int parent, int depth, v<int>& dist)
{
    dist[node] = depth;

    for(auto child : adj[node])
    {
        if(child != parent)
            dfs(child, node, depth + 1, dist);
    }
}

int get_farthest(v<int>& dist)
{
    int node = 1;

    for(int i = 2; i <= n; i++)
    {
        if(dist[i] > dist[node])
            node = i;
        else if(dist[i] == dist[node] && i > node)
            node = i;
    }

    return node;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    adj.resize(n + 1);

    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

   
    v<int> d1(n + 1);
    dfs(1, 0, 0, d1);

    int A = get_farthest(d1);

 
    v<int> distA(n + 1);
    dfs(A, 0, 0, distA);

    int B = get_farthest(distA);

  
    v<int> distB(n + 1);
    dfs(B, 0, 0, distB);

    for(int i = 1; i <= n; i++)
    {
        if(distA[i] > distB[i])
            cout << A;
        else if(distB[i] > distA[i])
            cout << B;
        else
            cout << max(A, B);

        cout<<endl;
    }

    return 0;
}