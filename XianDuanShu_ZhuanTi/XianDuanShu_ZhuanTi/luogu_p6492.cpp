//#include<bits/stdc++.h>
//#define rap(i,first,last) for(int i=first;i<=last;++i)
//#define Lson now*2
//#define Rson now*2+1
//#define Middle (left+right)/2
//#define Left Lson,left,Middle
//#define Right Rson,Middle+1,right
//using namespace std;
//const int maxN = 2e5 + 7;
//struct Tree//����������
//{
//	int lmax, rmax, mmax, l, r, len;//������ʾ����Ҫ������ֵ
//}tree[maxN * 4];
//int N, M;
//void PushUp(int now)
//{
//	tree[now].lmax = tree[Lson].lmax;//��ֱ�ӽ��������������ֵ����������
//	tree[now].rmax = tree[Rson].rmax;
//	tree[now].l = tree[Lson].l;//������������ֵ
//	tree[now].r = tree[Rson].r;
//	tree[now].mmax = max(tree[Lson].mmax, tree[Rson].mmax);//�ȴ������������м�������������ȡһ������
//	if (tree[Lson].r != tree[Rson].l)//�����ҿ�������ʱ
//	{
//		tree[now].mmax = max(tree[now].mmax, tree[Lson].rmax + tree[Rson].lmax);//��Ҫ��ȡһ����ֵ
//		if (tree[Lson].mmax == tree[Lson].len)//����ע��3
//		{
//			tree[now].lmax = tree[Rson].lmax + tree[Lson].len;
//		}
//		if (tree[Rson].mmax == tree[Rson].len)
//		{
//			tree[now].rmax = tree[Lson].rmax + tree[Rson].len;
//		}
//	}
//}
//void Build(int now = 1, int left = 1, int right = N)//����,����˵
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
//void UpData(int change, int now = 1, int left = 1, int right = N)//�޸�,��Ϊֻ�е����޸�����Ҳ�ò��������,ֱ�ӽ�������Ҫ�޸�λ�õ��������䶼�޸ľͺ���
//{
//	if (left > change || right < change)return;
//	if (left == right)//��Ҷ�ڵ�ʱ
//	{
//		tree[now].l ^= 1;
//		tree[now].r ^= 1;
//		return;
//	}
//	UpData(change, Left);
//	UpData(change, Right);
//	PushUp(now);//�ϲ�
//}
//int Query()
//{
//	return max(tree[1].mmax, max(tree[1].lmax, tree[1].rmax));//ȫ�ֲ���,ֱ��������������һ����ĸ�������ʱ����
//}
//int main()
//{
//	scanf("%d%d", &N, &M);
//	Build();//����
//	int change;
//	rap(i, 1, M)
//	{
//		scanf("%d", &change);
//		UpData(change);//�޸�
//		printf("%d\n", Query());//��ѯ
//	}
//	return 0;
//}