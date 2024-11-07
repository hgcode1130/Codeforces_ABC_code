#include<bits/stdc++.h>
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
MinCostMaxFlow<int> g;
map<string,int> mp;
map<int,string>mp2;
bool vis[N];
int pos[N];

void output(int x)
{
	vis[x] = 1;
	cout << mp2[x - n] << "\n";
	for(int i = g.h[x] ; ~i ; i = g.e[i].ne)
		if(g.e[i].v <= n && !g.e[i].f)
		{
			output(g.e[i].v + n);
			break;
		}
}

void output2(int x)
{
	for(int i = g.h[x] ; ~i ; i = g.e[i].ne)
	{
		int to = g.e[i].v;
		if(to <= n && !g.e[i].f && !vis[to + n]) 
			{output2(to + n);}

	}
	cout << mp2[x - n] << "\n";
}

signed main()
{
    cin >> n >> m;
    string u,v;
    s = 2 * n + 1 , t = 2 * n + 2;
    g.init(s , t , t); 
	bool f = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> u;
        mp[u] = i;
		mp2[i] = u;
		if(i != 1 && i != n)g.add(i , i + n , 1 , 1);
		else g.add(i , i + n , 2 , 1);
		pos[i + n] = g.etot - 1;
    }
	g.add(s , 1 , 2 , 0) ;
	g.add(2 * n , t , 2 , 0);
    for(int i = 1 ; i <= m ; i ++)
    {
        cin >> u >> v;
		int x = mp[u] , y = mp[v];
		if(x > y) swap(x , y);
		f |= (x == 1 && y == n);
		g.add(x + n , y , 1 , 0);
		g.add(y + n , x , 1 , 0);
    }
	auto [x , y] = g.solve();
	//cout << x << " " << y << "\n";
	if(x == 2) cout << y - 2 << "\n";
	else if(f)
	{
		cout << 2 << "\n" << mp2[1] << "\n" << mp2[n] << "\n" << mp2[1] << "\n";
		return 0;
	}
	else return cout << "No Solution!\n" , 0;
	for(int i = 1 ; i <= n * 2 + 10; i ++) vis[i] = 0;
	output(1 + n);
	output2(1 + n);
    return 0;
}


