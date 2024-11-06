//#include <iostream>
//#include<cstring>
//#include<vector>
//#include<stack>
//using namespace std;
//#define MAXN 500001
//
//int n, m, u, v, cnt;
//int dfn[MAXN], low[MAXN];
//vector<pair<int, int>> e[MAXN];
//vector<vector<int>> ans;
//stack<int> st;
//
//void tarjan(int x, int las) {
//	low[x] = dfn[x] = ++cnt;
//	st.push(x);
//	for (auto i : e[x]) {
//		if (i.second == (las ^ 1)) continue;
//		if (!dfn[i.first]) {
//			tarjan(i.first, i.second);
//			low[x] = min(low[x], low[i.first]);
//		}
//		else low[x] = min(low[x], dfn[i.first]);
//	}
//	if (dfn[x] == low[x]) {
//		vector<int> vec;
//		vec.push_back(x);
//		while (st.top() != x) {
//			vec.push_back(st.top());
//			st.pop();
//		}
//		st.pop();
//		ans.push_back(vec);
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> n >> m;
//	for (int i(1); i <= m; ++i) {
//		cin >> u >> v;
//		e[u].push_back(make_pair(v, i << 1));
//		e[v].push_back(make_pair(u, i << 1 | 1));
//	}
//	for (int i(1); i <= n; ++i) {
//		if (!dfn[i]) tarjan(i, 0);
//	}
//
//	cout << ans.size() << '\n';
//	for (auto i : ans) {
//		cout << i.size() << ' ';
//		for (auto j : i) cout << j << ' ';
//		cout << '\n';
//	}
//
//	return 0;
//}