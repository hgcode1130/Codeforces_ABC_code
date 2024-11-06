#include<bit/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 10, V = 3e6 + 10, inf = 1ll << 60;
template<typename T>
struct MinCostMaxFlow
{
	int flow, cost;
	int s, t, vtot;
	int h[V], etot;
	int dis[V], pre[V];
	bool vis[V];
	struct edge
	{
		int v, ne;
		T f, t;
	}e[N * 2];
	void add(int a, int b, int c, int t)
	{
		e[etot] = { b , h[a] , c ,t }; h[a] = etot++;
		e[etot] = { a , h[b] , 0 , -t }; h[b] = etot++;
	}
	bool spfa()
	{
		for (int i = 1; i <= vtot; i++) dis[i] = inf, vis[i] = false, pre[i] = -1;
		queue<int> q;
		q.push(s), dis[s] = 0, vis[s] = true;
		while (!q.empty())
		{
			int u = q.front();
			for (int i = h[u]; ~i; i = e[i].ne)
			{
				if (e[i].f && dis[e[i].v] > dis[u] + e[i].t)
				{
					int v = e[i].v;
					dis[v] = dis[u] + e[i].t;
					pre[v] = i;
					if (!vis[v])
					{
						vis[v] = true;
						q.push(v);
					}
				}
			}
			q.pop();
			vis[u] = false;
		}
		return dis[t] < inf / 2;
	}

	void augment()
	{
		int u;
		T f = numeric_limits<T>::max();
		u = t;
		while (~pre[u])
		{
			f = min(f, e[pre[u]].f);
			u = e[pre[u] ^ 1].v;
		}
		flow += f;
		cost += f * dis[t];
		u = t;
		while (~pre[u])
		{
			e[pre[u]].f -= f;
			e[pre[u] ^ 1].f += f;
			u = e[pre[u] ^ 1].v;
		}
	}

	pair<T, T> solve() {
		flow = 0;
		cost = 0;
		while (spfa()) augment();
		return { flow , cost };
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
int n, m, s, t;
MinCostMaxFlow<long long> g;
signed main()
{
	cin >> n >> m >> s >> t;
	g.init(s, t, n);
	for (int i = 1; i <= m; i++)
	{
		int u, v, w, c;
		cin >> u >> v >> w >> c;
		g.add(u, v, w, c);
	}
	pair<int,int> a = g.solve();
	cout << a.first << " " << a.second << "\n";
}