#include <iostream>
#include<algorithm>
#define ll long long
using namespace std;
int cou[1000000]; //��¼�����������Ҫ���ҵĴ���.
int main(void)
{
	int n, a, b, k, h; int res = 0; //��ʼ�÷�0
	cin >> n >> a >> b >> k;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h); //�õ���ǰ����Ѫ��
		if (h % (a + b) <= a && h % (a + b) > 0) res++; //���ڰ׸�����, ע���ж�>0�Ĳ���, ���=0˵���պñ�B����, �ÿ���
		else {
			h = h % (a + b); //�����������ֺ����ʣ��Ѫ��, Ӧ����>a��
			if (h == 0)  h = a + b; //�������, ���B�պô�������, ���ǹ���һ��, ��������û��
			cou[i] = h % a ? h / a + 1 : h / a; cou[i]--; //����A��Ҫ����ٴδ����������, ��Ҫ���ҵĴ���Ҫ-1,
			//��Ϊ���һ��Aֱ�Ӱѹ������ ���ÿ���
		}
	}
	sort(cou + 1, cou + 1 + n); //����
	for (int i = 1; i <= n; i++) 
	{
		if (cou[i] && k - cou[i] >= 0) k -= cou[i], res++;
	}
	cout << res << endl;
	return 0;
}
