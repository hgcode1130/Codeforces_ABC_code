#include <iostream>
#include<algorithm>
#define ll long long
using namespace std;
int cou[1000000]; //记录打死这个怪需要开挂的次数.
int main(void)
{
	int n, a, b, k, h; int res = 0; //初始得分0
	cin >> n >> a >> b >> k;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h); //得到当前怪物血量
		if (h % (a + b) <= a && h % (a + b) > 0) res++; //属于白给类型, 注意判断>0的部分, 如果=0说明刚好被B打死, 得开挂
		else {
			h = h % (a + b); //打完了整数轮后怪物剩的血量, 应该是>a的
			if (h == 0)  h = a + b; //特殊情况, 如果B刚好打死怪物, 我们滚回一轮, 假设这轮没打
			cou[i] = h % a ? h / a + 1 : h / a; cou[i]--; //看看A需要打多少次打死这个怪物, 需要开挂的次数要-1,
			//因为最后一次A直接把怪物打死 不用开挂
		}
	}
	sort(cou + 1, cou + 1 + n); //排序
	for (int i = 1; i <= n; i++) 
	{
		if (cou[i] && k - cou[i] >= 0) k -= cou[i], res++;
	}
	cout << res << endl;
	return 0;
}
