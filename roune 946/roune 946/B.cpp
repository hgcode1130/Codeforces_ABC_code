//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int N = 1e5 + 10;
//typedef long long ll;
//typedef pair<int, int> PII;
//string a;
//int n;
//bool vis[30];
//vector<int> str;
//void solve()
//{
//	cin >> n >> a;
//	memset(vis, 0, sizeof vis);
//	for (int i = 0; i < a.size(); i++)
//	{
//		int j = a[i] - 'a';
//		if (!vis[j])
//		{
//			str.push_back(j);
//			vis[j] = true;
//		}
//	}
//	sort(str.begin(), str.end());
//	int pos[30] = {0};
//	for (int i = 0; i < 28; i++)
//	{
//		for (int j = 0; j < str.size(); j++)
//		{
//			if (i == str[j])
//			{
//				pos[i] = j;
//				break;
//			}
//		}
//	}
//	for (int i = 0; i < a.size(); i++) {
//		int j = a[i] - 'a';
//		a[i] = str[str.size() - pos[j]] + 'a';
//		//cout << a[i] << endl;
//	}
//	cout << a << endl;
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		solve();
//	}
//
//}