//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//const int N = 2e5 + 10;
//vector<int> e[N];
//int dfn[N], low[N], tot;
//int stk[N], instk[N], top;
//int scc[N], siz[N], cnt;
//
//void tarjan(int x)
//{
//	//����
//	dfn[x] = low[x] = ++tot;
//	stk[++top] = x;
//	instk[x] = 1;
//	//��������
//	for (int y : e[x])
//	{
//		if (!dfn[y])
//		{
//			tarjan(y);
//			low[x] = min(low[x], low[y]);
//		}
//		else if (instk[y])
//			low[x] = min(low[x], low[y]);
//	}
//	//���ǿ��ͨ����
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
//
//}