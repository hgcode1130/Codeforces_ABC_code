#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef long long i64;
typedef pair<int, int> PII;
const int N = 1e6 + 10 , MOD = 1e9 + 7;
int n, k, l, a[N], b[N], id[N], le[N];
//如何设计一个状态数为nk的DP？
//在前k个节中选，且最后一个数是a[j]的条件的子序列个数
void solve() {
   int n , k  , l;
   cin >> n >> l >> k;
   for (int i = 0; i < n; i++) cin >> a[i] , id[i] = i , b[i] = a[i];
   sort(b , b + n);
   sort(id , id + n, [&](int i, int j) { return a[i] < a[j]; });
   vector<vector<int>> dp(k + 1,  vector<int>(n , 0));
   int ans = 0;
   //找出每个点比它小的数的位置le
   for(int i = 0 ; i < n ; i++) le[id[i]] = id[upper_bound(b , b + n , b[i]) - b - 1];

   for(int i = 1 ; i <= k ; i++)
   {
      for(int j = 0 ; j < n ; j++)
        {
            if(i == 1) dp[i][j] = 1;
            else
            {
                dp[i][j] += dp[i - 1][le[j]];
            }
            if(l >= (i - 1) * n + j + 1) ans = ans + (1 + (l - (i - 1) * n - j - 1) / n) % MOD * dp[i][j] , ans %= MOD;
        } 
        for(int j = 1 ; j < n ; j++) dp[i][id[j]] = (dp[i][id[j - 1]] + dp[i][id[j]]) % MOD;
   }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t --) solve();
    return 0;
}