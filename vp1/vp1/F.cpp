#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
#include<windows.h>
using namespace std;
const int MOD = 1e9 + 7, N = 1e6 + 10;
typedef long long ll;
int n, m, A, p, q;
int  a[100000] , level[N] ;
vector<int> state[10000];
ll ksm(ll a, ll b)
{
	int t = 1;
	while (b)
	{
		if (b & 1) t = t * a % MOD;
		a = a * a % MOD;
		b /= 2;
	}
	return t;
}
int ran()
{
	return A = (7 * A + 13) % 19260817;
}
void op1()
{
	ll book[35] = { 0 };
	int L = ran() % n + 1, R = ran() % n + 1;
	int l = min(L, R), r = max(L, R);
	for (int i = l; i <= r; i++)
		book[level[i]]++;
	for (int i = 1; i <= 30; i++)
		book[i + 1] += book[i] / 2;
	int ans = 31;
	for(int i = 30 ; i > 0 ;i--)
		if (book[i])
		{
			ans = i;
			break;
		}
	cout << ans % MOD<< endl;
}

void op3()
{
	int pos = ran() % n + 1, k = ran() % q + 1;
	level[pos] = k;
}
void baocun(int x)
{
	for (int i = 1; i <= n; i++)
		state[x].push_back(level[i]);
}
void op4(int x)
{
	int t = ran() % x + 1;
	for (int i = 1; i <= n; i++)
	{
		level[i] = state[t][i - 1];
	}
}

void op2()
{
	int book[50] = { 0 };
	int L = ran() % n + 1, R = ran() % n + 1;
	int l = min(L, R), r = max(L, R);
	for (int i = l; i <= r; i++)
		book[level[i]]++;
	int sum = 0;

	for (int i = 1; i <= 30; i++)
	{
		book[i + 1] += book[i] / 2;
		book[i] = book[i] % 2;
	}
	int k = ran() % q + 1;
	book[k]++;
	for (int i = 1; i < 30; i++)
	{
		cout << i << endl;
		if (book[i] >= 2)
		{
			sum = (sum + ksm(2, i + 1)) % MOD;
			book[i + 1]++;
		}
	}
	cout << sum << endl;
}


int main()
{
	cin >> n >> m >> A >> p >> q;
	for (size_t i = 1; i <= n; i++)
	{
		level[i] = ran() % q + 1;
		state[0].push_back(level[i]);
	}
	for (int i = 0; i < q; i++)
	{
		int opt = ran() % p + 1;
		switch (opt)
		{
		case 1:
			op1();
			baocun(i + 1);
			break;
		case 2:
			op1();
			baocun(i + 1);
			break;
		case 3:
			op3();
			baocun(i + 1);
			break;
		case 4 :
			op4(i + 1);
			baocun(i + 1);
			break;
		}
	}
	return 0;
}