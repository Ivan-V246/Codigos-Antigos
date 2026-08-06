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
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 2e5+5;
const int MOD = 1e9+7;

struct aresta {
    int u, v, custo, quant;
};

vector <aresta> lista;
map <pii, int> ind;
vector <int> grafo[MAXN];
bool vis[MAXN];

int dfs(int atual) {
    vis[atual] = 1;
    int s = 1;
    for(auto x : grafo[atual]) {
        if(!vis[x]) {
            int a = dfs(x);
            lista[ind[mkp(atual, x)]].quant = a;
            s += a;
        }
    }
    return s;
}

signed main() { op
    int n, q; cin >> n >> q;
    for(int i = 0; i < n-1; i++) {
        int a, b, v; cin >> a >> b >> v;
        aresta sla = {a, b, v, 0};
        lista.emplace_back(sla);
        ind[mkp(a, b)] = i;
        ind[mkp(b, a)] = i;
        grafo[a].emplace_back(b);
        grafo[b].emplace_back(a);
    }

    dfs(1); 
    int ans = 0;
    for(auto x : lista) {
        int temp = ((x.quant%MOD) * ((n-x.quant)%MOD)%MOD);
        ans += ((x.custo%MOD) * (temp%MOD)%MOD);
    }

    while(q--) {
        int a,b; cin >> a >> b;

        int coef = ((lista[a-1].quant % MOD) * ((n - lista[a-1].quant) % MOD)) % MOD;

        int old_contrib = ((lista[a-1].custo % MOD) * coef) % MOD;
        ans = (ans - old_contrib + MOD) % MOD;

        lista[a-1].custo = b;

        int new_contrib = ((lista[a-1].custo % MOD) * coef) % MOD;
        ans = (ans + new_contrib) % MOD;

        cout << ans << endl;
    }
}
