// 我们选择选枚举朋友 A 的最大价值，即把 ai和bi按照 ai从小到大排序。
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

typedef long long i64;
typedef pair<int, int> PII;
const int N=5e5+5;
int n;
struct node
{
	int id,a,b;
}s[N];

inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
inline void write(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x>9)
	{
		write(x/10);
	}
	putchar((x%10)^48);
	return;
}
inline bool cmp(node a,node b)
{
	return a.a<b.a;
}

void solve() {
		multiset <int> pre,nxt; 
        int ans=0x3fffffff;
		n=read();
		for (int i=1;i<=n;i++)
		{
			s[i].id=i;
			s[i].a=read();
			s[i].b=read();
			nxt.insert(s[i].b);
		}
		sort(s+1,s+n+1,cmp);        
		for (int i=1;i<=n;i++)
		{
			nxt.erase(nxt.find(s[i].b));
			auto w = nxt.end();
			int maxn = -0x3fffffff;
			if (!nxt.empty())          //找出后面最大的值
			{
				w--;
				maxn = *w;
			}
			if (maxn > s[i].a)
			{
				if (ans>maxn-s[i].a)
				{
					ans=maxn-s[i].a;
				}
			}
			else
			{
				if (ans>s[i].a-maxn)
				{
					ans=s[i].a-maxn;
				}
				auto it=pre.insert(s[i].a),ed=pre.end();
				ed--;
				if (it!=pre.begin())       //查前驱和后继
				{
					it--;
					if (ans>s[i].a-(*it))
					{
						ans=s[i].a-(*it);
					}
					it++;
				}
				if (it!=ed)
				{
					it++;
					if (ans>(*it)-s[i].a)
					{
						ans=(*it)-s[i].a;
					}
					it--;
				}
				pre.erase(it);
				
			}
			pre.insert(s[i].b);
		}
		cout << ans << endl;
}

signed main() {
    int t = 1;
    cin >> t;
    while (t --) solve();
    return 0;
}