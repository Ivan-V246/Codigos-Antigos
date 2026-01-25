#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e6+5;


signed main() { op
    int t; cin >> t;
    while(t--) {
        int n, q; cin >> n >> q;
        int a[n], b[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        a[n-1] = max(a[n-1], b[n-1]);
        for(int i = n-2; i >= 0; i--) {
            a[i] = max(a[i], max(a[i+1], b[i]));
        }
        int ps[n+1];
        ps[0] = 0;
        for(int i = 0; i < n; i++) {
            ps[i+1] = a[i]+ps[i];
        }
        for(int i = 0; i < q; i++) {
            int l, r; cin >> l >> r;
            cout << ps[r] - ps[l-1] << " ";
        }
        cout << endl;
    }
}
