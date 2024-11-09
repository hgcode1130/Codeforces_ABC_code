//#include<cstdio>
//#include<iostream>
//
//#define N 2000001
//
//using namespace std;
//
//int n, m;
//
//struct Tree//用结构体来存树
//{
//    int l, r;
//    long long maxleft, maxright, sum, ans;
//}tree[N];
//
//void putin(int k)//合并区间函数
//{
//    tree[k].sum = tree[k * 2].sum + tree[k * 2 + 1].sum;
//    tree[k].maxleft = max(tree[k * 2].maxleft, tree[k * 2].sum + tree[k * 2 + 1].maxleft);
//    tree[k].maxright = max(tree[k * 2 + 1].maxright, tree[k * 2].maxright + tree[k * 2 + 1].sum);
//    tree[k].ans = max(max(tree[k * 2].ans, tree[k * 2 + 1].ans), tree[k * 2].maxright + tree[k * 2 + 1].maxleft);
//}
//
//void build(int l, int r, int k)//建树
//{
//    tree[k].l = l; tree[k].r = r;
//    if (l == r)
//    {
//        scanf("%lld", &tree[k].sum);
//        tree[k].maxleft = tree[k].maxright = tree[k].ans = tree[k].sum;//初始化时，因为这个节点只有一个数，maxleft、maxright、sum和ans的值都一样。
//        return;//别忘了return
//    }
//    int mid = (l + r) / 2;
//    build(l, mid, k * 2);//递归建树
//    build(mid + 1, r, k * 2 + 1);
//    putin(k);//合并区间
//}
//
//Tree ask(int k, int x, int y)//询问函数，因为每次返回的maxleft等值不一定是左右儿子的数据，所以要返回一个结构体
//{
//    if (x <= tree[k].l && tree[k].r <= y)
//    {
//        return tree[k];
//    }
//    int mid = (tree[k].l + tree[k].r) / 2;
//    if (y <= mid) return ask(k * 2, x, y);//如果访问的区间全在左儿子里，直接return
//    else
//    {
//        if (x > mid) return ask(k * 2 + 1, x, y);//如果访问的区间全在右儿子里，也直接return
//        else
//        {//否则就左右儿子都访问，然后合并区间
//            Tree t, a = ask(k * 2, x, y), b = ask(k * 2 + 1, x, y);
//            t.maxleft = max(a.maxleft, a.sum + b.maxleft);//做类似的合并区间
//            t.maxright = max(b.maxright, a.maxright + b.sum);
//            t.ans = max(max(a.ans, b.ans), a.maxright + b.maxleft);
//            return t;//返回合并后的区间
//        }
//    }
//}
//
//void change(int k, int x, int y)//单点修改
//{
//    if (tree[k].l == tree[k].r)
//    {
//        tree[k].maxleft = tree[k].maxright = tree[k].ans = tree[k].sum = y;
//        return;
//    }
//    int mid = (tree[k].l + tree[k].r) / 2;
//    if (x <= mid)change(k * 2, x, y);//判断目标位置
//    else change(k * 2 + 1, x, y);
//    putin(k);//因为值已经改变了，所以要合并区间
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
//            if (x > y)swap(x, y);//这是个坑点，因为题目没有注明x<=y，就是因为这个我调了半天QAQ，最后还是看讨论才知道的，感谢讨论的巨佬们
//            printf("%lld\n", ask(1, x, y).ans);
//        }
//        else
//        {
//            change(1, x, y);
//        }
//    }
//    return 0;
//}