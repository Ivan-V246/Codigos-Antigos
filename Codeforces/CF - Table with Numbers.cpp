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
        int n, h, l; cin >> n >> h >> l;
        int tf = 0, x = 0, y = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            if(a <= h and a <= l) {
                tf++;
            } else if(a <= h and a > l) {
                x++;
            } else if(a > h and a <= l) {
                y++;
            }
        }
        ans += min(y, tf);
        tf -= min(y, tf);
        ans += min(x, tf);
        tf -= min(x, tf);
        ans += tf/2;
        cout << ans << endl;
    }
}
