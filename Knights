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
const int mod = 1000000;
const int raiz = 1000;
const int MAXL = 20;

vector <pii> postos;
vector <pii> cercas;
vector <int> raio;
bitset <MAXN> cont[MAXN];

int dist(int u, int v) {
    int x = abs(postos[u].f - cercas[v].f);
    int y = abs(postos[u].s - cercas[v].s);

    int resp = ((x*x) + (y*y));
    return sqrt(resp);
}

signed main() {
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        postos.emplace_back(a, b);
    }
    for(int i = 0; i < m; i++) {
        int r, x, y; cin >> r >> x >> y;
        cercas.emplace_back(x, y);
        raio.emplace_back(r);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int sla = dist(i, j);
            if(sla < raio[j]) {
                cont[i][j] = 1;
            }
        }
    }
    while(k--) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        bitset <MAXN> sla = (cont[a] ^ cont[b]);
        cout << sla.count() << endl;
    }
}
