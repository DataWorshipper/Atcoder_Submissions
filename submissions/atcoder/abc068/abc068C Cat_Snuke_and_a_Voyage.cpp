#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin>>N>>M;

    vector<vector<int>> adj(N+1);

    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<pair<int,int>> q;

  
    q.push({1,0});

    vector<int> vis(N+1,0);
    vis[1]=1;

    while(!q.empty())
    {
        auto [node,d]=q.front();
        q.pop();

        if(node==N && d==2)
        {
            cout<<"POSSIBLE\n";
            return 0;
        }

        if(d==2) continue;

        for(auto child:adj[node])
        {
            if(!vis[child])
            {
                vis[child]=1;
                q.push({child,d+1});
            }
        }
    }

    cout<<"IMPOSSIBLE\n";
}