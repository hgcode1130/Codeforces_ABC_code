#include<bit/stdc++.h>
using namespace  std;
const int N = 1e4 + 10, V = 3e6 + 10;
template<typename T>
struct GraphFlow
{
	int s, t, vtot;
	int h[V], etot;
	int dis[V], cur[V];
	struct edge
	{
		int v, ne;
		T f;
	}e[N * 2];
	void add(int a, int b, int c)
	{
		e[etot] = { b , h[a] , c }; h[a] = etot++;
		e[etot] = { a , h[b] , 0 }; h[b] = etot++;
	}
	bool bfs()
	{
		for (int i = 1; i <= vtot; i++)dis[i] = 0, cur[i] = h[i];
		queue<int> q;
		q.push(s), dis[s] = 1;
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (int i = h[u]; ~i; i = e[i].ne)
			{
				if (e[i].f && !dis[e[i].v])
				{
					int v = e[i].v;
					dis[v] = dis[u] + 1;
					if (v == t)return true;
					q.push(v);
				}
			}
		}
		return false;
	}
	T dfs(int u, T m)
	{
		if (u == t) return m;
		T flow = 0;
		for (int i = cur[u]; i != -1; cur[u] = i = e[i].ne)
		{
			if (e[i].f && dis[e[i].v] == dis[u] + 1)
			{
				T f = dfs(e[i].v, min(m, e[i].f));
				e[i].f -= f;
				e[i ^ 1].f += f;
				flow += f;
				m -= f;
				if (!m) break;
			}
		}
		if (!flow) dis[u] = -1;
		return flow;
	}


	T dinic() {
		T flow = 0;
		while (bfs()) flow += dfs(s, 1e18);
		return flow;
	}

	void init(int s_, int t_, int vtot_)
	{
		s = s_;
		t = t_;
		vtot = vtot_;
		etot = 0;
		for (int i = 1; i <= vtot; i++) h[i] = -1;
	}
};
