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
        int m = INF;
        for(int i = 0; i < 3; i++) {
            int a; cin >> a;
            m = min(m, a);
        }
        cout << n-m << endl;
    }
}
