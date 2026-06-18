#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF = 1e18;

int N, K, P;

ll C[105];
int A[105][5];

ll dp[105][6][6][6][6][6];

ll dfs(int idx, int a, int b, int c, int d, int e)
{
    a = min(a, P);
    b = min(b, P);
    c = min(c, P);
    d = min(d, P);
    e = min(e, P);

    int cur[5] = {a,b,c,d,e};

    bool ok = true;

    for(int i=0;i<K;i++)
    {
        if(cur[i] < P)
        {
            ok = false;
            break;
        }
    }

    if(ok)
        return 0;

    if(idx == N)
        return INF;

    ll &ans = dp[idx][a][b][c][d][e];

    if(ans != -1)
        return ans;

    ans = dfs(idx+1, a, b, c, d, e);

    int na = a;
    int nb = b;
    int nc = c;
    int nd = d;
    int ne = e;

    if(K >= 1) na = min(P, a + A[idx][0]);
    if(K >= 2) nb = min(P, b + A[idx][1]);
    if(K >= 3) nc = min(P, c + A[idx][2]);
    if(K >= 4) nd = min(P, d + A[idx][3]);
    if(K >= 5) ne = min(P, e + A[idx][4]);

    ll take = dfs(idx+1, na, nb, nc, nd, ne);

    if(take != INF)
        ans = min(ans, C[idx] + take);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> P;

    for(int i=0;i<N;i++)
    {
        cin >> C[i];

        for(int j=0;j<K;j++)
            cin >> A[i][j];
    }

    memset(dp, -1, sizeof(dp));

    ll ans = dfs(0,0,0,0,0,0);

    if(ans == INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}