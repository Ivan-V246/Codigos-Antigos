#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 110;
int n, m;
char mapa[MAXN][MAXN];
bool vi[MAXN][MAXN];


int main() { _
    cin >> n >> m;
    int x, y;
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <= m+1; j++) {
            if (i == 0 or i == n+1 or j == 0 or j == m+1) {
                mapa[i][j] = 'z';
            } else {
                cin >> mapa[i][j];
                if (mapa[i][j] == 'o') {
                    x = i;
                    y = j;
                }
            }
        }
    }
    queue <pii> fila;
    fila.emplace(x, y);
    vi[x][y] = 1;
    while(!fila.empty()) {
        int atx = fila.front().f;
        int aty = fila.front().s;
        x = atx;
        y = aty;
        fila.pop();
        if (mapa[atx][aty+1] == 'H' and !vi[atx][aty+1]) {
            vi[atx][aty+1] = 1;
            fila.emplace(atx, aty+1);
        }
        if (mapa[atx][aty-1] == 'H' and !vi[atx][aty-1]) {
            vi[atx][aty-1] = 1;
            fila.emplace(atx, aty-1);
        }
        if (mapa[atx+1][aty] == 'H' and !vi[atx+1][aty]) {
            vi[atx+1][aty] = 1;
            fila.emplace(atx+1, aty);          
        }
        if (mapa[atx-1][aty] == 'H' and !vi[atx-1][aty]) {
            vi[atx-1][aty] = 1;
            fila.emplace(atx-1, aty);          
        }
    }
    cout << x << " " << y << endl;
}