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
        string s; cin >> s;
        int y = 0;
        for(auto x : s) {
            if(x == 'Y') {
                y++;
            }
        }
        if(y > 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}
