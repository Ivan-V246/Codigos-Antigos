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
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e5+5;
const int mod = 1e9+7;
const int raiz = 20;
const int MAXL = 20;

int pai[MAXN];
int sz[MAXN];

int find(int u) {
    if(u == pai[u]) return u;
    return pai[u] = find(pai[u]);
}

void unir(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return;
    if(sz[u] > sz[v]) swap(u, v);
    sz[v] += sz[u];
    pai[u] = v;
}

signed main() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        sz[i] = 1;
        pai[i] = i;
    }
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        unir(a, b);
    }
    int ans = 0;
    vector <pii> lista;
    for(int i = 2; i <= n; i++) {
        if(find(i) != find(1)) {
            ans++;
            lista.emplace_back(i, 1);
            unir(1, i);
        }
    }
    cout << ans << endl;
    for(auto x : lista) {
        cout << x.f <<  " " << x.s << endl;
    }
}
