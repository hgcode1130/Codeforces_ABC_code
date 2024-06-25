//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//#define x first
//#define y second
//using namespace std;
//const int N = 110;
//typedef pair<int, int> PII;
//
//int n;
//PII q[N], temp[4];
//bool st[N];
//int ans = 0x3f3f3f3f;
//
//void dfs(int u, int start)
//{
//	if (u >= 3)
//	{
//		PII c, d, e;
//		c = temp[0], d = temp[1], e = temp[2];
//		d.x -= c.x;
//		e.x -= c.x;
//		d.y -= c.y;
//		e.y -= e.y;
//		int s = (int)fabs(d.x * e.y + d.y * e.x);
//		if (s)
//			ans = min(ans, s);
//		return;
//	}
//	for (int i = start; i <= n; i++)
//	{
//		temp[u] = q[i];
//		st[i] = true;
//		dfs(u + 1 , i + 1);
//		st[i] = false;
//		temp[u] = { 0 , 0 };
//	}
//}
//void solve()
//{
//	ans = 0x3f3f3f3f;
//	memset(st, 0, sizeof st);
//	cin >> n;
//	int a, b;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a >> b;
//		q[i].x = a;
//		q[i].y = b;
//	}
//	dfs(0 , 1);
//	if (ans == 0x3f3f3f3f)cout << -1 << endl;
//	else
//		cout << ans << endl;
//}
//
//int main()
//{
//	int T;
//	cin >> T;
//	while (T--)
//	{
//		solve();
//	}
//
//	return 0;
//}