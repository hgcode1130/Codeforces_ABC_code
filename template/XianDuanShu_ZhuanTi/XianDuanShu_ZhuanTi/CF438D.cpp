//#include<iostream>
//using namespace std;
//int n, m;
//typedef long long int ll;
//const int maxn = 1e5 + 10;
//struct seg {
//	int l, r;
//	ll s, m;
//	seg() { s = 0, m = 0; }
//	seg(int a, int b) :l(a), r(b) {}
//}tree[maxn << 2];
//void build(int id, int l, int r) {
//	if (l == r) {
//		tree[id] = { l,r };
//		scanf("%d", &tree[id].s);
//		tree[id].m = tree[id].s;
//		return;
//	}
//	int mid = l + r >> 1;
//	tree[id] = { l,r };
//	build(id << 1, l, mid);
//	build((id << 1) + 1, mid + 1, r);
//	tree[id].s = tree[id << 1].s + tree[(id << 1) + 1].s;
//	tree[id].m = max(tree[id << 1].m, tree[(id << 1) + 1].m);
//}
//void update(int id, int a, ll b) {
//	if (tree[id].l == tree[id].r && tree[id].l == a) {
//		tree[id].s = b;
//		tree[id].m = b;
//		return;
//	}
//	int mid = tree[id].l + tree[id].r >> 1;
//	if (a <= mid)update(id << 1, a, b);
//	else update((id << 1) + 1, a, b);
//	tree[id].s = tree[id << 1].s + tree[(id << 1) + 1].s;
//	tree[id].m = max(tree[id << 1].m, tree[(id << 1) + 1].m);
//}
//void update2(int id, int l, int r, ll x) {
//	if (tree[id].m < x)return;
//	if (tree[id].l == tree[id].r && tree[id].l >= l && tree[id].r <= r) {
//		tree[id].s %= x;
//		tree[id].m = tree[id].s;
//		return;
//	}
//	int mid = tree[id].l + tree[id].r >> 1;
//	if (r <= mid)update2(id << 1, l, r, x);
//	else if (l > mid)update2((id << 1) + 1, l, r, x);
//	else update2(id << 1, l, r, x), update2((id << 1) + 1, l, r, x);
//	tree[id].m = max(tree[id << 1].m, tree[(id << 1) + 1].m);
//	tree[id].s = tree[id << 1].s + tree[(id << 1) + 1].s;
//}
//ll query(int id, int l, int r) {
//	if (tree[id].l >= l && tree[id].r <= r) {
//		return tree[id].s;
//	}
//	ll ans = 0;
//	int mid = tree[id].l + tree[id].r >> 1;
//	if (r <= mid)return ans += query(id << 1, l, r);
//	else if (l > mid)return ans += query((id << 1) + 1, l, r);
//	else return ans += query(id << 1, l, r) + query((id << 1) + 1, l, r);
//}
//void solved() {
//	scanf("%d%d", &n, &m);
//	build(1, 1, n);
//	int l, r, k, x;
//	while (m--) {
//		int ins; scanf("%d", &ins);
//		if (1 == ins) {
//			scanf("%d%d", &l, &r);
//			printf("%lld\n", query(1, l, r));
//		}
//		if (2 == ins) {
//			scanf("%d%d%d", &l, &r, &x);
//			update2(1, l, r, x);
//		}
//		if (3 == ins) {
//			scanf("%d%d", &k, &x);
//			update(1, k, x);
//		}
//	}
//}
//int main() {
//	solved();
//	return 0;
//}
