#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 2e5+5;

int n, lista[MAXN];
int dp[MAXN];

int solve(int atual) {
    if(atual > n+1) return INF; 
    if(atual == n+1) return 0;

    if(~dp[atual]) return dp[atual];

    return dp[atual] = min(solve(atual+1)+1, solve(atual+lista[atual]+1));
}

signed main() { op
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> lista[i];
        }
        memset(dp, -1, sizeof dp);
        cout << solve(1) << endl;
    }
}
