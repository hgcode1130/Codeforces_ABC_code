#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mx = 250501;//n*m+m<=250500
inline int Read() {
	int x = 0;
	char c = getchar();
	while (c > '9' || c < '0')c = getchar();
	while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	return x;
}
int n, m;
int cnt;
int l[mx], r[mx], u[mx], d[mx], col[mx], row[mx];//ÿ�������������ָ�룬�������� 
int h[mx];//ÿ�е�ͷ��� 
int s[mx];//ÿ�еĽڵ��� 
int ansk[mx];//ѡ����Щ���� 
void init(int m) {//m��Ԫ�� 
	for (register int i = 0; i <= m; i++) {
		r[i] = i + 1;
		l[i] = i - 1;
		u[i] = d[i] = i;
	}
	r[m] = 0;
	l[0] = m;
	memset(h, -1, sizeof(h));
	memset(s, 0, sizeof(s));
	cnt = m + 1;
}//��ʼ�� 
inline void link(int R, int C) {//R��C�в���� 
	s[C]++;
	row[cnt] = R;
	col[cnt] = C;
	u[cnt] = C;
	d[cnt] = d[C];
	u[d[C]] = cnt;
	d[C] = cnt;
	if (h[R] == -1)h[R] = r[cnt] = l[cnt] = cnt;//����û�е㣬ֱ�Ӽ��� 
	else {
		r[cnt] = h[R];
		l[cnt] = l[h[R]];
		r[l[h[R]]] = cnt;
		l[h[R]] = cnt;
	}
	cnt++;
	return;
}
inline void remove(int C) {//ɾ���漰C�еļ��� 
	r[l[C]] = r[C], l[r[C]] = l[C];
	for (int i = d[C]; i != C; i = d[i]) {
		for (int j = r[i]; j != i; j = r[j]) {
			u[d[j]] = u[j];
			d[u[j]] = d[j];
			s[col[j]]--;
		}
	}
}
inline void resume(int C) {//�ָ��漰C�еļ��� 
	for (int i = u[C]; i != C; i = u[i]) {
		for (int j = l[i]; j != i; j = l[j]) {
			u[d[j]] = j;
			d[u[j]] = j;
			s[col[j]]++;
		}
	}
	r[l[C]] = C;
	l[r[C]] = C;
}
bool dance(int deep) {
	if (r[0] == 0) {
		register int i = 0;
		for (i = 0; i < deep; i++)printf("%d ", ansk[i]);
		return 1;
	}
	int c = r[0];
	int i, j;
	for (i = r[0]; i != 0; i = r[i])if (s[i] < s[c])c = i;
	remove(c);
	for (i = d[c]; i != c; i = d[i]) {
		ansk[deep] = row[i];
		for (j = r[i]; j != i; j = r[j])remove(col[j]);
		if (dance(deep + 1))return 1;
		for (j = l[i]; j != i; j = l[j])resume(col[j]);
	}
	resume(c);
	return 0;
}
int main() {
	//	freopen("cin.txt","r",stdin);
	n = Read(), m = Read();
	register int i, j;
	int f;
	init(m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			f = Read();
			if (f)link(i, j);
		}
	}
	if (!dance(0))printf("No Solution!");
	return 0;
}