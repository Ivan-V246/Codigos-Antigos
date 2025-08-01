#include <bits/stdc++.h>

#define ALL(x) x.begin(), x.end()
#define endl '\n'

#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int MAXN = 1e6+5;
const int MOD = 1e9 +7;

int n;
vector <int> grafo[6];
int dp[MAXN][6];

int solve(int atual, int ant) {
    if(~dp[atual][ant]) return dp[atual][ant];
    dp[atual][ant] = 0;
    for(auto x : grafo[ant]) {
        dp[atual][ant] += solve(atual-1, x)%MOD; 
        dp[atual][ant]%=MOD;
    }
    return dp[atual][ant]%=MOD;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    grafo[0] = {0, 2, 3, 4};
    grafo[3] = {0, 2, 3, 4};
    grafo[4] = {0, 2, 3, 4};
    grafo[5] = {1, 5};
    grafo[1] = {0, 1, 2, 3, 4, 5};
    grafo[2] = {0, 1, 2, 3, 4, 5};
    memset(dp, -1, sizeof dp);
    dp[1][1] = 2;
    dp[1][2] = 2;
    dp[1][0] = 1;
    dp[1][3] = 1;
    dp[1][4] = 1;
    dp[1][5] = 1;
    int t; cin >> t; 
    while(t--) {
        cin >> n;
        cout << solve(n, 1) << endl;
    }
}
