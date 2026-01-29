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
        string s = "";
        int n; string str; cin >> n >> str;
        if(n < 3) {
            cout << 1 << endl;
            continue;
        }
        s+=str;
        int ans = 0;
        int i = 0;
        int z = 0;
        for(; i < n; i++) {
            if(s[i] == '0') {
                z++;
            } else {
                ans++;
                z = max(0LL, z-1);
                i++;
                break;
            }
        }
        ans += z/3;
        if(z%3 != 0) ans++;
        z = 0;
        for(; i < n; i++) {
            if(s[i] == '0') {
                z++;
            } else {
                ans++;
                z= max(0LL, z-2);
                ans += z/3;
                if(z%3 != 0) ans++;
                z = 0;
            }
        }
        z = max(0LL, z-1);
        ans += z/3;
        if(z%3 != 0) ans++;
        z = 0;
        cout << ans << endl;
    }
}
