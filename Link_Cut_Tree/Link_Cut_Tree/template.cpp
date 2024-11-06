#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
#define N 200010
#define M 1010

using namespace std;
int n, m, sy;
int dep[N], top[N], siz[N], dfn[N], fath[N], son[N], w[N], pre[N];

int read() {
	int s = 0, f = 0; char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return f ? -s : s;
}

namespace Seg {
#define lson rt << 1
#define rson rt << 1 | 1
	struct node {
		int sum, lazy, len, dep;
	}tree[N << 2];
	void build(int rt, int l, int r) {
		tree[rt].len = r - l + 1, tree[rt].dep = tree[rt].lazy = 0;
		if (l == r) {
			tree[rt].sum = w[pre[l]];
			tree[rt].dep = dep[pre[l]];
			return;
		}
		int mid = (l + r) >> 1;
		build(lson, l, mid);
		build(rson, mid + 1, r);
	}
	void push_down(int rt) {
		if (!tree[rt].lazy) return;
		if (tree[lson].dep != 0)
			if (tree[lson].dep % 2 == 1) tree[lson].sum += tree[rt].lazy;
			else tree[lson].sum -= tree[rt].lazy;
		if (tree[rson].dep != 0)
			if (tree[rson].dep % 2 == 1) tree[rson].sum += tree[rt].lazy;
			else tree[rson].sum -= tree[rt].lazy;
		tree[lson].lazy += tree[rt].lazy;
		tree[rson].lazy += tree[rt].lazy;
		tree[rt].lazy = 0;
	}
	void update(int rt, int c, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			tree[rt].lazy += c;
			if (tree[rt].dep)
				if (tree[rt].dep % 2 == 1) tree[rt].sum += c;
				else tree[rt].sum -= c;
			return;
		}
		push_down(rt);
		int mid = (l + r) >> 1;
		if (L <= mid) update(lson, c, l, mid, L, R);
		if (R > mid) update(rson, c, mid + 1, r, L, R);
	}
	int query(int rt, int l, int r, int pos) {
		if (l == r) return tree[rt].sum;
		push_down(rt);
		int mid = (l + r) >> 1;
		if (pos <= mid) return query(lson, l, mid, pos);
		else return query(rson, mid + 1, r, pos);
	}
}

namespace Cut {
	int cnt, add_edge, head[N << 1];
	struct node {
		int next, to;
	}edge[N << 1];
	void add(int from, int to) {
		edge[++add_edge].next = head[from];
		edge[add_edge].to = to;
		head[from] = add_edge;
	}
	void dfs(int x, int fa) {
		siz[x] = 1, fath[x] = fa, dep[x] = dep[fa] + 1;
		for (int i = head[x]; i; i = edge[i].next) {
			int to = edge[i].to;
			if (to == fa) continue;
			dfs(to, x), siz[x] += siz[to];
			if (siz[son[x]] < siz[to]) son[x] = to;
		}
	}
	void dfs2(int x, int tp) {
		dfn[x] = ++cnt, pre[cnt] = x, top[x] = tp;
		if (son[x]) dfs2(son[x], tp);
		for (int i = head[x]; i; i = edge[i].next) {
			int to = edge[i].to;
			if (to == fath[x] || to == son[x]) continue;
			dfs2(to, to);
		}
	}
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) w[i] = read();
	for (int i = 1, x, y; i < n; i++) {
		x = read(), y = read();
		Cut::add(x, y), Cut::add(y, x);
	}
	Cut::dfs(1, 0), Cut::dfs2(1, 1), Seg::build(1, 1, n);
	for (int i = 1, opt, x, y; i <= m; i++) {
		opt = read();
		if (opt == 1) {
			x = read(), y = read();
			if (dep[x] % 2 == 1) Seg::update(1, y, 1, n, dfn[x], dfn[x] + siz[x] - 1);
			else Seg::update(1, -y, 1, n, dfn[x], dfn[x] + siz[x] - 1);
		}
		if (opt == 2) {
			x = read();
			printf("%d\n", Seg::query(1, 1, n, dfn[x]));
		}
	}
	return 0;
}