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
// #define vi vector <int>
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e4+10;
int n, m, p;
int ans = -1e4;
int grid[8][8];
vector <pii> pb;

void solve (int tot, int atual) {

    if(atual == pb.size()) {
        ans = max(ans, tot);
        return;
    }
    int x = pb[atual].f;
    int y = pb[atual].s;
    int resp = 0;
    bool flag = 1;
    if(grid[x][y] != 0) {
        flag = 0;
    }
    if(grid[x+1][y] == 1) {
        flag = 0;
    }
    if(grid[x-1][y] == 1) {
        flag = 0;
    }
    if(grid[x][y+1] == 1) {
        flag = 0;
    }
    if(grid[x][y-1] == 1) {
        flag = 0;
    }
    
    if(flag) {
        grid[x][y] = 1;
        solve(tot+1, atual+1);
        grid[x][y] = 0;
    }
    solve(tot, atual+1);
    
}

signed main() {
    cin >> n >> m >> p;
    for(int i = 0; i < n+2; i++) {
        for(int j = 0; j < m+2; j++) {
            if(i == 0 or j == 0 or i == n+1 or j == m+1) {
                grid[i][j] = 3;
            }
        }
    }
    for(int i = 0; i < p; i++) {
        int l, c; cin >> l >> c;
        grid[l][c] = 2;
        pb.emplace_back(l+1, c);
        pb.emplace_back(l-1, c);
        pb.emplace_back(l, c+1);
        pb.emplace_back(l, c-1);
    }
    solve(0, 0);
    cout << ans << endl;
}