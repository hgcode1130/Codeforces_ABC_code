//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#define x first
//#define y second
//using namespace std;
//typedef pair<int, int> PII;
//const int N = 2e5 + 10;
//PII pos[N];
//int n, m, a, b;
//struct Node {
//	int x1, x2, y1, y2;
//}d[N];
//void solve()
//{	
//	cin >> n >> m >> a >> b;
//	memset(d, 0, sizeof d);
//	for (int i = 1; i <= a; i++)
//		cin >> pos[i].x >> pos[i].y;
//	int x1 = 1, x2 = n, y1 = 1, y2 = m;
//	d[0] = { x1 , x2 , y1 , y2 };
//	for (int i = 1; i <= b; i++)
//	{
//		char op;
//		int s;
//		cin >> op >> s;
//		if (op == 'U')
//		{
//			x1 += s;
//		}
//		else if (op == 'D')
//		{
//			x2 -= s;
//		}
//		else if (op == 'L')
//		{
//			y1 += s;
//		}
//		else  y2 -= s;
//		d[i] = { x1 , x2 , y1 , y2 };
//	}
//	int ans1 = 0, ans2 = 0;
//	for (int i = 1; i <= a; i++)
//	{
//		int s = pos[i].x;
//		int q = pos[i].y;
//		int l = -1 , r = b + 1;
//		while (l + 1 != r)
//		{
//			int mid = (l + r) >> 1;
//			if (s <= d[mid].x2 && s >= d[mid].x1 && q <= d[mid].y2 && q >= d[mid].y1) l = mid;
//			else r = mid;
//		}
//		if (r != b + 1)
//		{
//			if (r % 2) ans1++;
//			else ans2++;
//		}
//	}
//	cout << ans1 << " " << ans2 << '\n';
// }
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		solve();
//	}
//	return 0;
//}