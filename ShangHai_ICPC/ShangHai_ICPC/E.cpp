//#include<iostream>
//
//using namespace std;
//const int N = 1e6 + 10;
//string a;
//int n , c[100];
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	cin >> n;
//	//getchar();
//	cin >> a;
//	string b = "shanghai";
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] >= 'A' && a[i] <= 'Z') a[i] = a[i] - 'A';
//		else a[i] = a[i] - 'a';
//		c[a[i]]++;
//	}
//	int cnt = 0x3f3f3f3f;
//	for (int i = 0; i < b.size(); i++)
//	{
//		if (b[i] != 'h' && b[i] != 'a')
//			cnt = min(cnt, c[b[i] - 'a']);
//		else cnt = min(cnt, c[b[i] - 'a'] / 2);
//	}
//	cout << cnt << "\n";
//}