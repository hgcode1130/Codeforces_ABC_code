#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

using namespace std;


void solve() {
    int n;
    cin >> n;
    double p = 1.0 / n, sum = 0;
    for (int i = 1; i <= 1e2; i++)
    {
        sum += i * p;
        p *= (n + 2.0)/(2 * n);
    }
    cout << sum << "\n";
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}