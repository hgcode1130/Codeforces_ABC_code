#include<bits/stdc++.h>
#define int long long
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
int n , m;
GraphFlow<int> g;
bool vis[N];
int pos[N];
void output(int u)
{
    cout << u << " ";
    vis[u] = true;
    for(int i = g.h[u] ; ~i ; i = g.e[i].ne)
    {
        int v = g.e[i].v;
        if(v > n && v <= 2 * n && !vis[v - n] && !g.e[i].f) output(v - n);
    }
}

signed main()
{
    cin >> n >> m;
    int s = 2 * n + 1 , t = 2 * n + 2;
    g.init(s , t , t);
    for(int i = 1 ; i <= n ; i++) g.add(s , i , 1) , g.add(i + n , t , 1) , pos[i + n] = g.etot - 1;;
    for(int i = 1 ; i <= m ; i ++)
    {
        int u , v;
        cin >> u >> v;
        g.add(u , v + n , 1);
    }
    vector<int> v;
    int ans = g.dinic();
    for(int i = 1 + n ; i <= n * 2 ; i ++) if(!g.e[pos[i]].f) output(i - n) , puts("");
    cout << n - ans<< "\n";
}