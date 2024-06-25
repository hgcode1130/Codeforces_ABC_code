//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<unordered_map>
//using namespace std;
//const int N = 10;
//int stack1[N], stack2[N];
//char op[4] = { '+' , '-' , '*' };
//int num[4] , ans;
//bool vis[4];
//unordered_map<int, int> mp;
//
//int op1()
//{
//	int cnt = 0;
//	if (mp.find(stack1[0] + stack1[1] + stack1[2] + stack1[3]) == mp.end())
//	{
//		cnt++;
//		mp[stack1[0] + stack1[1] + stack1[2] + stack1[3]] = 0;
//	}
//	if (mp.find(stack1[0] + stack1[1] + stack1[2] - stack1[3]) == mp.end())
//	{
//		cnt++;
//		mp[stack1[0] + stack1[1] + stack1[2] - stack1[3]] = 0;
//	}
//	if (mp.find(stack1[0] + stack1[1] + stack1[2] * stack1[3]) == mp.end())
//	{
//		cnt++;
//		mp[stack1[0] + stack1[1] + stack1[2] * stack1[3]] = 0;
//	}
//	if (mp.find(stack1[0] + stack1[1] - stack1[2] + stack1[3]) == mp.end())
//	{
//		cnt++;
//		mp[stack1[0] + stack1[1] - stack1[2] + stack1[3]] = 0;
//	}
//	if (mp.find(stack1[0] + stack1[1] - stack1[2] - stack1[3]) == mp.end())
//	{
//		mp[stack1[0] + stack1[1] - stack1[2] - stack1[3]] = 0;
//		cnt++;
//	}
//	if (mp.find(stack1[0] + stack1[1] - stack1[2] * stack1[3]) == mp.end())
//	{
//		mp[stack1[0] + stack1[1] - stack1[2] * stack1[3]] = 0;
//		cnt++;
//	}
//	if (mp.find(stack1[0] + stack1[1] * stack1[2] + stack1[3]) == mp.end())
//	{
//		mp[stack1[0] + stack1[1] * stack1[2] + stack1[3]] = 0;
//		cnt++;
//	}
//	if (mp.find(stack1[0] + stack1[1] * stack1[2] - stack1[3]) == mp.end())
//	{
//		cnt++;
//		mp[stack1[0] + stack1[1] * stack1[2] - stack1[3]] = 0;
//	}
//	if (mp.find(stack1[0] + stack1[1] * stack1[2] * stack1[3]) == mp.end())
//	{
//		cnt++;
//		mp[stack1[0] + stack1[1] * stack1[2] * stack1[3]] = 0;
//	}
//	if (mp.find(stack1[0] - stack1[1] + stack1[2] + stack1[3]) == mp.end())
//	{
//		mp[stack1[0] - stack1[1] + stack1[2] + stack1[3]] = 0;
//		cnt++;
//	}
//	if (mp.find(stack1[0] - stack1[1] + stack1[2] - stack1[3]) == mp.end())
//	{
//		mp[stack1[0] - stack1[1] + stack1[2] - stack1[3]] = 0;
//		cnt++;
//	}
//	if (mp.find(stack1[0] - stack1[1] + stack1[2] * stack1[3]) == mp.end())
//	{
//		mp[stack1[0] - stack1[1] + stack1[2] * stack1[3]] = 0;
//		cnt++;
//	}
//	if (mp.find(stack1[0] - stack1[1] - stack1[2] + stack1[3]) == mp.end())
//	{
//		mp[stack1[0] - stack1[1] - stack1[2] + stack1[3]] = 0;
//		cnt++;
//	}
//	if (mp.find(stack1[0] - stack1[1] - stack1[2] - stack1[3]) == mp.end())
//	{
//		mp[stack1[0] - stack1[1] - stack1[2] - stack1[3]] = 0;
//		cnt++;
//	}
//	if (mp.find(stack1[0] - stack1[1] - stack1[2] * stack1[3]) == mp.end())
//	{
//		cnt++;
//		mp[stack1[0] - stack1[1] - stack1[2] * stack1[3]] = 0;
//	}
//	if (mp.find(stack1[0] - stack1[1] * stack1[2] + stack1[3]) == mp.end())
//	{
//		cnt++;
//		mp[stack1[0] - stack1[1] * stack1[2] + stack1[3]] = 0;
//	}
//	if (mp.find(stack1[0] - stack1[1] * stack1[2] - stack1[3]) == mp.end())
//	{
//		mp[stack1[0] - stack1[1] * stack1[2] - stack1[3]] = 0;
//		cnt++;
//	}
//	if (mp.find(stack1[0] - stack1[1] * stack1[2] * stack1[3]) == mp.end())
//	{
//		mp[stack1[0] - stack1[1] * stack1[2] * stack1[3]] = 0;
//		cnt++;
//	}
//	if (mp.find(stack1[0] * stack1[1] + stack1[2] + stack1[3]) == mp.end())
//	{
//		mp[stack1[0] * stack1[1] + stack1[2] + stack1[3]] = 0;
//		cnt++;
//	}
//	if (mp.find(stack1[0] * stack1[1] + stack1[2] - stack1[3]) == mp.end())
//	{
//		mp[stack1[0] * stack1[1] + stack1[2] - stack1[3]] = 0;
//		cnt++;
//	}
//	if (mp.find(stack1[0] * stack1[1] + stack1[2] * stack1[3]) == mp.end())
//	{
//		mp[stack1[0] * stack1[1] + stack1[2] * stack1[3]] = 0;
//		cnt++;
//	}
//	if (mp.find(stack1[0] * stack1[1] - stack1[2] + stack1[3]) == mp.end())
//	{
//		mp[stack1[0] * stack1[1] - stack1[2] + stack1[3]] = 0;
//		cnt++;
//	}
//	if (mp.find(stack1[0] * stack1[1] - stack1[2] - stack1[3]) == mp.end())
//	{
//		mp[stack1[0] * stack1[1] - stack1[2] - stack1[3]] = 0;
//		cnt++;
//	}
//	if (mp.find(stack1[0] * stack1[1] - stack1[2] * stack1[3]) == mp.end())
//	{
//		mp[stack1[0] * stack1[1] - stack1[2] * stack1[3]] = 0;
//		cnt++;
//	}
//	if (mp.find(stack1[0] * stack1[1] * stack1[2] + stack1[3]) == mp.end())
//	{
//		mp[stack1[0] * stack1[1] * stack1[2] + stack1[3]] = 0;
//		cnt++;
//	}
//	if (mp.find(stack1[0] * stack1[1] * stack1[2] - stack1[3]) == mp.end())
//	{
//		mp[stack1[0] * stack1[1] * stack1[2] - stack1[3]] = 0;
//		cnt++;
//	}
//	if (mp.find(stack1[0] * stack1[1] * stack1[2] * stack1[3]) == mp.end())
//	{
//		mp[stack1[0] * stack1[1] * stack1[2] * stack1[3]] = 0;
//		cnt++;
//	}
//	return cnt;
//}
//
//void dfs(int u)
//{
//	if (u >= 4)
//	{
//		//for (int i = 0; i < 4; i++)
//			//cout << stack1[i] << " ";
//		ans += op1();
//		return;
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		if (!vis[i])
//		{
//			stack1[u] = num[i];
//			vis[i] = true;
//			dfs(u + 1);
//			vis[i] = false;
//			stack1[u] = 0;
//		}
//	}
//}
//
//int main()
//{
//	cin >> num[0] >> num[1] >> num[2] >> num[3];
//	dfs(0);
//	cout << ans << endl;
//}