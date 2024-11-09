//#include<bits/stdc++.h>
//
//using namespace std;
//
//const int MX = 1 * 1000000 + 10;
//#define LL long long
//#define inf 1e15
//
//#define lson now<<1
//#define rson now<<1|1
//
//#define none -1145141919180
////这个来判断究竟存不存在 covertag
//
//inline LL read()
//{
//	LL x = 0, f = 1; char ch = getchar();
//	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
//	while (isdigit(ch)) { x = x * 10 + ch - 48; ch = getchar(); }
//	return x * f;
//}
//
//LL n, Q;
//LL w[MX];
//
//struct tTree
//{
//	LL covertag;
//	LL sumtag;
//	LL maxn;
//}tree[MX << 2];
//
//inline void pushup(LL now)
//{
//	tree[now].maxn = max(tree[lson].maxn, tree[rson].maxn);
//}
//
//inline void coverdown(LL now)
//{
//	if (tree[now].covertag != -1145141919810)
//	{
//		//printf("WTH\n");
//		tree[lson].sumtag = tree[rson].sumtag = 0;
//		tree[lson].maxn = tree[rson].maxn = tree[now].covertag;
//		tree[lson].covertag = tree[rson].covertag = tree[now].covertag;
//		tree[now].covertag = -1145141919810;
//	}
//}
//
//inline void sumdown(LL now)
//{
//	if (tree[now].sumtag)
//	{
//		coverdown(now);
//		tree[lson].maxn += tree[now].sumtag, tree[rson].maxn += tree[now].sumtag;
//		tree[lson].sumtag += tree[now].sumtag, tree[rson].sumtag += tree[now].sumtag;
//		tree[now].sumtag = 0;
//	}
//}
//
//inline void pushdown(LL now)
//{
//	coverdown(now), sumdown(now);
//}
//
//inline void build(LL now, LL l, LL r)
//{
//	if (l == r)
//	{
//		tree[now].maxn = w[l];
//		tree[now].covertag = -1145141919810;
//		tree[now].sumtag = 0;
//		return;
//	}
//	LL mid = (l + r) >> 1;
//	build(lson, l, mid), build(rson, mid + 1, r);
//	pushup(now);
//}
//
//inline void tree_add(LL now, LL l, LL r, LL nl, LL nr, LL k)
//{
//	if (nl <= l && nr >= r)
//	{
//		coverdown(now);
//		tree[now].maxn += k;
//		tree[now].sumtag += k;
//		return;
//	}
//	pushdown(now);
//	LL mid = (l + r) >> 1;
//	if (nl <= mid) tree_add(lson, l, mid, nl, nr, k);
//	if (nr >= mid + 1) tree_add(rson, mid + 1, r, nl, nr, k);
//	pushup(now);
//}
//
//inline void cover_add(LL now, LL l, LL r, LL nl, LL nr, LL k)
//{
//	if (nl <= l && nr >= r)
//	{
//		tree[now].sumtag = 0;
//		tree[now].maxn = k;
//		tree[now].covertag = k;
//		return;
//	}
//	pushdown(now);
//	LL mid = (l + r) >> 1;
//	if (nl <= mid) cover_add(lson, l, mid, nl, nr, k);
//	if (nr >= mid + 1) cover_add(rson, mid + 1, r, nl, nr, k);
//	pushup(now);
//}
//
//inline LL get_max(LL now, LL l, LL r, LL nl, LL nr)
//{
//	if (nl <= l && nr >= r)
//	{
//		return tree[now].maxn;
//	}
//	pushdown(now);
//	LL mid = (l + r) >> 1;
//	LL res = -inf;
//	if (nl <= mid) res = max(res, get_max(lson, l, mid, nl, nr));
//	if (nr >= mid + 1) res = max(res, get_max(rson, mid + 1, r, nl, nr));
//	return res;
//}
//
//int main(int argc, char const* argv[])
//{
//	n = read(), Q = read();
//	for (LL i = 1; i <= n; i++) w[i] = read();
//	build(1, 1, n);
//	for (int i = 1; i <= n * 4; i++) tree[i].covertag = -1145141919810;
//	while (Q--)
//	{
//		LL pos, l, r;
//		pos = read(), l = read(), r = read();
//		if (pos == 1)
//		{
//			LL k = read();
//			cover_add(1, 1, n, l, r, k);
//		}
//		else if (pos == 2)
//		{
//			LL k = read();
//			tree_add(1, 1, n, l, r, k);
//		}
//		else
//		{
//			printf("%lld\n", get_max(1, 1, n, l, r));
//		}
//	}
//	return 0;
//}