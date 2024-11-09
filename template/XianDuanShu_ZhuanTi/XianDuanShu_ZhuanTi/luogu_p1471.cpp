//#include<iostream>
//
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;
//struct
//{
//	int l, r;
//	double sum1, sum2 , add; //sum1 为西格玛ai ，sum2为西格玛ai的平方
//}tr[N << 2];
//
//int n, m;
//double a[N];
//
//void pushup(int u)
//{
//	tr[u].sum1 = tr[u << 1].sum1 + tr[u << 1 | 1].sum1;
//	tr[u].sum2 = tr[u << 1].sum2 + tr[u << 1 | 1].sum2;
//}
//
//void pushdown(int u)
//{
//	if (tr[u].add)
//	{
//		tr[u << 1].add += tr[u].add, tr[u << 1 | 1].add += tr[u].add;
//		tr[u << 1].sum2 += tr[u << 1].sum1 * 2 * tr[u].add + tr[u].add * tr[u].add * (tr[u << 1].r - tr[u << 1].l + 1);
//		tr[u << 1 | 1].sum2 += tr[u << 1 | 1].sum1 * 2 * tr[u].add + tr[u].add * tr[u].add * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
//		tr[u << 1].sum1 += tr[u].add * (tr[u << 1].r - tr[u << 1].l + 1);
//		tr[u << 1 | 1].sum1 += tr[u].add * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
//		tr[u].add = 0;
//	}
//}
//	
//void build(int u, int l, int r)
//{
//	tr[u].l = l, tr[u].r = r;
//	if (l == r)
//	{
//		tr[u].sum1 = a[l];
//		tr[u].sum2 = a[l] * a[l];
//		return;
//	}
//	int mid = tr[u].l + tr[u].r >> 1;
//	build(u << 1, l, mid);
//	build(u << 1 | 1, mid + 1, r);
//	pushup(u);
//}
//
//void modify(int u, int ql, int qr , double x)
//{
//	if (tr[u].l >= ql && tr[u].r <= qr)
//	{
//		tr[u].add += x;
//		tr[u].sum2 += x * 2 * tr[u].sum1 + x * x * (tr[u].r - tr[u].l + 1);
//		tr[u].sum1 += x * (tr[u].r - tr[u].l + 1);
//		return;
//	}
//	pushdown(u);
//	int mid = tr[u].l + tr[u].r >> 1;
//	if (ql <= mid) modify(u << 1, ql, qr, x);
//	if (qr > mid) modify(u << 1 | 1, ql, qr, x);
//	pushup(u);
//}
//
//double query1(int u, int ql, int qr)
//{
//	if (tr[u].l >= ql && tr[u].r <= qr)
//	{
//		return tr[u].sum1;
//	}
//	pushdown(u);
//	double ans = 0;
//	int mid = tr[u].l + tr[u].r >> 1;
//	if (ql <= mid) ans += query1(u << 1, ql, qr);
//	if (qr > mid) ans += query1(u << 1 | 1, ql, qr);
//	return ans;
//}
//
//double query2(int u, int ql, int qr)
//{
//	if (tr[u].l >= ql && tr[u].r <= qr)
//	{
//		return tr[u].sum2;
//	}
//	pushdown(u);
//	double ans = 0;
//	int mid = tr[u].l + tr[u].r >> 1;
//	if (ql <= mid) ans += query2(u << 1, ql, qr);
//	if (qr > mid) ans += query2(u << 1 | 1, ql, qr);
//	return ans;
//}
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	build(1, 1, n);
//	
//	int op, x, y;
//	double k;
//	double ans;
//	for (int i = 1; i <= m; i++)
//	{
//		cin >> op >> x >> y;
//		if (op == 1) cin >> k, modify(1, x, y, k);
//		else if (op == 2) ans = query1(1, x, y) / (y - x + 1) , printf("%.4lf\n",ans);
//		else ans = query2(1, x, y) / (y - x + 1) - query1(1, x, y) * query1(1 , x , y)/ ((y - x + 1) * (y - x + 1)) , printf("%.4lf\n",ans);
//	}
//	return 0;
//}