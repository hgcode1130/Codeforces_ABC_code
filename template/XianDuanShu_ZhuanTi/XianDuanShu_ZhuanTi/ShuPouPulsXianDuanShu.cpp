#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 5e5 + 5, MOD = 1e9 + 7;
vector<int> e[N];
int top[N], son[N], si[N], dep[N], father[N], id[N] ,nw[N] , w[N] , cnt;//id为树剖后的新编号，nw为新编号对应的权值
int n, m, s;
struct
{
    int l, r, add, sum;
}tr[N << 2];
void dfs1(int u, int fa)
{
    si[u] = 1, dep[u] = dep[fa] + 1, father[u] = fa;
    for (int v : e[u])
    {
        if (v == fa) continue;
        dfs1(v, u);
        si[u] += si[v];
        if (si[son[u]] < si[v]) son[u] = v;
    }
}

void dfs2(int u, int t)
{
    top[u] = t , id[u] = ++ cnt , nw[cnt] = w[u] ;
    if (!son[u]) return;
    dfs2(son[u], t);
    for (int v : e[u])
    {
        if (v == father[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u)
{
    if (tr[u].add)
    {
        tr[u << 1].add += tr[u].add, tr[u << 1 | 1].add += tr[u].add;
        tr[u << 1].sum += (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].add;
        tr[u << 1 | 1].sum += (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].add;
        tr[u].add = 0;
    }
}

void build(int u, int l, int r)
{
    tr[u].l = l, tr[u].r = r;
    if (l == r)
    {
        tr[u].sum = nw[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l , mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    pushdown(u);
    int ans = 0;
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid) ans += query(u << 1, l, r);
    if (r > mid) ans += query(u << 1 | 1, l, r);
    return ans;
}

int lca(int u, int v)
{
    int ans = 0;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        ans += query(1, id[top[u]], id[u]);
        u = father[top[u]];
    }
    if (dep[u] < dep[v]) swap(u, v);
    ans += query(1, id[v], id[u]);
    return ans;
}

void solve()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs1(s, 0);
    dfs2(s, s);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}