//#include<bits/stdc++.h>
//#define rap(i,first,last) for(int i=first;i<=last;++i)
//#define Lson now*2
//#define Rson now*2+1
//#define Middle (left+right)/2
//#define Left Lson,left,Middle
//#define Right Rson,Middle+1,right
//using namespace std;
//const int maxN = 2e5 + 7;
//struct Tree//保存整棵树
//{
//	int lmax, rmax, mmax, l, r, len;//如上所示的需要保留的值
//}tree[maxN * 4];
//int N, M;
//void PushUp(int now)
//{
//	tree[now].lmax = tree[Lson].lmax;//先直接将子树的左右最长赋值到整颗数中
//	tree[now].rmax = tree[Rson].rmax;
//	tree[now].l = tree[Lson].l;//整颗树的左右值
//	tree[now].r = tree[Rson].r;
//	tree[now].mmax = max(tree[Lson].mmax, tree[Rson].mmax);//先从左右子树中中间的最长符合区间中取一个最大的
//	if (tree[Lson].r != tree[Rson].l)//当左右可以相连时
//	{
//		tree[now].mmax = max(tree[now].mmax, tree[Lson].rmax + tree[Rson].lmax);//需要再取一个大值
//		if (tree[Lson].mmax == tree[Lson].len)//如上注意3
//		{
//			tree[now].lmax = tree[Rson].lmax + tree[Lson].len;
//		}
//		if (tree[Rson].mmax == tree[Rson].len)
//		{
//			tree[now].rmax = tree[Lson].rmax + tree[Rson].len;
//		}
//	}
//}
//void Build(int now = 1, int left = 1, int right = N)//建树,不多说
//{
//	tree[now].len = right - left + 1;
//	if (left == right)
//	{
//		tree[now].lmax = tree[now].rmax = 1;
//		tree[now].mmax = 1;
//		tree[now].l = tree[now].r = 1;
//		return;
//	}
//	Build(Left);
//	Build(Right);
//	PushUp(now);
//}
//void UpData(int change, int now = 1, int left = 1, int right = N)//修改,因为只有单点修改所以也用不上懒标记,直接将覆盖需要修改位置的所有区间都修改就好了
//{
//	if (left > change || right < change)return;
//	if (left == right)//到叶节点时
//	{
//		tree[now].l ^= 1;
//		tree[now].r ^= 1;
//		return;
//	}
//	UpData(change, Left);
//	UpData(change, Right);
//	PushUp(now);//合并
//}
//int Query()
//{
//	return max(tree[1].mmax, max(tree[1].lmax, tree[1].rmax));//全局查找,直接在整颗树中找一个最长的附和条件时区间
//}
//int main()
//{
//	scanf("%d%d", &N, &M);
//	Build();//建树
//	int change;
//	rap(i, 1, M)
//	{
//		scanf("%d", &change);
//		UpData(change);//修改
//		printf("%d\n", Query());//查询
//	}
//	return 0;
//}