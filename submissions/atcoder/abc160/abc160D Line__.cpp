#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int src, vector<vector<int>>& adj, int N)
{
    vector<int> dist(N+1,-1);
    vector<int> vis(N+1,0);

    queue<pair<int,int>> q;

    q.push({src,0});
    vis[src]=1;

    while(!q.empty())
    {
        auto [node,d]=q.front();
        q.pop();

        dist[node]=d;

        for(auto child:adj[node])
        {
            if(!vis[child])
            {
                vis[child]=1;
                q.push({child,d+1});
            }
        }
    }

    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,X,Y;
    cin>>N>>X>>Y;

    vector<vector<int>> adj(N+1);

   
    for(int i=1;i<N;i++)
    {
        adj[i].push_back(i+1);
        adj[i+1].push_back(i);
    }

    
    adj[X].push_back(Y);
    adj[Y].push_back(X);

   vector<vector<int>> mat(N+1,vector<int>(N+1));

for(int src=1;src<=N;src++)
{
    mat[src]=bfs(src,adj,N);
}

vector<int> ans(N,0);

for(int i=1;i<=N;i++)
{
    for(int j=i+1;j<=N;j++)
    {
        ans[mat[i][j]]++;
    }
}
  for(int k=1;k<N;k++)
    {
        cout<<ans[k]<<"\n";
    }
}
