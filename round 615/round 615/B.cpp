#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;

struct str {
    int x, y;
}a[N];
int n;

/*
1 2
1 3
3 3
4 3
5 5
*/
bool cmp(str a, str b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
void solve() {
    int x = 0, y = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    sort(a, a + n, cmp);
    string s;
    int i = 0;
    while (i < n) {
        //    cout<<x<<" "<<y<<endl;
        //    cout<<a[i].x<<" "<<a[i].y<<endl;
        if (x > a[i].x || y > a[i].y) {
            cout << "NO\n";
            return;
        }
        while (x < a[i].x) {
            x++;
            s += "R";
        }
        while (y < a[i].y) {
            y++;
            s += "U";
        }
        if (x == a[i].x && y == a[i].y) {
            i++;
        }
    }
    cout << "YES\n";
    cout << s << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

