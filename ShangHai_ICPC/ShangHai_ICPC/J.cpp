//#include<iostream>
//using namespace std;
//const int N = 1010;
//int primes[1010], cnt;
//bool st[1010];
//
//void get_primes()
//{
//    for (int i = 2; i <= 1010; i++)
//    {
//        if (!st[i])//那么i是素数
//            primes[cnt++] = i;
//        for (int j = 0; primes[j] <= 1010 / i; j++)
//        {
//            st[i * primes[j]] = true;
//            if (i % primes[j] == 0) break;
//        }
//    }
//}
//int sum[N] , a[N];
//bool find(int n)
//{
//    if (n <= 2)
//    {
//        return false;
//    }
//    int flag = 0;
//    for (int i = 2; i <= n / i; i++)
//        if (n % i == 0)
//        {
//            flag = 1;
//            break;
//        }
//    return flag;
//}
//void solve()
//{
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> a[i] , sum[i] = sum[i - 1] + a[i];
//    int ans = 0x3f3f3f3f;
//    for(int i = 1 ; i <= n ; i++)
//        for (int j = i; j <= n; j++)
//        {
//            if (find(sum[j] - sum[i - 1]))
//            {
//                ans = min(ans, j - i);
//            }
//        }
//    if (ans != 0x3f3f3f3f)
//        cout << ans << "\n";
//    else cout << -1 << "\n";
//}
//int main()
//{
//	//找质数
//    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    get_primes();
//    int t;
//    cin >> t;
//    while (t--)
//    {
//        solve();
//    }
//	return 0;
//}