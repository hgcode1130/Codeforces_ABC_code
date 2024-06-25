//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<set>
//using namespace std;
//const int N = 2e5 + 10;
//int a[N], b[N];
//int p[N];
//void solve()
//{
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < n + m + 1; i++) cin >> a[i];
//	for (int i = 0; i < m + n + 1; i++) cin >> b[i];
//	int sum1 = 0, sum2 = 0;
//	int t1 = m, t2 = n;
//	set<int> ceshi, biancheng;
//	for (int i = 1; i <= m + n; i++)
//	{
//		if (a[i] >= b[i])
//		{
//			if (t1)
//			{
//				t1--;
//				sum1 += a[i];
//				p[i] = 1;
//				biancheng.insert(i);
//			}
//			else {
//				sum2 += b[i];
//				p[i] = 2;
//				t2--;
//				ceshi.insert(i);
//			}
//		}
//		else {
//			if (t2)
//			{
//				t2--;
//				sum2 += b[i];
//				p[i] = 2;
//				ceshi.insert(i);
//			}
//			else {
//				t1--;
//				sum1 += a[i];
//				p[i] = 1;
//				biancheng.insert(i);
//			}
//		}
//	}
//	for (int i = 0; i < m + n; i++)
//	{
//		cout << sum1 + sum2 << endl;
//		if (p[i + 1] == 1)
//		{
//			sum1 -= a[i + 1];
//			biancheng.erase(biancheng.find(i + 1));
//			if (a[i] >= b[i])
//			{			
//				sum1 += a[i];
//				biancheng.insert(i);
//			}
//			else
//			{
//				//现在要做的就是找到从i + 1之后最后第一个加入测试的人并且更新最后一个加入测试的
//				if(ceshi.size () && *ceshi.rbegin() > i + 1)
//				{
//					sum2 -= b[*ceshi.rbegin()];
//					sum2 += b[i];
//					sum1 += a[*ceshi.rbegin()];
//					biancheng.insert(*ceshi.rbegin());
//					ceshi.erase(*ceshi.rbegin());
//					ceshi.insert(i);
//				}
//				else
//				{
//					sum1 += a[i];
//					biancheng.insert(i);
//				}
//			}
//		}
//		else
//		{
//			sum2 -= b[i + 1];
//			ceshi.erase(ceshi.find(i + 1));
//			if (b[i] >= a[i])
//			{
//				sum2 += b[i];
//				ceshi.insert(i);
//			}
//			else
//			{
//				//找到从i + 1之后最后一个加入编程的人
//				if (biancheng.size() && *biancheng.rbegin() > i + 1)
//				{
//					sum1 -= a[*biancheng.rbegin()];
//					sum1 += a[i];
//					sum2 += b[*biancheng.rbegin()];
//					ceshi.insert(*biancheng.rbegin());
//					biancheng.erase(*biancheng.rbegin());
//					biancheng.insert(i);
//				}
//				else
//				{
//					sum2 += b[i];
//					ceshi.insert(i);
//				}
//			}
//		}
//	}
//}
//int main()
//{
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