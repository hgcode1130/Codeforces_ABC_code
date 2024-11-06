//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//const int N = 2e5 + 10;
//vector<int> e[N];
//int dfn[N], low[N], tot;
//int stk[N], instk[N], top;
//int scc[N], siz[N], cnt;
//int din[N], dout[N];//SCC的入度和出度
//void tarjan(int x)
//{
//	//打标记
//	dfn[x] = low[x] = ++tot;
//	stk[++top] = x;
//	instk[x] = 1;
//	//遍历更新
//	for (int y : e[x])
//	{
//		if (!dfn[y])
//		{
//			tarjan(y);
//			low[x] = min(low[x], low[y]);
//		}
//		else if (instk[y])
//			low[x] = min(low[x], dfn[y]); // 缩点的tarjan要注意的地方，要用dfn来更新
//	}
//	//检查强连通分量
//	if (dfn[x] == low[x])
//	{
//		int y; ++cnt;
//		do
//		{
//			y = stk[top--];
//			instk[y] = 0;
//			scc[y] = cnt;
//			++siz[cnt];
//		} while (y != x);
//	}
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1, a; i <= n; i++)
//		while (cin >> a, a)
//			e[i].push_back(a);
//	for (int i = 1; i <= n; i++)
//		if (!dfn[i]) tarjan(i);
//	for (int i = 1; i <= n; i++)
//		for (int j : e[i])
//		{
//			if (scc[i] != scc[j])
//			{
//				din[scc[j]]++;
//				dout[scc[i]]++;
//			}
//		}
//	int a = 0, b = 0;
//	for (int i = 1; i <= cnt; i++)
//	{
//		if (!din[i]) a++;
//		if (!dout[i]) b++;
//	}
//	cout << a << "\n";
//	if (cnt == 1) cout << 0;
//	else cout << max(a, b) << "\n";
//	return 0;
//}