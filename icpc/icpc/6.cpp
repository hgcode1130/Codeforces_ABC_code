//#include<iostream>
//#include<map>
//#include<vector>
//#include<set>
//#define int long long
//using namespace std;
//int dx[] = { 0 , 1 , -1 , 0 }, dy[] = { 1 , 0 , 0 , -1 };
//const int MOD = 1e9 + 7, N = 2e5 + 5;
//typedef pair<int, int> PII;
//int ksm(int a, int b)
//{
//    int res = 1;
//    while (b)
//    {
//        if (b & 1) res = res * a % MOD;
//        a = a * a % MOD;
//        b >>= 1;
//    }
//    return res;
//}
//int a[N], tt, b[N], v[N], val[N], l[N], r[N];
//void solve()
//{
//    tt = 0;
//    int tot = 0;
//    int n;
//    cin >> n;
//    vector<int> stk(n + 1);
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> a[i];
//    }
//    int x = 1, cnt = 1;
//    for (int i = 2; i <= n; i++)
//    {
//        if (a[i] == a[x]) cnt++;
//        else
//        {
//            b[++tot] = a[x];
//            v[tot] = cnt;
//            x = i;
//            cnt = 1;
//        }
//    }
//    b[++tot] = a[x];
//    v[tot] = cnt;
//    for (int i = 1; i <= tot; i++) val[i] = 0;
//    for (int i = 1; i <= tot; i++) v[i] += v[i - 1];
//    //for(int i = 1 ; i <= tot ; i ++) cout << b[i] << " " << v[i] << "\n";
//    for (int i = 1; i <= tot; i++) {
//
//    }
//    int ans = 0;
//    for (int i = 1; i <= tot; i++) ans += val[i];
//    cout << ans;
//}
//
//signed main()
//{
//    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    int t = 1;
//    cin >> t;
//    while (t--)
//    {
//        solve();
//        if (t) cout << "\n";
//    }
//    return 0;
//}