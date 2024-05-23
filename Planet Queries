#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 1e18
#define pii pair<int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
// #define vi vector <int>
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 2*(1e5+10);
const int MAXL = 31;
int n, m;
int bl[MAXL][MAXN];
signed main() { op
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> bl[0][i];
    }
    for(int i = 1; i < MAXL; i++) {
        for(int u = 1; u <= n; u++) {
            int a = bl[i-1][u];
            int b = bl[i-1][a];
            bl[i][u] = b;
        }
    }
    for(int j = 0; j < m; j++) {
        int ini, k; cin >> ini >> k;
        for(int i = 31; i >= 0; i--) {
            if((k | (1 << i)) == k) {
                ini = bl[i][ini];
            }
        }
        cout << ini << endl;
    }
}
