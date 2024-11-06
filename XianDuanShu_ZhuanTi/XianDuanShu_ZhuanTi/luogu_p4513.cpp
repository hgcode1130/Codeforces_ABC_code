//#include<cstdio>
//#include<iostream>
//
//#define N 2000001
//
//using namespace std;
//
//int n, m;
//
//struct Tree//�ýṹ��������
//{
//    int l, r;
//    long long maxleft, maxright, sum, ans;
//}tree[N];
//
//void putin(int k)//�ϲ����亯��
//{
//    tree[k].sum = tree[k * 2].sum + tree[k * 2 + 1].sum;
//    tree[k].maxleft = max(tree[k * 2].maxleft, tree[k * 2].sum + tree[k * 2 + 1].maxleft);
//    tree[k].maxright = max(tree[k * 2 + 1].maxright, tree[k * 2].maxright + tree[k * 2 + 1].sum);
//    tree[k].ans = max(max(tree[k * 2].ans, tree[k * 2 + 1].ans), tree[k * 2].maxright + tree[k * 2 + 1].maxleft);
//}
//
//void build(int l, int r, int k)//����
//{
//    tree[k].l = l; tree[k].r = r;
//    if (l == r)
//    {
//        scanf("%lld", &tree[k].sum);
//        tree[k].maxleft = tree[k].maxright = tree[k].ans = tree[k].sum;//��ʼ��ʱ����Ϊ����ڵ�ֻ��һ������maxleft��maxright��sum��ans��ֵ��һ����
//        return;//������return
//    }
//    int mid = (l + r) / 2;
//    build(l, mid, k * 2);//�ݹ齨��
//    build(mid + 1, r, k * 2 + 1);
//    putin(k);//�ϲ�����
//}
//
//Tree ask(int k, int x, int y)//ѯ�ʺ�������Ϊÿ�η��ص�maxleft��ֵ��һ�������Ҷ��ӵ����ݣ�����Ҫ����һ���ṹ��
//{
//    if (x <= tree[k].l && tree[k].r <= y)
//    {
//        return tree[k];
//    }
//    int mid = (tree[k].l + tree[k].r) / 2;
//    if (y <= mid) return ask(k * 2, x, y);//������ʵ�����ȫ��������ֱ��return
//    else
//    {
//        if (x > mid) return ask(k * 2 + 1, x, y);//������ʵ�����ȫ���Ҷ����Ҳֱ��return
//        else
//        {//��������Ҷ��Ӷ����ʣ�Ȼ��ϲ�����
//            Tree t, a = ask(k * 2, x, y), b = ask(k * 2 + 1, x, y);
//            t.maxleft = max(a.maxleft, a.sum + b.maxleft);//�����Ƶĺϲ�����
//            t.maxright = max(b.maxright, a.maxright + b.sum);
//            t.ans = max(max(a.ans, b.ans), a.maxright + b.maxleft);
//            return t;//���غϲ��������
//        }
//    }
//}
//
//void change(int k, int x, int y)//�����޸�
//{
//    if (tree[k].l == tree[k].r)
//    {
//        tree[k].maxleft = tree[k].maxright = tree[k].ans = tree[k].sum = y;
//        return;
//    }
//    int mid = (tree[k].l + tree[k].r) / 2;
//    if (x <= mid)change(k * 2, x, y);//�ж�Ŀ��λ��
//    else change(k * 2 + 1, x, y);
//    putin(k);//��Ϊֵ�Ѿ��ı��ˣ�����Ҫ�ϲ�����
//}
//
//int main()
//{
//    scanf("%d%d", &n, &m);
//    build(1, n, 1);
//    while (m--)
//    {
//        int choose, x, y;
//        scanf("%d%d%d", &choose, &x, &y);
//        if (choose == 1)
//        {
//            if (x > y)swap(x, y);//���Ǹ��ӵ㣬��Ϊ��Ŀû��ע��x<=y��������Ϊ����ҵ��˰���QAQ������ǿ����۲�֪���ģ���л���۵ľ�����
//            printf("%lld\n", ask(1, x, y).ans);
//        }
//        else
//        {
//            change(1, x, y);
//        }
//    }
//    return 0;
//}