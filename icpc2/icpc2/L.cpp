//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//#define int long long
//
//using namespace std;
//
//const int MOD = 998244353;
//
//int gcd(int a, int b) {
//    if (!b) return a;
//    return gcd(b, a % b);
//}
//
//int ksm(int a, int b) {
//    int res = 1;   
//    while (b) {
//        if (b & 1) res = res * a % MOD;
//        a = a * a % MOD;
//        b >>= 1;
//    }
//    return res;
//}
//
//int inv(int x) {
//    return ksm(x, MOD - 2);
//}
//
//struct Num {
//    int x, y;
//
//    Num operator+ (const Num& rhs) {
//        x = x * rhs.y + y * rhs.x;
//        y = y * rhs.y;
//        int g = gcd(x, y);
//        x /= g;
//        y /= g;
//        return Num({ x, y });
//    }
//
//    Num operator* (const Num& rhs) {
//        x *= rhs.x;
//        y *= rhs.y;
//        int g = gcd(x, y);
//        x /= g;
//        y /= g;
//        return Num({ x, y });
//    }
//};
//int x, y, a0, a1, b;
//
//int work(int x, int y) {
//    if (x == y) return  a0 * inv(a0 + a1) % MOD;
//    else if (x > y) {
//        int t = (x - 1) / y;
//        return  ((ksm(a0 + a1, t) - ksm(a1, t) + MOD) % MOD * inv( ksm(a0 + a1, t)) % MOD + ksm(a1, t) * inv(ksm(a0 + a1, t)) % MOD * work(x - t * y, y) % MOD) % MOD;
//    }
//    else {
//        int t = (y - 1) / x;
//        return ksm(a0, t)*inv( ksm(a0 + a1, t))% MOD * work(x, y - t * x) % MOD;
//    }
//}
//
//void solve() {
//    cin >> x >> y >> a0 >> a1 >> b;
//    cout << work(x, y) % MOD << "\n";
//}
//
//signed main()
//{
//    ios::sync_with_stdio(0), cin.tie(0);
//    int T = 1;
//    cin >> T;
//    while (T--) {
//        solve();
//    }
//    return 0;
//}