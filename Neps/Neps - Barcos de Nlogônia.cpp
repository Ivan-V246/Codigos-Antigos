#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e5+10;
const int MAXL = 20;
int pai[MAXN];
int sz[MAXN];
int menor[MAXL][MAXN];
int bl[MAXL][MAXN];
int niv[MAXN];
struct are{
    int cap, u, v;
};
vector <are> barcos;
vector <pii> grafo[MAXN];

int find(int x) {
    if(x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}

void unir(int u, int v) {
    u = find(u), v = find(v);
    if(sz[u] > sz[v]) swap(u, v);
    sz[v] += sz[u];
    pai[u] = v;
}

bool comp(are a, are b) { 
    return (a.cap > b.cap);
}

void dfs(int atual) {
    for(auto x : grafo[atual]) {
        if(niv[x.f] == -1) {
            niv[x.f] = niv[atual]+1;
            bl[0][x.f] = atual;
            menor[0][x.f] = x.s;
            dfs(x.f);
        }
    }
}

int lca(int u, int v) {
    int ans = INF;
    if(niv[u] > niv[v]) swap(u, v);
    int pulo = (niv[v]-niv[u]);
    for(int i = 19; i >= 0; i--) {
        if((pulo | (1 << i)) == pulo) {
            ans = min(ans, menor[i][v]);
            v = bl[i][v];
        }
    }

    if(u == v) return ans;

    for(int i = 19; i >= 0; i--) {
        if(bl[i][u] != bl[i][v]) {
            ans = min({ans, menor[i][u], menor[i][v]});
            u = bl[i][u];
            v = bl[i][v];
        }
    }
    ans = min({ans, menor[0][u], menor[0][v]});
    return ans;

}

signed main() { op
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        pai[i] = i;
        sz[i] = 1;
    }
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        are sla = {c, a, b};
        barcos.emplace_back(sla);
    }
    sort(barcos.begin(), barcos.end(), comp);
    for(auto x : barcos) {
        if(find(x.u) != find(x.v)) {
            grafo[x.u].emplace_back(x.v, x.cap);
            grafo[x.v].emplace_back(x.u, x.cap);
            unir(x.u, x.v);
        }
    }
    memset(niv, -1, sizeof niv);
    bl[0][1] = 1;
    niv[1] = 0;
    dfs(1);
    for(int i = 1; i < MAXL; i++) {
        for(int u = 1; u <= n; u++) {
            int a = bl[i-1][u];
            int b = bl[i-1][a];
            bl[i][u] = b;
            menor[i][u] = min(menor[i-1][u], menor[i-1][a]);
        }
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}
/*Questão divertida, usa coisa pra krl.*/
