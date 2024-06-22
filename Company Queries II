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
const int MAXN = 2*(1e5+5);
const int mod = 1e9+7;
const int raiz = 20;
const int MAXL = 20;

int bl[MAXL][MAXN];
int niv[MAXN];

int lca(int u, int v) {
    if(niv[u] > niv[v]) swap(u, v);
    int pulo = niv[v] - niv[u];
    for(int i = 19; i >= 0; i--) {
        if((pulo | (1 << i)) == pulo) {
            v = bl[i][v];
        }
    }

    if(v == u) return v;

    for(int i = 19; i >= 0; i--) {
        if(bl[i][u] != bl[i][v]) {
            u = bl[i][u];
            v = bl[i][v];
        }
    }

    return bl[0][u];
}

signed main() {
    int n, q; cin >> n >> q;
    niv[1] = 1;
    for(int i = 2; i <= n; i++) {
        cin >> bl[0][i];
        niv[i] = niv[bl[0][i]] +1;
    }
    bl[0][1] = 1;
    for(int i = 1; i < MAXL; i++) {
        for(int u = 1; u <= n; u++) {
            int a = bl[i-1][u];
            int b = bl[i-1][a];
            bl[i][u] = b;
        }
    }
    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}
