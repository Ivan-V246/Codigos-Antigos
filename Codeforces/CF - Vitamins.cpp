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
#define vi vector <int>
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e3+10;
int n, m;
int dp[MAXN][10];

pii suco[MAXN];

int solve(int atual, int mask) {
    if(~dp[atual][mask]) return dp[atual][mask];
    if(mask == 7) return 0;
    if(atual == n) return 1e18;
    int resp = 1e18;
    resp = min(solve(atual+1, mask), resp);
    resp = min(resp, solve(atual+1, (mask | (suco[atual].s)))+suco[atual].f );

    return dp[atual][mask] = resp;
}

signed main() { 
    cin >> n;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++) {
        int a;
        string vit;
        cin >> a >> vit;
        suco[i].f = a;
        int temp = 0;
        for(auto x : vit) {
            temp |= (1 << (x - 'A'));
        }
        suco[i].s = temp;
    }
    int ans = solve(0, 0);
    if(ans == 1e18) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
/*Dp com bitmask, tranquilo.*/
