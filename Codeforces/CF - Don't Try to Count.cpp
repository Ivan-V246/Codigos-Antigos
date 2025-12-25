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

bool match(string a, string b, int ind) {
    for(int j = 0; j < b.size(); j++, ind++) {
        if(a[ind] != b[j]) return false;
    }
    return true;
}
bool contem(string a, string b) { //Retorna se b é substring de a
    if(b.size() > a.size()) return false;
    bool resp = 0;
    for(int i = 0; i <= a.size()-b.size(); i++) {
        if(a[i] == b[0]) {
            if(match(a, b, i)) {
                return true;
            }
        }
    }
    return false;
}

signed main() { op
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        string x, s; cin >> x >> s;
        int ans = 0;
        while(ans <= 6) {
            if(contem(x, s)) {
                break;
            } else {
                x += x;
                ans++;
            }
        }
        if(ans <= 6) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
