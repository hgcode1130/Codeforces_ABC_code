//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//const int N = 5010;
//int n, m;
//int w[N];
//vector<int> edge[N];
//long long ans , s;
//bool vis[N];
//
//void dfs(int now , int u, long long sum)
//{
//	sum += w[u];
//	if (now >= s)
//	{
//		ans = max(ans, sum);
//		return;
//	}
//	vis[u] = true;
//	bool f = true;
//	for (int i = 0; i < edge[u].size(); i++)
//	{
//		if (!vis[edge[u][i]])
//		{
//			f = false;
//			dfs(u + 1, edge[u][i] , sum);
//			vis[edge[u][i]] = false;
//		}
//	}
//	if (f)
//	{
//		ans = max(ans, sum);
//	}
//}
//
//int main()
//{
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
//
//	s = min(5, n);
//	int a, b;
//	for(int i = 1 ; i <= m ; i ++)
//	{
//		scanf("%d%d", &a, &b);
//		if (a != b)
//		{
//			edge[a].push_back(b);
//			edge[b].push_back(a);
//		}
//	}
//	if (n == 1) { cout << w[1] << endl; return 0; }
//	for (int i = 1; i <= n; i++)
//	{
//		dfs(0, i , 0);
//		vis[i] = false;
//	}
//	printf("%lld", ans);
//	return 0;
//}