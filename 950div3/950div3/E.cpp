//#define _CRT_SECURE_NO_WARNINGS 1
//#include<bits/stdc++.h>
//using namespace std;
//
//void solve()
//{
//    int n, m;
//    cin >> n >> m;
//    vector a(n, vector<int>(m)), b(n, vector<int>(m));
//    vector<int>row(n * m), col(n * m);
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//        {
//            cin >> a[i][j];
//            a[i][j]--;
//            row[a[i][j]] = i;
//            col[a[i][j]] = j;
//        }
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//        {
//            cin >> b[i][j];
//            b[i][j]--;
//        }
//    for (int i = 0; i < n; i++)
//    {
//        int j = row[b[i][0]];
//        swap(a[i], a[j]);
//        for (int s = 0; s < m; s++)
//        {
//            row[a[i][s]] = i;
//            row[a[j][s]] = j;
//        }
//    }
//    for (int j = 0; j < m; j++)
//    {
//        int c = col[b[0][j]];
//        for (int i = 0; i < n; i++)
//        {
//            swap(a[i][j], a[i][c]);
//            col[a[i][j]] = j;
//            col[a[i][c]] = c;
//        }
//    }
//    if (a == b) cout << "YES" << "\n";
//    else cout << "NO" << "\n";
//}
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0), cout.tie(0);
//    int t;
//    cin >> t;
//    while (t--)
//    {
//        solve();
//    }
//}