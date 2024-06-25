#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, hpa, hpb ,x ,len1 = 0,len2 = 0;
		int cnt1 = 0, cnt2 = 0;
		scanf("%d%d%d", &n, &hpa, &hpb);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			if (x == -1)cnt1++;
			else a[len1++] = x;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			if (x == -1)cnt2++;
			else b[len2++] = x;
		}
		sort(a, a + len1, greater<int>());
		sort(b, b + len2);
		for (int i = 0; i < min(len1, len2) && hpa > 0; i ++)
		{
			hpa -= b[i];
			hpb -= a[i];
			if (hpb <= 0 && hpa > 0) { cout << "yes" << endl; return 0; }
		}
		cout << "no" << endl;
	}

	return 0;
}