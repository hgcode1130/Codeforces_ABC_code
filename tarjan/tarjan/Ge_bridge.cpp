//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//const int N = 2e5 + 10 , M = 2e4 + 10;
//vector<int> h[N];
//struct edge { int u, v; };
//vector<edge> e;
//int dfn[N], low[N], tot;
//struct bridge { int x, y; }bri[M];
//int cnt;
//void add(int a, int b)
//{
//	e.push_back({a , b});
//	h[a].push_back(e.size() - 1);
//}
//
//void tarjan(int x, int in_edge)
//{
//	dfn[x] = low[x] = tot++;
//	for (int i = 0; i < h[x].size(); i++)
//	{
//		int j = h[x][i];
//		int y = e[j].v;
//		if (!dfn[y])
//		{
//			tarjan(y , j);
//			low[x] = min(low[x], low[y]);
//			if (low[y] > dfn[x])
//			{
//				bri[++cnt] = { x ,y };
//			}
//		}
//		else if (j != in_edge ^ 1)
//		{
//			low[x] = min(low[y], dfn[y]);//可以处理重边
//		}
//	}
//}