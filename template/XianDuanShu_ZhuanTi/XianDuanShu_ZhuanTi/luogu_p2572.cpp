/*
tot��¼������1�ĸ���

len��¼���䳤��

l��¼������˵�

r��¼�����Ҷ˵�

sum1��ʾ�������������1�ĸ���

lmax1��ʾ����������˵�Ϊ���������ҵ�����1�ĸ���

rmax1��ʾ���������Ҷ˵�Ϊ���������������1�ĸ���

0ͬ��

laz1��ʾ���串�ǣ�0��ʾ�޲�����1��ʾ0���ǣ�2��ʾ1����

laz2��ʾ���䷴ת��0��ʾ�޲�����1��ʾ��ת

��������ô��͹��ˣ�Ȼ���ǽ�����updateά��

update��

1.tot��ֱ�ӼӾ���

2.lmax1����Ҫ��һ���������Ƿ�ȫΪ1����ȫΪ1����Ӧ����������lmax1

3.rmax1����Ҫ��һ���������Ƿ�ȫΪ1����ȫΪ1����Ӧ����������rmax1

4.sum1������������Դ��������sum1��������sum1��������rmax1+������lmax1

0ά����ͬ��

����д�Ƕ�if��else����������ֱ�Ӳ�������Ŀ�����

build��

1.���ұ���len

2.�ݹ鵽Ҷ�ӽ�㣬��ԭ��������1����0,ȥ����Ҷ�ӽ��Ķ���

3.��Ŀ�������1��0�ĸ����෴

4.���update����Ҷ�ӽ����ݣ�ά������������

Ȼ������Ľ�������ˣ��Ȳ�����Щ����������main���д����

change���Էֱ�Ǳ�ʾ�޸Ĳ�����һ���͹���

ask���صĶ�����ͬ��Ҫ������

Ȼ��main����Ҳ�㶨��

��ʼ����Ƚ�������һ�飺down��laz��ǡ�

1.���֮ǰ�з�ת��ǣ��������и��Ǳ�ǣ�֮ǰ�ķ�ת��Ǿ�û���ˣ�

���Ե�Ҫ�򸲸Ǳ��ʱ����ת����ǿ�����յ�

2.���串�ǵĻ�������Щ��������len��0������

3.���䷴ת��0��1�Ķ�������������

4.down���Ǽǵ����

ask1����tot����

ask2�ֿ�������Ļ������п������������rmax1+�������lmax1��

�����Ҫȡmin����Ϊ���ֵܷ���������ĳ��ȵ�����lmax1��rmax1*/


//#include<iostream>
//#include<cstdio>
//#define R register
//#define lson k<<1,l,mid   //������������Ϊ�˺ÿ�
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