#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e3+5;
const int mod = 1e9+7;
const int raiz = 20;
const int MAXL = 20;

char grid[MAXN][MAXN];

int ii[4] = {1, -1, 0, 0};
int jj[4] = {0, 0, 1, -1};

void solve(int x, int y) {
    grid[x][y] = '#';
    for(int a = 0; a < 4; a++) {
        if(grid[x+ii[a]][y+jj[a]] == '.') {
            solve(x+ii[a], y+jj[a]);
        }
    }
}

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
    int ans = 0;
    for(int i = 0; i <= n+1; i++) {
        for(int j = 0; j <= m+1; j++) {
            if(grid[i][j] == '.') {
                ans++;
                solve(i, j);
            }
        }
    }
    cout << ans << endl;
}
