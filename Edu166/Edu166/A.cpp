//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//
//using namespace std;
//void solve()
//{
//	string a;
//	int n;
//	cin >> n >> a;
//	bool f = false;//代表已经有字母了
//	int pre = -1 , pre2 = -1;
//	for (int i = 0; i < a.size(); i++)
//	{
//		if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= '0' && a[i] <= '9'))
//		{
//			if (a[i] >= 'a' && a[i] <= 'z')
//			{
//				f = true;
//				if (pre2 == -1) { pre2 = a[i] - 'a'; }
//				else
//				{
//					if (a[i] - 'a' < pre2) { cout << "NO" << endl; return; }
//					else { pre2 = a[i] - 'a'; }
//				}
//			}
//			else
//			{
//				if (f) { cout << "NO" << endl; return; }
//				else {
//					if (pre == -1)
//					{
//						pre = a[i] - '0';
//					}
//					else
//					{
//						if (a[i] - '0' < pre) { cout << "NO" << endl; return; }
//						else { pre = a[i] - '0'; }
//					}
//				}
//			}
//		}
//		else { cout << "NO" << endl; return; }
//	}
//	cout << "YES" << endl;
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		solve();
//	}
//	return 0;
//}