

#include<bits/stdc++.h>

using namespace std;
using i64 = long long;


i64 n, m, k;
map<i64, i64> dp[30][30];
i64 a[30][30];
i64 ans;

void dfs(int x, int y, i64 sum) {
    if (x + y == (n + m) / 2 + 1) {
        dp[x][y][sum] ++;
        return ;
    }
    if (x + 1 <= n) dfs(x + 1, y, sum ^ a[x + 1][y]);
    if (y + 1 <= m) dfs(x, y + 1, sum ^ a[x][y + 1]);
}

void dfs2(int x, int y, i64 sum) {
    if (x + y == (n + m) / 2 + 1) {
        ans += dp[x][y][k ^ sum ^ a[x][y]];
        return ;
    }
    if (x - 1 >= 1) dfs2(x - 1, y, sum ^ a[x - 1][y]);
    if (y - 1 >= 1) dfs2(x, y - 1, sum ^ a[x][y - 1]);
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];

    dfs(1, 1, a[1][1]);
    dfs2(n, m, a[n][m]);

    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t --) solve();
    return 0;
}