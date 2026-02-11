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


signed main() { 
    int t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        if(n%2 == 0 and x%2 == 1) {
            cout << -1 << endl;
            continue;
        }
        if(x == 1 and n != 1) {
            cout << -1 << endl;
            continue;
        }
        if(n == 1) {
            if(x <= 9) {
                cout << x << endl;
                continue;
            }
        }
        if(n*9 < x) {
            cout << -1 << endl;
            continue;
        }
        int nn = n/2;
        int nx = x/2;
        string ans = "";
        for(int i = 0; i < nn; i++) {
            int m = min(nx, 9LL);
            ans += (max(m, 0LL)) + '0';
            nx -= max(m, 0LL);
            x-= max(m, 0LL)*2;
        }
       if(n%2 == 1) {
            string ori = ans;
            reverse(ans.begin(), ans.end());
            ori += '0'+x;
            cout << ori << ans << endl;
        } else {
            string ori = ans;
            reverse(ans.begin(), ans.end());
            cout << ori << ans << endl;
        }
    }
}
