#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<string> grid(H);

    int sx = -1, sy = -1;
    int tx = -1, ty = -1;

    for (int i = 0; i < H; i++)
    {
        cin >> grid[i];

        for (int j = 0; j < W; j++)
        {
            if (grid[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            else if (grid[i][j] == 'T')
            {
                tx = i;
                ty = j;
            }
        }
    }

    int N;
    cin >> N;

    vector<vector<ll>> med(H, vector<ll>(W, 0));

    for (int i = 0; i < N; i++)
    {
        int r, c;
        ll e;

        cin >> r >> c >> e;

        --r;
        --c;

        med[r][c] = e;
    }

    if (med[sx][sy] == 0)
    {
        cout << "No\n";
        return 0;
    }

    vector<vector<ll>> best(H, vector<ll>(W, -1));

    queue<pair<int, int>> q;

    best[sx][sy] = med[sx][sy];
    q.push({sx, sy});

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        ll curr = best[x][y];

        if (curr == 0)
            continue;

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;

            if (grid[nx][ny] == '#')
                continue;

            ll candidate = curr - 1;
            candidate = max(candidate, med[nx][ny]);

            if (candidate > best[nx][ny])
            {
                best[nx][ny] = candidate;
                q.push({nx, ny});
            }
        }
    }

    if (best[tx][ty] >= 0)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}