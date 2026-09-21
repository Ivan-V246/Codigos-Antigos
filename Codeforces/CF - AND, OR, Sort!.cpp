#include <bits/stdc++.h>
using namespace std;

#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define mkp make_pair
#define f first
#define s second
#define endl '\n'

#define dbg(x) cout << #x << " -> " << x << endl;
#define dbgv(x) cout << #x << endl; for(auto y : x) cout << y << " "; cout << endl;
#define ALL(x) (x).begin(), (x).end()

const int MAXN = 1e6+5;
const int MOD = 1e9+7;

signed main() { 
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<vi> ps(n+2, vi(2));
        int um = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') um++;
            ps[i+1][1] = um;
        }
        int zero = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '0') zero++;
            ps[i+1][0] = zero;
        }
        if(s[0] == '1') {
            cout << ps[1][0] << endl;
        } else {
            int ans = INF;
            for(int i = 1; i <= n; i++) {
                ans = min(ans, ps[i+1][0] + ps[i-1][1] );
            }
            cout << ans << endl;
        }
    }
}
