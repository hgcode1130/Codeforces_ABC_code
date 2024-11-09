//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 1e5 + 10;
//struct node
//{
//	int l, r, sum, lazy;
//}tr[N << 2];
//int n, m;
//
//void pushup(int u)
//{
//	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
//}
//
//void pushdown(int u)
//{
//	if (tr[u].lazy)
//	{
//		tr[u << 1].sum = (tr[u << 1].r - tr[u << 1].l + 1) - tr[u << 1].sum;
//		tr[u << 1 | 1].sum = (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) - tr[u << 1 | 1].sum;
//		tr[u << 1].lazy ^= 1;
//		tr[u << 1 | 1].lazy ^= 1;
//		tr[u].lazy = 0;
//	}
//}
//
//void build(int u, int l, int r)
//{
//	tr[u].l = l ,  tr[u].r = r;
//	if (l == r) {		
//		tr[u].sum = 0;
//		tr[u].lazy = 0;
//		return;
//	}
//	int mid = l + r >> 1;
//	build(u << 1, l, mid);
//	build(u << 1 | 1, mid + 1, r);
//	pushup(u);
//}
//
//void modify(int u, int ql, int qr)
//{
//	
//	if (tr[u].l >= ql && tr[u].r <= qr)
//	{
//		tr[u].sum = (tr[u].r - tr[u].r + 1) - tr[u].sum;
//		tr[u].lazy ^= 1;
//		return;
//	}
//	pushdown(u);
//	int mid = tr[u].l + tr[u].r >> 1;
//	if (ql <= mid) modify(u << 1, ql, qr);
//	if (qr > mid) modify(u << 1 | 1, ql, qr);
//	pushup(u);
//}
//
//int query(int u, int ql, int qr)
//{
//	if (tr[u].l >= ql && tr[u].r <= qr)
//	{
//		return tr[u].sum;
//	}
//	int ans = 0;
//	pushdown(u);
//	int mid = (tr[u].l + tr[u].r) >> 1;
//	if (ql <= mid) ans += query (u << 1, ql, qr);
//	if (qr > mid) ans += query (u << 1 | 1, ql, qr);
//	return ans;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	cin >> n >> m;
//	int op, l, r;
//	build(1 , 1, n);
//	for (int i = 1; i <= m; i++)
//	{
//		cin >> op >> l >> r;
//		if (op == 0)
//		{
//			modify(1, l, r);
//		}
//		else cout << query(1, l, r) << "\n";
//	}
//
//}