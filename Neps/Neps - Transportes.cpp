#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define inf 0x3f3f3f3f
#define pii pair <int, pair<int, int>>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
#define db cout << "blz" << endl;
const int MAXN = 1*(1e5+5);
const int mod = 1e9+7;
const int raiz = 1000;

map <int, int> dist[MAXN];
int pre[MAXN];
vector <pair <int, int> > grafo[MAXN];

signed main() { op
    int n, m, k; cin >> n >> m >> k;
    for(int i = 1; i <= k; i++) {
        cin >> pre[i];
    }
    for(int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        grafo[a].emplace_back(b, c);
        grafo[b].emplace_back(a, c);
    }
    int ini, fim; cin >> ini >> fim;
    dist[ini][0] = 0;
    priority_queue <pii, vector<pii>, greater<pii>> fila;
    fila.emplace(0, mkp(ini, 0));
    while(!fila.empty()) {
        int atual = fila.top().s.f;
        int id = fila.top().s.s;
        int custo = fila.top().f;
        fila.pop();
        if(custo > dist[atual][id]) continue;
        for(auto x : grafo[atual]) {
            if(!dist[x.f].count(x.s)) {
                dist[x.f][x.s] = 1e17;
            }
            if(!dist[atual].count(x.s)) {
                dist[atual][x.s] = custo+pre[x.s];
            }
            int aux = custo;
            if(id != x.s) {
                aux += pre[x.s];
            }
            if(aux < dist[x.f][x.s]) {
                dist[x.f][x.s] = aux;
                fila.emplace(aux, mkp(x.f, x.s));
            }
        }
    }
    if(dist[fim].size() == 0) {
        cout << -1 << endl;
    } else {
        int ans = 1e17;
        for(auto x : dist[fim]) {
            ans = min(ans, x.s);
        }
        cout << ans << endl;
    }
}
