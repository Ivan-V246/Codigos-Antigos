#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define inf 0x3f3f3f3f
#define pii pair <int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = (1e5+5);
const int mod = 1e17;
const int raiz = 1000;
const int MAXL = 20;

vector <int> grafo[MAXN];
int dp[MAXN];

int solve(int atual) {
    if(~dp[atual]) return dp[atual];
    int resp = 0;
    for(auto x : grafo[atual]) {
        resp = max(resp, solve(x)+1);
    }

    return dp[atual] = resp;
}

signed main() {
    memset(dp, -1, sizeof dp);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        grafo[a].emplace_back(b);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, solve(i));
    }
    cout << ans << endl;
}
