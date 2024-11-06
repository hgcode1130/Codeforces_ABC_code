//#pragma GCC optimize(3)
//#include <bits/stdc++.h>
//#define debug(x) cout<<#x<<":"<<x<<endl;
//#define dl(x) printf("%lld\n",x);
//#define di(x) printf("%d\n",x);
//#define _CRT_SECURE_NO_WARNINGS
//#define pb push_back
//#define mp make_pair
//#define all(x) (x).begin(),(x).end()
//#define fi first
//#define se second
//#define SZ(x) ((int)(x).size())
//using namespace std;
//typedef long long ll;
//typedef unsigned long long ull;
//typedef pair<int, int> PII;
//typedef vector<int> VI;
//const ll INF = 0x3f3f3f3f3f3f3f3f;
//const int N = 2e5 + 10;
//const ll mod = 1000000007;
//const double eps = 1e-5;
//const double PI = acos(-1);
//template<typename T>inline void read(T& a) {
//	char c = getchar(); T x = 0, f = 1; while (!isdigit(c)) { if (c == '-')f = -1; c = getchar(); }
//	while (isdigit(c)) { x = (x << 1) + (x << 3) + c - '0'; c = getchar(); } a = f * x;
//}
//int gcd(int a, int b) { return (b > 0) ? gcd(b, a % b) : a; }
//ll a[N];
//PII q[N];
//int n, m;
//vector<double> nums;
//
//struct Node {
//	int l, r;
//	int cnt;
//	ll sum;
//}tr[N << 2];
//
//struct Q {
//	int op, x;
//	ll val;
//}ques[N];
//
//int find(int x) {
//	return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
//}
//
//void push(int u) {
//	tr[u].cnt = tr[u << 1].cnt + tr[u << 1 | 1].cnt;
//	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
//}
//
//void build(int u, int l, int r) {
//	tr[u] = { l,r,0,0 };
//	if (l == r) return;
//	int mid = (l + r) >> 1;
//	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
//}
//
//void modify(int u, int x, int k) {
//	if (tr[u].l == tr[u].r) {
//		if (k == 1) tr[u].cnt++, tr[u].sum += nums[x - 1];
//		else tr[u].cnt--, tr[u].sum -= nums[x - 1];
//		return;
//	}
//	int mid = (tr[u].l + tr[u].r) >> 1;
//	if (x <= mid) modify(u << 1, x, k);
//	else modify(u << 1 | 1, x, k);
//	push(u);
//}
//
//int query_cnt(int u, int l, int r) {
//	if (tr[u].l >= l && tr[u].r <= r) return tr[u].cnt;
//	int res = 0, mid = (tr[u].l + tr[u].r) >> 1;
//	if (l <= mid) res = query_cnt(u << 1, l, r);
//	if (r > mid) res += query_cnt(u << 1 | 1, l, r);
//	return res;
//}
//
//ll query_sum(int u, int l, int r) {
//	if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
//	ll res = 0;
//	int mid = (tr[u].l + tr[u].r) >> 1;
//	if (l <= mid) res = query_sum(u << 1, l, r);
//	if (r > mid) res += query_sum(u << 1 | 1, l, r);
//	return res;
//}
//
//void solve(ll x) {
//	double l = 0, r = 1e15;
//	double ans = 0;
//	while (r - l >= eps) {
//		double mid = (l + r) / 2;
//		int p = upper_bound(all(nums), mid) - nums.begin();
//		if (query_cnt(1, 1, p) * mid >= query_sum(1, 1, p) * 1.0 + x) r = ans = mid;
//		else l = mid;
//	}
//	printf("%lf\n", ans);
//}
//
//
//int main() {
//	read(n), read(m);
//	for (int i = 1; i <= n; i++) read(a[i]), nums.pb(a[i]);
//	for (int i = 1; i <= m; i++) {
//		int op, x;
//		ll val;
//		read(op);
//		if (op == 1) {
//			read(x), read(val);
//			ques[i] = { op,x,val };
//			nums.pb(val);
//		}
//		else {
//			read(val);
//			ques[i] = { 0,0,val };
//		}
//	}
//	sort(nums.begin(), nums.end());
//	nums.erase(unique(nums.begin(), nums.end()), nums.end());
//	nums.pb(1e15);
//	int mx = nums.size();
//	build(1, 1, mx);
//	for (int i = 1; i <= n; i++) {
//		modify(1, find(a[i]), 1);
//	}
//	for (int i = 1; i <= m; i++) {
//		int op = ques[i].op;
//		if (op == 1) {
//			modify(1, find(a[ques[i].x]), -1);
//			a[ques[i].x] = ques[i].val;
//			modify(1, find(a[ques[i].x]), 1);
//		}
//		else {
//			solve(ques[i].val);
//		}
//	}
//	return 0;
//}
