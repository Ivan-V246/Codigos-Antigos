#include <bits/stdc++.h>
#include <cstring>
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
const int MAXN = 1e3+5;
const int MAXS = 6;

int n, p, s, dp[MAXN][MAXS];
vector <int> tempo_p(3), voltas_p(3);

int solve(int atual, int troca) {
    if(~dp[atual][troca]) return dp[atual][troca];
    if(atual >= n) {
        return 0;
    }

    int ans = INF;
    if(troca > 0) {
        for(int i = 0; i < 3; i++) {
            if(atual + voltas_p[i] <= n) {
                ans = min(ans, solve(atual+voltas_p[i], troca-1) + (tempo_p[i] * voltas_p[i]) + p);
            } else {
                ans = min(ans, solve(n, troca-1) + ((n-atual) * tempo_p[i]) + p);
            }
        }
    }

    return dp[atual][troca] = ans;
}

signed main() { 
    memset(dp, -1, sizeof dp);
    cin >> n >> p >> s;
    for(auto &x : tempo_p) cin >> x;
    for(auto &x : voltas_p) cin >> x;
    cout << solve(0, s+1)-p << endl;
}
