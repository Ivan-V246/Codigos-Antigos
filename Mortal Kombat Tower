#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 2*(1e5+10);
int m, n;
vector <bool> torre;
int dp[MAXN][2];

int solve(int atual, bool amigo) {
    if(~dp[atual][amigo]) return dp[atual][amigo];
    if (atual > n) return 0;
    int resp = 0;
    if (amigo) {
        int so1 = INF;
        int so2 = INF;
        if (atual+1 < n) {
            so1 = solve(atual+1, !amigo) + torre[atual];
        } else {
            so1 = torre[atual];
        }
        if (atual +2 < n) {
            so2 = solve(atual+2, !amigo) + torre[atual] + torre[atual+1];
        } else {
            so2 = torre[atual] + torre[atual+1];
        }
        resp = min(so1, so2);
    } else {
        resp = min(solve(atual+1, !amigo), solve(atual+2, !amigo));
    }

    return dp[atual][amigo] = resp;
}

signed main() { op
    cin >> m;
    for (int j = 0; j < m; j++) {
        cin >> n;
        torre.clear();
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < n; i++) {
            bool a;
            cin >> a;
            torre.emplace_back(a);
        }
        torre.emplace_back(0);
        torre.emplace_back(0);
        solve(0, 1);
        cout << dp[0][1] << endl;
    }
}
/*Essa é uma Dp de corno bem chatinha nos casos bases, mas a ideia é simples.*/
