//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//
//const int N = 3e4 + 10;
//int h[N], e[N * 2], ne[N * 2], idx, w[N];
//int dfn[N], rnk[N];
//int cnt;
//int n, q;
//char op[10];
//int dep[N], fa[N], si[N] , son[N] , top[N];
//
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//
//void dfs1(int u) {
//	si[u] = 1;
//	son[u] = -1;
//	for (int i = h[u]; i != -1; i = ne[i])
//	{
//		int j = e[i];
//		if (!dep[j])
//		{
//			dep[j] = dep[u] + 1;
//			fa[j] = u;
//			dfs1(j);
//			si[u] += si[j];
//			if (son[u] == -1 || si[son[u]] < si[j]) son[u] = j;
//		}
//	}
//}
//
//void dfs2(int u, int t)
//{
//	top[u] = t;
//	dfn[u] = ++cnt;
//	rnk[cnt] = u;
//	if (son[u] == -1) return;
//	dfs2(son[u], t);
//	for (int i = h[u]; i != -1; i = ne[i])
//	{
//		int j = e[i];
//		if (j != fa[i] && j != son[u]) dfs2(j, j);
//	}
//}
//
//struct SeTree
//{
//	int sum[N << 2], ma[N << 2];
//	void build(int u, int l1, int r1)
//	{
//		if (l1 == r1)
//		{
//			ma[u] = sum[u] = w[rnk[l1]];
//			return;
//		}
//		int mid = (l1 + r1) >> 1;
//		build(u << 1, l1, mid);
//		build(u << 1 | 1, mid + 1, r1);
//		sum[u] = sum[u << 1] + sum[u << 1 | 1];
//		ma[u] = max(ma[u << 1], ma[u << 1 | 1]);
//	}
//	void change(int u, int l , int r , int ql, int qr , int x)
//	{
//		if (ql >= l && qr <= r)
//		{
//			sum[u] = ma[u] = x;
//			return;
//		}
//		int mid = (l + r) >> 1;
//		if (ql <= mid) change(u << 1, l, mid, ql, qr, x);
//		if (qr > mid) change(u << 1 | 1, mid + 1, r, ql, qr, x);
//		sum[u] = sum[u << 1] + sum[u << 1 | 1];
//		ma[u] = max(ma[u << 1], ma[u << 1 | 1]);
//	}
//	int query_max(int u, int l, int r, int ql, int qr)
//	{
//		if (ql >= l && qr <= r)
//		{
//			return ma[u];
//		}
//		int ans = -0x3f3f3f3f;
//		int mid = (l + r) >> 1;
//		if (mid >= ql) ans = max(ans , query_max(u << 1, l, mid, ql, qr));
//		if (qr > mid) ans = max(ans, query_max(u << 1 | 1, mid + 1, r , ql, qr));
//		sum[u] = sum[u << 1] + sum[u << 1 | 1];
//		ma[u] = max(ma[u << 1], ma[u << 1 | 1]);
//		return ans;
//	}
//	int query_sum(int u, int l, int r, int ql, int qr)
//	{
//		if (ql >= l && qr <= r)
//		{
//			return sum[u];
//		}
//		int ans = 0;
//		int mid = (l + r) >> 1;
//		if (mid >= ql) ans += query_sum(u << 1 , l, mid, ql, qr);
//		if (qr > mid) ans += query_sum(u << 1 | 1, mid + 1, r, ql, qr);
//		sum[u] = sum[u << 1] + sum[u << 1 | 1];
//		ma[u] = max(ma[u << 1], ma[u << 1 | 1]);
//		return ans;
//	}
//}se;
//
//void qchange(int u, int x)
//{
//	se.change(1, 1, n, dfn[u], dfn[u], x);
//}
//void qsum(int u, int v)
//{
//	int ans = 0;
//	while (top[u] != top[v])
//	{
//		if (dep[top[u]] < dep[top[v]]) swap(u, v);
//		ans += se.query_sum(1, 1, n, dfn[top[u]], dfn[u]);
//		u = fa[top[u]];
//	}
//	if (dep[u] < dep[v]) swap(u, v);
//	ans += se.query_sum(1, 1, n, dfn[top[u]], dfn[u]);
//	cout << ans << "\n";
//}
//void qmax(int u, int v)
//{
//	int ans = -0x3f3f3f3f;
//	while (top[u] != top[v])
//	{
//		if (dep[top[u]] < dep[top[v]]) swap(u, v);
//		ans = max(ans , se.query_sum(1, 1, n, dfn[top[u]], dfn[u]));
//		u = fa[top[u]];
//	}
//	if (dep[u] < dep[v]) swap(u, v);
//	ans = max(ans, se.query_sum(1, 1, n, dfn[top[u]], dfn[u]));
//	cout << ans << "\n";
//}
//
//int main()
//{
//	int u , v;
//	cin >> n;
//	memset(h, -1, sizeof h);
//	memset(se.ma, -0x3f, sizeof se.ma);
//	for (int i = 1; i <= n - 1; i++)
//	{
//		cin >> u >> v;
//		add(u, v), add(v, u);
//	}
//	for (int i = 1; i <= n; i++) cin >> w[i];
//	dep[1] = 1 , fa[1] = 1;
//	dfs1(1); dfs2(1, 1);
//	se.build(1, 1, n);
//	cin >> q;
//	while (q--)
//	{
//		cin >> op >> u >> v;
//		if (op[0] == 'C')
//		{
//			qchange(u, v);
//		}
//		else if (op[1] == 'M')
//		{
//			qmax(u , v);
//		}
//		else
//		{
//			qsum(u, v);
//		}
//	}
//	return 0;
//}
//#include<algorithm>
//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#define N 100007
//#define INF 10000000
//using namespace std;
//int n, cnt, num, Q;
//int val[N], head[N];
//int f[N], dep[N], si[N], son[N];	//Dfs1处理 父亲，深度，大小，重儿子 
//int top[N], id[N], rk[N];	//Dfs2处理 链顶，Dfs序新编号 ，新编号对应原编号 
//struct Edge {
//	int next, to;
//}edge[N << 1];
//struct Segment_Tree
//{
//	int sum[N << 2], maxv[N << 2];
//	inline int ls(int p) { return p << 1; }
//	inline int rs(int p) { return p << 1 | 1; }
//	void push_up(int p) {
//		sum[p] = sum[ls(p)] + sum[rs(p)];
//		maxv[p] = max(maxv[ls(p)], maxv[rs(p)]);
//	}
//	void build(int p, int l, int r)
//	{
//		if (l == r) { sum[p] = maxv[p] = val[rk[l]]; return; }
//		int mid = (l + r) >> 1;
//		build(ls(p), l, mid);
//		build(rs(p), mid + 1, r);
//		push_up(p);
//	}
//	int Querysum(int ql, int qr, int p, int l, int r)
//	{
//		if (ql <= l && r <= qr) return sum[p];
//		int res = 0, mid = (l + r) >> 1;
//		if (ql <= mid) res += Querysum(ql, qr, ls(p), l, mid);
//		if (qr > mid) res += Querysum(ql, qr, rs(p), mid + 1, r);
//		return res;
//	}
//	int Querymax(int ql, int qr, int p, int l, int r)
//	{
//		if (ql <= l && r <= qr) return maxv[p];
//		int Max = -INF, mid = (l + r) >> 1;
//		if (ql <= mid) Max = max(Max, Querymax(ql, qr, ls(p), l, mid));
//		if (qr > mid) Max = max(Max, Querymax(ql, qr, rs(p), mid + 1, r));
//		return Max;
//	}
//	void update(int p, int l, int r, int q, int v)
//	{
//		int mid = (l + r) >> 1;
//		if (l == r) { sum[p] = maxv[p] = v; return; }
//		if (q <= mid) update(ls(p), l, mid, q, v);
//		else update(rs(p), mid + 1, r, q, v);
//		push_up(p);
//	}
//}tree;
//void add(int u, int v) {
//	edge[++cnt].next = head[u];
//	edge[cnt].to = v;
//	head[u] = cnt;
//}
//void Dfs1(int p, int fa)
//{
//	f[p] = fa, dep[p] = dep[fa] + 1, si[p] = 1;
//	for (int i = head[p], v; i; i = edge[i].next) {
//		if ((v = edge[i].to) != fa) {
//			Dfs1(v, p);
//			si[p] += si[v];
//			if (si[v] > si[son[p]])
//				son[p] = v;
//		}
//	}
//}
//void Dfs2(int p, int t)
//{
//	top[p] = t, id[p] = ++num, rk[num] = p;
//	if (son[p]) Dfs2(son[p], t);
//	for (int i = head[p], v; i; i = edge[i].next) {
//		if ((v = edge[i].to) != f[p] && v != son[p])
//			Dfs2(v, v);
//	}
//}
//int qsum(int x, int y)
//{
//	int res = 0;
//	while (top[x] != top[y]) {
//		if (dep[top[x]] < dep[top[y]]) swap(x, y);
//		res += tree.Querysum(id[top[x]], id[x], 1, 1, n);
//		x = f[top[x]];
//	}
//	if (dep[x] > dep[y]) swap(x, y);
//	return res += tree.Querysum(id[x], id[y], 1, 1, n);
//}
//int qmax(int x, int y)
//{
//	int res = -INF;
//	while (top[x] != top[y]) {
//		if (dep[top[x]] < dep[top[y]]) swap(x, y);
//		res = max(res, tree.Querymax(id[top[x]], id[x], 1, 1, n));
//		x = f[top[x]];
//	}
//	if (dep[x] > dep[y]) swap(x, y);
//	return res = max(res, tree.Querymax(id[x], id[y], 1, 1, n));
//}
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1, u, v; i <= n - 1; ++i) {
//		scanf("%d%d", &u, &v);
//		add(u, v), add(v, u);
//	}
//	for (int i = 1; i <= n; ++i)
//		scanf("%d", &val[i]);
//	Dfs1(1, 0), Dfs2(1, 1), tree.build(1, 1, n);
//	scanf("%d", &Q);
//	while (Q--) {
//		char s[10]; int x, y;
//		cin >> s;
//		scanf("%d%d", &x, &y);
//		if (s[0] == 'C') tree.update(1, 1, n, id[x], y);
//		else if (s[1] == 'M') printf("%d\n", qmax(x, y));
//		else printf("%d\n", qsum(x, y));
//	}
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<cstring>
//#include<cmath>
//#include<map>
//#define ll long long
//using namespace std;
//const int  maxn = 1e5 + 10;
//char a[maxn];
//int dx[] = { 1 , 0 , 0 , -1 }, dy[] = { 0 , -1,  1 , 0 };
//// void read(int &x){
////     x=0;char c=getchar();int flag=1;
////     while(c<'0'||c>'9') flag=(c=='-'?-1:1),c=getchar();
////     while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
////     x=x*flag;
//// }
//// 1 2 3 4 
//// b n x d
//int main() {
//
//    int t;
//    cin >> t;
//    while (t--)
//    {
//        map<pair<int, int>, int>mp;
//        ll n;
//        cin >> n >> a + 1;
//        ll nowx = 0, nowy = 0, face = 1;
//        bool f1 = false, f2 = false;
//        mp[{0, 0}] = face;
//        //a[n + 1] = 'S';
//        for (int i = 1; i <= n; i++)
//        {
//            if (a[i] == 'S') {
//                if (face == 1) nowy++;
//                else if (face == 2) nowy--;
//                else if (face == 3) nowx--;
//                else nowx++;
//            }
//            else if (a[i] == 'R')
//            {
//                if (face == 1) nowy++;
//                else if (face == 2) nowy--;
//                else if (face == 3) nowx--;
//                else nowx++;
//                if (face == 1) face = 4;
//                else if (face == 2) face = 3;
//                else if (face == 3) face = 1;
//                else face = 2;
//            }
//            else
//            {
//                if (face == 1) nowy++;
//                else if (face == 2) nowy--;
//                else if (face == 3) nowx--;
//                else nowx++;
//                if (face == 1) face = 3;
//                else if (face == 2) face = 4;
//                else if (face == 3)face = 2;
//                else face = 1;
//            }
//            if (i != n && mp.count({ nowx , nowy }))
//            {
//                f1 = true;
//                break;
//            }
//            else if (i != n)mp[{nowx, nowy}] = face;
//        }
//        if (f1)
//        {
//            cout << -1 << "\n";
//        }
//        else
//        {
//            if (nowx == 0 && nowy == 0 && mp[{0, 0}] == face) cout << 1 << "\n";
//            else cout << 0 << "\n";
//        }
//    }
//}