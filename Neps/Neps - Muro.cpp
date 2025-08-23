#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair <int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e4+5;
const int mod = 1e9+7;
const int raiz = 20;
const int MAXL = 20;

int dp[MAXN];

int solve(int atual) {
    if(atual < 0) return 0;
    if(~dp[atual]) return dp[atual]%mod;
    int resp = 0;
    int n1 = solve(atual-1);
    int n2 = solve(atual-2);
    int n3 = solve(atual-3);
    resp += n1%mod;
    for(int i = 1; i <= 4; i++) {
        resp+=n2%mod;
        resp %= mod;
    }
    for(int i = 1; i <= 2; i++) {
        resp+=n3%mod;
        resp %= mod;
    }

    return dp[atual] = resp%mod;
}

signed main() {
    int n; cin >> n;
    memset(dp, -1, sizeof dp);
    dp[0] = 1;
    cout << solve(n) << endl;
}
