//#include<iostream>
//#include<map>
//#include<algorithm>
//using namespace std;
//const int N = 1e6 + 10;
//typedef long long ll;
//int a[N], n;
//
//char s[N];
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
//	{
//		map<pair<int, int>, int>mp;
//		cin >> n;
//		cin >> s + 1;
//		mp[{0, 0}] = 0;
//		int x = 0, y = 0;
//		int l = 0, r = 0;
//		int minn = 0x3f3f3f3f;
//		for (int i = 1; i <= n; i++)
//		{
//			if (s[i] == 'L')x--;
//			if (s[i] == 'R')x++;
//			if (s[i] == 'U')y++;
//			if (s[i] == 'D')y--;
//			//mp.count({ x, y });±»·ÃÎÊ¹ý
//			if (mp.count({ x, y }))
//			{
//				int dis = i - mp[{x, y}];
//				if (minn > dis)
//				{
//					minn = dis;
//					l = mp[{x, y}] + 1;
//					r = i;
//				}
//			}
//			mp[{x, y}] = i;
//		}
//		if (minn == 0x3f3f3f3f)cout << -1 << endl;
//		else cout << l << " " << r << endl;
//	}
//	return 0;
//}