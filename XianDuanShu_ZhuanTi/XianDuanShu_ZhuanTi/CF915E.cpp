//#include<bits/stdc++.h>
//using namespace std;
//int tree[15001000], lson[15001000], rson[15001000], tag[15001000], d;
//long long n, q, l, r, k;
//void freelazy(int x, int l, int r)
//{
//    int mid = (l + r) / 2;
//    if (tree[x])
//    {
//        tree[lson[x]] = (mid - l + 1);
//        tree[rson[x]] = (r - (mid + 1) + 1);
//    }
//    else
//    {
//        tree[lson[x]] = 0;
//        tree[rson[x]] = 0;
//    }
//    tag[lson[x]] = 1;
//    tag[rson[x]] = 1;
//    tag[x] = 0;
//    //正常的懒标记下放操作
//}
//void add(int x, int l, int r, int ql, int qr, int sd)
//{
//
//    if (ql <= l && qr >= r)
//    {
//        tree[x] = (r - l + 1) * sd; tag[x] = 1;
//        return;
//    }
//    if (!lson[x])
//    {
//        d++;
//        lson[x] = d;
//    }
//    if (!rson[x])
//    {
//        d++;
//        rson[x] = d;
//    }//要用就开点
//    //上面要记得记录左右儿子
//    if (tag[x]) freelazy(x, l, r);
//    int mid = (l + r) / 2;
//    if (ql > mid)
//    {
//        add(rson[x], mid + 1, r, ql, qr, sd);
//    }
//    else
//        if (qr <= mid)
//        {
//            add(lson[x], l, mid, ql, qr, sd);
//        }
//        else
//        {
//            add(lson[x], l, mid, ql, mid, sd);
//            add(rson[x], mid + 1, r, mid + 1, qr, sd);
//        }
//    tree[x] = tree[lson[x]] + tree[rson[x]];
//    //正常的线段树操作
//}
//int main()
//{
//    cin >> n >> q; d = 1;
//    for (int i = 1; i <= q; i++)
//    {
//        scanf("%d%d%d", &l, &r, &k);//本题用cin、cout会有超时风险
//        if (l > r) swap(l, r);
//        if (k == 1)
//        {
//            add(1, 1, n, l, r, k);
//        }
//        else
//        {
//            add(1, 1, n, l, r, 0);
//        }
//        printf("%d\n", n - tree[1]);
//    }
//    return 0;
//}