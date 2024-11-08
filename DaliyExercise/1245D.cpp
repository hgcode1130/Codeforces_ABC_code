// 注意到这个图上既有点权又有边权，有个很典的思路就是树上的时候可以把点权合并到边权上，如果是图上的时候就是建立一个虚点，让点和虚点连边，边权就是点权，核心思路都是把问题简单化——变成只有边权的问题本题也是一样，我们建立一个超级源点作为电力源让这个点和所有城市连一条边
//典典典~~~
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef pair<int, int> PII;
struct DSU {
    int n;
    vector<int> fa, sz;
    vector<i64> val;

    explicit DSU(int n): n(n) {
        fa.assign(n + 1, 0);
        sz.assign(n + 1, 1);
        val.assign(n + 1, 0);
        for (int i = 1; i <= n; i ++) fa[i] = i;
    }

    int find(int x) {
        if (x == fa[x]) return fa[x];

        int f = fa[x];
        fa[x] = find(fa[x]);
        val[x] += val[f];
        return fa[x];
    }

    bool judge(int x, int y) {
        int dx = find(x), dy = find(y);
        if (dx == dy) return true;
        else return false;
    }

    void merge(int x, int y, i64 w = 0) {
        int dx = find(x), dy = find(y);
        if (dx != dy) {
            fa[dx] = dy;
            sz[dy] += sz[dx];
            val[dx] = -val[x] + val[y] + w;
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<PII> a(n + 1);
    vector<i64> c(n + 1), k(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= n; i ++) cin >> c[i];
    for (int i = 1; i <= n; i ++) cin >> k[i];
    vector<array<i64, 3>> edge;
    for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++) {
            i64 w = (k[i] + k[j]) * (abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second));
            edge.push_back({w, i, j});
        }
    for (int i = 1; i <= n; i ++) {
        edge.push_back({c[i], i, n + 1});
    }

    DSU dsu(n + 1);

    sort(edge.begin(), edge.end());
    i64 ans = 0;
    vector<int> ver;
    vector<PII> e;
    for (auto [w, u, v] : edge) {
        if (!dsu.judge(u, v)) {
            ans += w;
            dsu.merge(u, v);
            if (u == n + 1 || v == n + 1)
                ver.emplace_back(min(u, v));
            else
                e.emplace_back(u, v);
        }
    }

    cout << ans << "\n";
    cout << ver.size() << "\n";
    for (auto i : ver) cout << i << " ";
    cout << "\n";
    cout << e.size() << "\n";
    for (auto [u, v] : e) cout << u << " " << v << "\n";
}

int main() {
    int t = 1;
    //cin >> t;
    while (t --) solve();
    return 0;
}