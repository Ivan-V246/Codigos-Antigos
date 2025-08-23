#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair<int, pair<int, int>>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e5+10;
int n;
int dp[MAXN][4];
struct dia {
    int a;
    int b;
    int c;
};
vector <dia> dias;

int solve(int atual, int ant) {
    if(~dp[atual][ant]) return dp[atual][ant];
    if(atual == n) return 0;
    int resp = -INF;
    if(ant != 1) {
        resp = max(resp, solve(atual+1, 1) + dias[atual].a);
    }
    if(ant != 2) {
        resp = max(resp, solve(atual+1, 2) + dias[atual].b);
    }
    if (ant != 3) {
        resp = max(resp, solve(atual+1, 3) + dias[atual].c);
    }
    return dp[atual][ant] = resp;
}

signed main() {
    memset(dp, -1, sizeof dp); 
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        dia sla = {a, b, c};
        dias.emplace_back(sla);
    }
    cout << solve(0, 0) << endl;
}
