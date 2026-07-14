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
const int MAXN = 2e5+5;

vector <int> lista(MAXN);
bool flipa[MAXN];
int dp[2][MAXN];

int solve(int atual, bool flipado) {
    if(atual == 0) return 0;

    if(~dp[flipado][atual]) return dp[flipado][atual];
    
    int ans = 0;

    if(flipado) {
        ans = solve(atual-1, flipado) - lista[atual];
    } else {
        ans = solve(atual-1, flipado) + lista[atual];
    }

    if(flipa[atual]) {
        if(flipado) {
            ans = max(ans, solve(atual-1, !flipado) + lista[atual]);
        } else {
            ans = max(ans, solve(atual-1, !flipado) - lista[atual]);
        }
    }

    return dp[flipado][atual] = ans;
}

signed main() { op
    int t; cin >> t;
    while(t--) {
        memset(flipa, 0, sizeof flipa);
        memset(dp, -1, sizeof dp);
        int n, m; cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            cin >> lista[i];
        }
        for(int i = 0; i < m; i++) {
            int a; cin >> a; 
            flipa[a] = 1;
        }
        cout << solve(n, 0) << endl;
    }
}
