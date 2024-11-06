//////#include<iostream>
//////#include<algorithm>
//////#define int long long
//////using namespace std;
//////int dx[] = { 0 , 1 , -1 , 0 }, dy[] = { 1 , 0 , 0 , -1 };
//////const int MOD = 1e9 + 7 , N = 2e5 + 5;
//////typedef pair<int, int> PII;
//////int ksm(int a, int b)
//////{
//////	int res = 1;
//////	while (b)
//////	{
//////		if (b & 1) res = res * a % MOD;
//////		a = a * a % MOD;
//////		b >>= 1;
//////	}
//////	return res;
//////}
//////
//////struct tree
//////{
//////	int l, r, lazy, sum;
//////}tr[N << 2];
//////
//////void pushup(int u)
//////{
//////
//////}
//////void pushdown(int u)
//////{
//////
//////}
//////void build(int u, int l, int r)
//////{
//////	tr[u].l = l, tr[u].r = r;
//////	if (l == r)
//////	{
//////
//////		return;
//////	}
//////}
//////
//////int a[33];
//////void solve()
//////{
//////	int n = 32, i;
//////	for (i = 1; i <= 32; i++) cin >> a[i];
//////	int cnt = 0;
//////
//////	for (i = 2; i <= 32; i++) if (a[i] > a[1]) cnt++;
//////
//////	if (cnt == 0) cout << 1;
//////	else if (cnt <= 8) cout << 2;
//////	else if (cnt <= 18) cout << 4;
//////	else if (cnt <= 25) cout << 8;
//////	else if (cnt <= 29) cout << 16;
//////	else cout << 32;
//////}
//////
//////int main()
//////{
//////	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//////	int t = 1;
//////	cin >> t;
//////	while (t--) solve();
//////	return 0;
//////}
////#include<iostream>
////#include<cstring>
////using namespace std;
////const int N = 210;
////int n, m, Q;
////int d[N][N];
////int main()
////{
////    cin >> n >> m >> Q;
////    memset(d, 0x3f, sizeof d);
////    while (m--)
////    {
////        int x, y, z;
////        cin >> x >> y >> z;
////        d[x][y] = min(d[x][y], z);
////    }
////    for (int i = 1; i <= n; i++) d[i][i] = 0;
////    for (int k = 1; k <= n; k++)
////        for (int i = 1; i <= n; i++)
////            for (int j = 1; j <= n; j++)
////                if(i != j)
////                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
////
////    while (Q--)
////    {
////        int x, y;
////        cin >> x >> y;
////        if (d[x][y] > 0x3f3f3f3f / 2) cout << "impossible" << endl;
////        else cout << d[x][y] << endl;
////    }
////}
//#include<iostream>
//using namespace std;
//
////顺序表的类模板
//template<typename T>
//class Array
//{
//private:
//	//数据成员
//	T* arr = nullptr;
//	//最大容量
//	int maxSize = 0;
//	//现在的容量
//	int curSize = 0;
//
//public:
//	//构造方法
//	Array(int size)
//	{
//		if (size <= 0)
//		{
//			arr = nullptr;
//			cout << "创建失败" << endl;
//			throw - 1;
//		}
//		else
//		{
//			maxSize = size;
//			curSize = 0;
//			arr = new T[size];
//			cout << "创建成功" << endl;
//		}
//	}
//	//析构方法
//	~Array()
//	{
//		if (arr)
//		{
//			delete[] arr;
//			arr = nullptr;
//		}
//		
//	}
//	//深拷贝
//	Array(Array& cpyArr)
//	{
//		if (cpyArr.Size() == 0)
//		{
//			return;
//		}
//		else
//		{
//			curSize = cpyArr.Size();
//			maxSize = cpyArr.MaxSize();
//			arr = new T[maxSize];
//			for (int i = 0; i < curSize; i++)
//			{
//				arr[i] = cpyArr[i];
//			}
//		}
//	}
//	//增加
//	bool Append(T data)
//	{
//		//已经填满
//		if (curSize == maxSize)
//		{
//			cout << "以达到最大容量，无法写入" << endl;
//			return false;
//		}
//		else
//		{
//			arr[curSize] = data;
//			curSize++;
//		}
//		return true;
//	}
//	//删除
//	bool Delete()
//	{
//		if (curSize == 0)
//		{
//			return false;
//		}
//		else
//		{
//			curSize--;
//			return true;
//		}
//	}
//	//查找
//	bool Find(T pos)
//	{
//		for (int i = 0; i < curSize; i++)
//		{
//			if (arr[i] == pos)
//			{
//				return true;
//			}
//		}
//		return false;
//	}
//	//改数据
//	bool Change(int pos, T data)
//	{
//		if (curSize - 1 < pos)
//		{
//			return false;
//		}
//		else
//		{
//			arr[pos] = data;
//		}
//	}
//	//返回size
//	int Size()
//	{
//		return this->curSize;
//	}
//
//	int MaxSize()
//	{
//		return this->maxSize;
//	}
//
//	//运算符重载 []
//	T& operator[](int pos)
//	{
//		if (curSize >= pos)
//		{
//			cout << "越界" << endl;
//		}
//		else
//		{
//			return arr[pos];
//		}
//	}
//	//打印
//	void Show()
//	{
//		for (int i = 0; i < curSize; i++)
//			cout << arr[i] << "\t";
//		cout << endl;
//	}
//};
//
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
//	//顺序表
//	Array<int> arrList(10);
//	for (int i = 0; i < 11; i++)
//	{
//		arrList.Append(i);
//	}
//	cout << arrList.Size() << endl;
//	cout << arrList.MaxSize() << endl;
//
//	arrList.Show();
//	//0,1,2,3,4,5,6,7,8,9
//	arrList.Delete();
//
//	arrList.Show();
//	//0,1,2,3,4,5,6,7,8
//	if (arrList.Find(3))
//		cout << "找到" << endl;
//	else
//		cout << "未找到" << endl;
//	//找到
//	if (arrList.Find(9))
//		cout << "找到" << endl;
//	else
//		cout << "未找到" << endl;
//	//未找到
//	//改
//	arrList.Change(3, 4);
//	arrList.Show();
//	//0,1,2,4,4,5,6,7,8
//
//	//单链表
//
//	return 0;
//}
//#include<iostream>
//
//using namespace std;
//const int N = 2e5 + 10;
//typedef long long ll;
//typedef pair<int, int> PII;
//typedef unsigned long long ull;
//const int mod = 1e9 + 7;
//int ksm(int a, int b)
//{
//    int res = 1;
//    while (b)
//    {
//        if (b & 1) res = res * a % mod;
//        b >>= 1;
//        a = a * a % mod;
//    }
//    return res;
//}
//void solve()
//{
//    for (int i = 1; i <= 20000; i++) for (int j = 1; j <= i; j++)
//    {
//
//        if (i * ksm(j, mod - 2) % mod == 500000007 % mod)
//        {
//            cout << i << " " << j << "\n";
//            break;
//        }
//    }
//}
//int main()
//{
//    int t = 1;
//    //cin >> t;
//    while (t--)solve();
//}

#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef unsigned long long ull;
const int mod = 1e9 + 7, N = 5e5 + 10;
int ksm(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}
int dx[] = { 1 , 0 , -1 , 0 }, dy[] = { 0 , 1 , 0 , -1 };
const int inf = 0x3f3f3f3f;
vector<int>e[N];
int dist[N];
int jc[N];
void dfs(int u)
{
    for (int v : e[u])
    {
        dist[v] = dist[u] + 1;
        dfs(v);
    }
}
int C(int a, int b)
{
    return jc[a] * ksm(jc[a - b], mod - 2) % mod * ksm(jc[b], mod - 2) % mod;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), w(n + 1), du(n + 1, 0), ans(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i], e[i].clear(), dist[i] = 0;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < a[b[i]]) ans[i] = a[i] + w[i];
        else if (i == b[i]) ans[i] = a[i];
        else if (a[i] >= a[b[i]] + w[b[i]]) ans[i] = a[i];
        else e[b[i]].push_back(i), du[i]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!ans[i] && !du[i]) dfs(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!ans[i]) {
            //int t=n-1-dist[i];
            //ans[i]=jc[t]*C(t+dist[i]+1,dist[i]+1)%mod*ksm(jc[n],mod-2)%mod*w[i]%mod+a[i];
            ans[i] = ksm(jc[dist[i]] + 1, mod - 2) * w[i] + a[i];
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] % mod << " ";
    cout << "\n";
}
signed main()
{
    jc[0] = 1;
    for (int i = 1; i <= N; i++) jc[i] = jc[i - 1] * i % mod;
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)solve();
}