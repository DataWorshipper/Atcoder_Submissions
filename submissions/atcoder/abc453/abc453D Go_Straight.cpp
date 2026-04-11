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

int main()
{   
    fast_io;
    ll h,w;
    cin>>h>>w;
    v<v<char>>grid(h,v<char>(w));
    
    ll s_x=-1, s_y=-1, end_x=-1, end_y=-1;
    
    for(ll i=0;i<h;i++)
    {
        for(ll j=0;j<w;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='S')
            {
                s_x=i;
                s_y=j;
            }
            if(grid[i][j]=='G')
            {
                end_x=i;
                end_y=j;
            }
        }
    }

    ll nx[]={-1, 0, 1, 0};
    ll ny[]={0, 1, 0, -1};
    char m[] = {'U', 'R', 'D', 'L'};
    
    v<v<v<bool>>>vis(h,v<v<bool>>(w,v<bool>(5, false)));
    v<v<v<v<ll>>>>par(h,v<v<v<ll>>>(w,v<v<ll>>(5)));
    
    queue<v<ll>>q;
    q.push({s_x,s_y,4});
    vis[s_x][s_y][4]=true;
    
    ll final_x=-1;
    ll final_y=-1;
    ll final_dir=-1;
    
    while(!q.empty())
    {
        v<ll>state=q.front();
        ll curr_x=state[0];
        ll curr_y=state[1];
        ll curr_dir=state[2];
        q.pop();
        
        if(curr_x==end_x && curr_y==end_y)
        {
            final_x=curr_x;
            final_y=curr_y;
            final_dir=curr_dir;
            break;
        }
        
        for(ll i=0;i<4;i++)
        {
            if(curr_dir!=4)
            {
                if(grid[curr_x][curr_y]=='o' && i!=curr_dir)
                {
                    continue;
                }
                if(grid[curr_x][curr_y]=='x' && i==curr_dir)
                {
                    continue;
                }
            }
            
            ll new_x=curr_x+nx[i];
            ll new_y=curr_y+ny[i];
            
            if(new_x>=0 && new_x<h && new_y>=0 && new_y<w && grid[new_x][new_y]!='#' && !vis[new_x][new_y][i])
            {
                q.push({new_x,new_y,i});
                vis[new_x][new_y][i]=true;
                par[new_x][new_y][i]={curr_x, curr_y, curr_dir, (ll)m[i]};
            }
        }
    }
    
    if (final_dir == -1) {
        cout <<"No"<<endl;
        return 0;
    }
    
    string path="";
    ll curr_r = final_x;
    ll curr_c = final_y;
    ll curr_d = final_dir;
    
    while(curr_d!=4)
    {
        v<ll>parent=par[curr_r][curr_c][curr_d];
        path+=(char)parent[3];
        curr_r=parent[0];
        curr_c=parent[1];
        curr_d=parent[2];
    }
    
    reverse(path.begin(),path.end());
    cout<<"Yes"<<endl;
    cout << path << endl;

    return 0;
}