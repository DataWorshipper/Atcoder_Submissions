#include <bits/stdc++.h>
using namespace std;

#define ll long long

int a, b;
ll C;

int bits[60];
int dp[61][61][61];

pair<int, int> choice[61][61][61];

bool f(int idx, int cntX, int cntY)
{
    if(idx == 60)
    {
        return (cntX == a && cntY == b);
    }

    if(dp[idx][cntX][cntY] != -1)
        return dp[idx][cntX][cntY];

    bool ans = false;

    if(bits[idx] == 1)
    {
      
        if(f(idx + 1, cntX + 1, cntY))
        {
            choice[idx][cntX][cntY] = {1, 0};
            ans = true;
        }

     
        if(!ans && f(idx + 1, cntX, cntY + 1))
        {
            choice[idx][cntX][cntY] = {0, 1};
            ans = true;
        }
    }
    else
    {
      
        if(f(idx + 1, cntX, cntY))
        {
            choice[idx][cntX][cntY] = {0, 0};
            ans = true;
        }


        if(!ans && f(idx + 1, cntX + 1, cntY + 1))
        {
            choice[idx][cntX][cntY] = {1, 1};
            ans = true;
        }
    }

    return dp[idx][cntX][cntY] = ans;
}

int main()
{
    cin >> a >> b >> C;

    for(int i = 0; i < 60; i++)
        bits[i] = (C >> i) & 1;

    memset(dp, -1, sizeof(dp));

    bool ok = f(0, 0, 0);

    if(!ok)
    {
        cout << -1 << '\n';
        return 0;
    }

    ll X = 0, Y = 0;

    int idx = 0, cntX = 0, cntY = 0;

    while(idx < 60)
    {
        auto [bx, by] = choice[idx][cntX][cntY];

        if(bx)
            X |= (1LL << idx);

        if(by)
            Y |= (1LL << idx);

        cntX += bx;
        cntY += by;
        idx++;
    }

    cout << X << " " << Y << '\n';

    return 0;
}