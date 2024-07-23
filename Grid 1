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
const int MAXN = (1e3+5);
const int mod = 1e9+7;
const int raiz = 1000;

char grid[MAXN][MAXN];
int dp[MAXN][MAXN];

signed main() {
    int n, m; cin >> n >> m;
    for(int i = 0; i <= n+1; i++) {
        for(int j = 0; j <= m+1; j++) {
            if(i == 0 or j == 0 or i == n+1 or j == m+1) {
                grid[i][j] = '#';
            } else {
                cin >> grid[i][j];
            }
        }
    }
    dp[n][m] = 1;
    for(int i = n; i >= 1; i--) {
        for(int j = m; j >= 1; j--) {
            if(grid[i+1][j] == '.') {
                dp[i][j] += (dp[i+1][j]%mod);
                dp[i][j] %= mod;
            } 
            if(grid[i][j+1] == '.') {
                dp[i][j] += (dp[i][j+1]%mod);
                dp[i][j] %= mod;
            }
        }
    }
    cout << (dp[1][1]%mod) << endl;
}
