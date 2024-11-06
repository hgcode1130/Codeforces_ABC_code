//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//ll n, m, ans, f[50];
//struct x {
//	ll a, b;
//}a[50];
//bool cmp(x a, x b) { return a.b > b.b; }
//void dfs(ll x, ll now, ll sum, ll rest) {
//	if (x == n + 1) {
//		ans = max(ans, sum); return;
//	}
//	if (rest >= a[x].a)
//		dfs(x + 1, now + a[x].b, sum + now, rest - a[x].a);
//	dfs(x + 1, now, sum, rest);
//	return;
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) cin >> a[i].a;
//	for (int i = 1; i <= n; i++) cin >> a[i].b;
//	sort(a + 1, a + 1 + n, cmp);
//	for (int i = n - 1; i >= 1; i--)
//		f[i] = f[i + 1] + a[i].b * (n - i);
//	dfs(1, 0, 0, m);
//	cout << ans;
//	return 0;
//}