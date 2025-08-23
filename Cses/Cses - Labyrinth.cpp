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
const int MAXN = 1e3+5;
const int mod = 1e9+7;
const int raiz = 20;
const int MAXL = 20;

int ii[4] = {1, -1, 0, 0};
int jj[4] = {0, 0, 1, -1};
char grid[MAXN][MAXN];
int dp[MAXN][MAXN];
int xi, xf, yi, yf;
string caminho;

void rec(int x, int y) {
    if(dp[x+1][y] == dp[x][y]-1) {
        caminho += 'U';
        rec(x+1, y);
        return;
    }
    if(dp[x-1][y] == dp[x][y]-1) {
        caminho += 'D';
        rec(x-1, y);
        return;
    }
    if(dp[x][y+1] == dp[x][y]-1) {
        caminho += 'L';
        rec(x, y+1);
        return;
    }
    if(dp[x][y-1] == dp[x][y]-1) {
        caminho += 'R';
        rec(x, y-1);
        return;
    }
}

signed main() { op
    int n, m; cin >> n >> m;
    memset(dp, INF, sizeof dp);
    for(int i = 0; i <= n+1; i++) {
        for(int j = 0; j <= m+1; j++) {
            if(i == 0 or j == 0 or j == m+1 or i == n+1) {
                grid[i][j] = '#';
            } else {
                cin >> grid[i][j];
                if(grid[i][j] == 'A') {
                    xi = i;
                    yi = j;
                } else if(grid[i][j] == 'B') {
                    xf = i;
                    yf = j;
                }
            }
        }
    }
    priority_queue <pii, vector<pii>, greater<pii>> fila;
    fila.emplace(0, mkp(xi, yi));
    dp[xi][yi] = 0;
    while(!fila.empty()) {
        int atualx = fila.top().s.f;
        int atualy = fila.top().s.s;
        int custo = fila.top().f;
        fila.pop();
        for(int i = 0; i < 4; i++) {
            if(grid[atualx+ii[i]][atualy+jj[i]] != '#' and dp[atualx+ii[i]][atualy+jj[i]] > custo+1) {
                dp[atualx+ii[i]][atualy+jj[i]] = custo+1;
                fila.emplace(custo+1, mkp(atualx+ii[i], atualy+jj[i]));
            }
        }
    }
    if(dp[xf][yf] != INF) {
        cout << "YES" << endl << dp[xf][yf] << endl;
        rec(xf, yf);
        reverse(caminho.begin(), caminho.end());
        cout << caminho << endl;
    } else {
        cout << "NO" << endl;
    }
}
