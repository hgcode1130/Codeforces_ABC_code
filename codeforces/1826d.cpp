#include <bits/stdc++.h>

using i64 = long long;
using i64u = unsigned long long;
using f80 = long double;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  std::vector f(2, std::vector<int>(n));
  for (int i = 1; i < n; i++) {
    f[0][i] = std::max(f[0][i - 1], b[i - 1]) - 1;
  }
  for (int i = n - 2; i >= 0; i--) {
    f[1][i] = std::max(f[1][i + 1], b[i + 1]) - 1;
  }

  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    ans = std::max(ans, f[0][i] + f[1][i] + b[i]);
  }

  std::cout << ans << "\n";

  return;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}