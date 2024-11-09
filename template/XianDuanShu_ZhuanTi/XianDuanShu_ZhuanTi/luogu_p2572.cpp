/*
tot记录区间中1的个数

len记录区间长度

l记录区间左端点

r记录区间右端点

sum1表示区间中最长连续的1的个数

lmax1表示区间中以左端点为起点从左往右的连续1的个数

rmax1表示区间中以右端点为起点从右往左的连续1的个数

0同理

laz1表示区间覆盖，0表示无操作，1表示0覆盖，2表示1覆盖

laz2表示区间反转，0表示无操作，1表示反转

定义了这么多就够了，然后考虑建树和update维护

update：

1.tot就直接加就行

2.lmax1更新要看一下左区间是否全为1，若全为1，则应加上右区间lmax1

3.rmax1更新要看一下右区间是否全为1，若全为1，则应加上左区间rmax1

4.sum1更新有三个来源，左区间sum1，右区间sum1，左区间rmax1+右区间lmax1

0维护的同理。

懒得写那多if，else，所以这里直接采用了三目运算符

build：

1.边找边求len

2.递归到叶子结点，看原序列中是1还是0,去更新叶子结点的东西

3.三目运算符对1和0的更新相反

4.最后update，由叶子结点回溯，维护整个大区间

然后基本的建树完成了，先不想那些个操作，把main框架写出，

change可以分标记表示修改操作，一个就够了

ask返回的东西不同，要分两个

然后main函数也搞定了

开始本题比较难理解的一块：down和laz标记。

1.如果之前有反转标记，但是又有覆盖标记，之前的反转标记就没用了，

所以当要打覆盖标记时，反转标记是可以清空的

2.区间覆盖的话就是那些东西等于len或0的问题

3.区间反转把0和1的东西交换就行了

4.down完标记记得清空

ask1返回tot就行

ask2分开找区间的话，还有可能是左区间的rmax1+右区间的lmax1，

这个还要取min，因为可能分到两个区间的长度到不了lmax1或rmax1*/


//#include<iostream>
//#include<cstdio>
//#define R register
//#define lson k<<1,l,mid   //减少码量或者为了好看
//#define rson k<<1|1,mid+1,r
//#define ls k<<1
//#define rs k<<1|1
//#define mid ((l+r)>>1)
//#define sum1(rt) tr[rt].sum1
//#define sum0(rt) tr[rt].sum0
//#define lmax1(rt) tr[rt].lmax1
//#define lmax0(rt) tr[rt].lmax0
//#define rmax1(rt) tr[rt].rmax1
//#define rmax0(rt) tr[rt].rmax0
//#define len(rt) tr[rt].len
//#define laz1(rt) tr[rt].laz1
//#define laz2(rt) tr[rt].laz2
//#define tot(rt) tr[rt].tot
//using namespace std;
//const int maxn = 200005;
//int n, m, a[maxn];
//struct node {
//    int sum1, lmax1, rmax1;
//    int tot, len, laz1, laz2;
//    int sum0, lmax0, rmax0;
//}tr[maxn << 2];
//inline int read() {
//    R int s = 0, w = 1;
//    R char ch = getchar();
//    while (ch < '0' || ch>'9') { if (ch == '-')w = -1; ch = getchar(); }
//    while (ch >= '0' && ch <= '9') { s = s * 10 + ch - '0'; ch = getchar(); }
//    return s * w;
//}
//inline void update(R int k) {
//    lmax1(k) = (sum1(ls) == len(ls)) ? len(ls) + lmax1(rs) : lmax1(ls);
//    rmax1(k) = (sum1(rs) == len(rs)) ? len(rs) + rmax1(ls) : rmax1(rs);
//    sum1(k) = max(max(sum1(ls), sum1(rs)), rmax1(ls) + lmax1(rs));
//    lmax0(k) = (sum0(ls) == len(ls)) ? len(ls) + lmax0(rs) : lmax0(ls);
//    rmax0(k) = (sum0(rs) == len(rs)) ? len(rs) + rmax0(ls) : rmax0(rs);
//    sum0(k) = max(max(sum0(ls), sum0(rs)), rmax0(ls) + lmax0(rs));
//    tot(k) = tot(ls) + tot(rs);
//}
//void build(R int k, R int l, R int r) {
//    len(k) = r - l + 1;
//    if (l == r) {
//        tot(k) = a[l];
//        lmax1(k) = rmax1(k) = sum1(k) = ((a[l] == 1) ? 1 : 0);
//        lmax0(k) = rmax0(k) = sum0(k) = ((a[l] == 1) ? 0 : 1);
//        return;
//    }
//    build(lson); build(rson);
//    update(k);
//}
//inline void down(R int k) {
//    if (laz1(k) == 1) {
//        sum0(ls) = lmax0(ls) = rmax0(ls) = len(ls);
//        tot(ls) = sum1(ls) = lmax1(ls) = rmax1(ls) = 0;
//        laz1(ls) = 1; laz2(ls) = 0;
//        sum0(rs) = lmax0(rs) = rmax0(rs) = len(rs);
//        tot(rs) = sum1(rs) = lmax1(rs) = rmax1(rs) = 0;
//        laz1(rs) = 1; laz2(rs) = 0;
//        laz1(k) = 0; laz2(k) = 0;
//    }
//    if (laz1(k) == 2) {
//        tot(ls) = sum1(ls) = lmax1(ls) = rmax1(ls) = len(ls);
//        sum0(ls) = lmax0(ls) = rmax0(ls) = 0;
//        laz1(ls) = 2; laz2(ls) = 0;
//        tot(rs) = sum1(rs) = lmax1(rs) = rmax1(rs) = len(rs);
//        sum0(rs) = lmax0(rs) = rmax0(rs) = 0;
//        laz1(rs) = 2; laz2(rs) = 0;
//        laz1(k) = 0; laz2(k) = 0;
//    }
//    if (laz2(k)) {
//        tot(ls) = len(ls) - tot(ls);
//        swap(sum0(ls), sum1(ls));
//        swap(lmax0(ls), lmax1(ls));
//        swap(rmax0(ls), rmax1(ls));
//        if (laz1(ls) == 1)laz1(ls) = 2;
//        else if (laz1(ls) == 2)laz1(ls) = 1;
//        else laz2(ls) ^= 1;
//        tot(rs) = len(rs) - tot(rs);
//        swap(sum0(rs), sum1(rs));
//        swap(lmax0(rs), lmax1(rs));
//        swap(rmax0(rs), rmax1(rs));
//        if (laz1(rs) == 1)laz1(rs) = 2;
//        else if (laz1(rs) == 2)laz1(rs) = 1;
//        else laz2(rs) ^= 1;
//        laz2(k) = 0;
//    }
//}
//void change(R int k, R int l, R int r, R int x, R int y, R int z) {
//    down(k);
//    if (l == x && y == r) {
//        if (z == 1) {
//            sum0(k) = lmax0(k) = rmax0(k) = len(k);
//            tot(k) = sum1(k) = lmax1(k) = rmax1(k) = 0;
//            laz1(k) = 1;
//            laz2(k) = 0;
//        }
//        else if (z == 2) {
//            tot(k) = sum1(k) = lmax1(k) = rmax1(k) = len(k);
//            sum0(k) = lmax0(k) = rmax0(k) = 0;
//            laz1(k) = 2;
//            laz2(k) = 0;
//        }
//        else {
//            tot(k) = len(k) - tot(k);
//            swap(sum0(k), sum1(k));
//            swap(lmax0(k), lmax1(k));
//            swap(rmax0(k), rmax1(k));
//            laz2(k) ^= 1;
//        }
//        return;
//    }
//    if (y <= mid)change(lson, x, y, z);
//    else if (x > mid)change(rson, x, y, z);
//    else change(lson, x, mid, z), change(rson, mid + 1, y, z);
//    update(k);
//}
//int ask1(R int k, R int l, R int r, R int x, R int y) {
//    down(k);
//    if (l == x && y == r) {
//        return tot(k);
//    }
//    if (y <= mid)return ask1(lson, x, y);
//    else if (x > mid)return ask1(rson, x, y);
//    else return ask1(lson, x, mid) + ask1(rson, mid + 1, y);
//}
//int  ask2(R int k, R int l, R int r, R int x, R int y) {
//    down(k);
//    if (l == x && y == r) {
//        return sum1(k);
//    }
//    if (y <= mid)return ask2(lson, x, y);
//    else if (x > mid)return ask2(rson, x, y);
//    else return max(max(ask2(lson, x, mid), ask2(rson, mid + 1, y)), min(lmax1(rs), y - mid) + min(rmax1(ls), mid - x + 1));
//}
//int main() {
//    n = read(); m = read();
//    for (R int i = 1; i <= n; ++i)
//        a[i] = read();
//    build(1, 1, n);
//    int opt, a, b;
//    while (m--) {
//        opt = read(); a = read() + 1; b = read() + 1;
//        if (opt == 0)change(1, 1, n, a, b, 1);
//        else if (opt == 1)change(1, 1, n, a, b, 2);
//        else if (opt == 2)change(1, 1, n, a, b, 3);
//        else if (opt == 3)printf("%d\n", ask1(1, 1, n, a, b));
//        else if (opt == 4)printf("%d\n", ask2(1, 1, n, a, b));
//    }
//    return 0;
//}