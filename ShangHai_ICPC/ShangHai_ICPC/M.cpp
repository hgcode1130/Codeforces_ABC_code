//#include<iostream>
//#include<vector>
//using namespace std;
//typedef pair<int, int> PII;
//int main()
//{
//	vector<PII> a , b;
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	int n;
//	cin >> n;
//
//		int len = (n + 1) / 2 , cnt = 0;
//		for (int i = 1; i + 1 <= len; i += 2)
//		{
//			cnt++;
//			a.push_back({ i , i + 1 });
//		}
//		for (int i = len + 2; i + 1 <= 2 * len - (n % 2); i += 2)
//		{
//			cnt++;
//			a.push_back({ i , i + 1 });
//		}
//		for (int i = 3; i <= len ; i += 2)
//		{
//			cnt++;
//			a.push_back({ i , i - 2 + len });
//		}
//		cout << cnt << "\n";
//		for (int i = 0; i < a.size(); i++)
//		{
//			cout << a[i].first << " " << a[i].second << "\n";
//		}
//		for (int i = 1; i <= cnt; i++)
//		{
//			cout << i << " " << i + len << " " << "\n";
//		}
//}
