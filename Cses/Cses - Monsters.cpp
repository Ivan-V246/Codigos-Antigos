#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair <int, pair<int, int>>
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

char grid[MAXN][MAXN];
int distm[MAXN][MAXN];
int dp[MAXN][MAXN]; 
string caminho;

int ii[4] = {1, -1, 0, 0};
int jj[4] = {0, 0, 1, -1};

void rec(int x, int y) {
    if(dp[x+1][y] == dp[x][y]-1) {
        caminho+= 'U';
        rec(x+1, y);
        return;
    }
    if(dp[x-1][y] == dp[x][y]-1) {
        caminho+= 'D';
        rec(x-1, y);
        return;
    }
    if(dp[x][y+1] == dp[x][y]-1) {
        caminho+= 'L';
        rec(x, y+1);
        return;
    }
    if(dp[x][y-1] == dp[x][y]-1) {
        caminho+= 'R';
        rec(x, y-1);
        return;
    }
}


vector <pair<int,int>> monster; // X no f e y no s
signed main() { 
    int inix, iniy;
    int n, m; cin >> n >> m;
    for(int i = 0; i <= n+1; i++) {
        for(int j = 0; j <= m+1; j++) {
            if(i == 0 or j == 0 or i == n+1 or j == m+1) {
                grid[i][j] = '#';
            } else {
                cin >> grid[i][j];
                if(grid[i][j] == 'A') {
                    inix = i;
                    iniy = j;
                } else if(grid[i][j] == 'M') {
                    monster.emplace_back(i, j);
                }
            }
        }
    }
    priority_queue <pii, vector<pii>, greater<pii> > fila;
    memset(distm, INF, sizeof distm);
    memset(dp, INF, sizeof dp);
    for(auto x : monster) {
        fila.emplace(0, mkp(x.f, x.s));
        distm[x.f][x.s] = 0;
    }
    while(!fila.empty()) {
        int x = fila.top().s.f;
        int y = fila.top().s.s;
        int custo = fila.top().f;
        fila.pop();
        if(distm[x][y] < custo) continue;
        for(int i = 0; i < 4; i++) {
            if(grid[x+ii[i]][y+jj[i]] != '#' and distm[x+ii[i]][y+jj[i]] > custo+1) {
                distm[x+ii[i]][y+jj[i]] = custo+1;
                fila.emplace(custo+1, mkp(x+ii[i], y+jj[i]));
            }
        }
    }
    fila.emplace(0, mkp(inix, iniy));
    dp[inix][iniy] = 0;
    while(!fila.empty()) {
        int x = fila.top().s.f;
        int y = fila.top().s.s;
        int custo = fila.top().f;
        fila.pop();
        if(dp[x][y] < custo) continue;
        for(int i = 0; i < 4; i++) {
            if(grid[x+ii[i]][y+jj[i]] != '#' and dp[x+ii[i]][y+jj[i]] > custo+1 and custo+1 < distm[x+ii[i]][y+jj[i]]) {
                dp[x+ii[i]][y+jj[i]] = custo+1;
                fila.emplace(custo+1, mkp(x+ii[i], y+jj[i]));
            }
        }
    }
    int fimx = 0, fimy = 0;
    for(int i = 1; i <= n; i++) {
        if(dp[1][i] != INF) {
            fimx = 1;
            fimy = i;
        }
        if(dp[n][i] != INF) {
            fimx = n;
            fimy = i;
        }
    }
    for(int i = 1; i <= m; i++) {
        if(dp[i][1] != INF) {
            fimx = i;
            fimy = 1;
        }
        if(dp[i][m] != INF) {
            fimx = i;
            fimy = m;
        }
    }
    if(fimx == 0 and fimy == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << dp[fimx][fimy] << endl;
        rec(fimx, fimy);
        reverse(caminho.begin(), caminho.end());
        cout << caminho << endl;
    }
}
