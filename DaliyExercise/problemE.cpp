// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// typedef pair<int,int> PII;
// void solve() {
//     int n, k;
//     cin >> n >> k;
//     vector<int> a(n + 1 , 0), pre(n + 1 , 0), suf(n + 2 , 0);
//     int ans = 0;
 
//     for (int i = 1; i <= n; i ++) cin >> a[i], ans = __gcd(ans, a[i]);
//     for (int i = 1; i <= n; i ++) pre[i] = __gcd(pre[i - 1], a[i]);
//     for (int i = n; i >= 1; i --) suf[i] = __gcd(suf[i + 1], a[i]);
 
//     vector<PII> b;
//     b.emplace_back(0, 0);
//     for (int i = 1; i <= n; i ++) {
//         if (!b.empty() && b.back().first == pre[i]) b.pop_back();
//         b.emplace_back(pre[i], i);
//     }
 
//     for (auto [preg, st] : b) {
//         int g = 0;
//         for (int r = st + 1; r <= n; r ++) {
//             ans = max(ans, __gcd(gcd(preg, g), __gcd(a[r] + k, suf[r + 1])));
//             g = __gcd(g, abs(a[r] - a[r + 1]));
//         }
//     }
 
//     cout << ans << "\n";
// }

// signed main()
// {
//     ios::sync_with_stdio(0);
//     int t = 1;
//     cin >> t;
//     while(t --) solve();
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std; 
#define int long long
const int N=1e6+6;
int mod=1e9+7;
int a[N];
int suf[N];
void solve() {
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int now=0;
	for(int i=n;i>=1;i--){
		now=__gcd(now,a[i]);
		suf[i]=now;
	}
	suf[n+1]=0;
	int ans=suf[1];
	int pre=a[0];
	for(int i=0;i<=n;i++){
		if(__gcd(pre,a[i])==pre&&i!=n){
			continue;
		}
		int gd1=0;
		int pre1=a[i];
		for(int j=i;j<=n;j++){
			gd1=__gcd(gd1,abs(a[j]-pre1));
			int sum1=__gcd(pre,gd1);
			int sum2=__gcd(a[i]+k,suf[j+1]);
			ans=max(ans,__gcd(sum1,sum2));
			pre1=a[j];
		}
		pre=__gcd(pre,a[i]);
	}
	cout<<ans<<'\n';
}
signed main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}