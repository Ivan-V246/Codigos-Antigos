#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair<int, pair<int, int> >
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
// #define vi vector <int>
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e4+10;
int n, m, t, b;
vector <pair<int, int>> grafo[MAXN];
int dist[MAXN];
int distdfs[MAXN];

int dfs(int atual, int ant, int custo) {
    int temp = INF;
    if(distdfs[atual] != INF) {
        int ciclo = custo - distdfs[atual];
        if(ciclo >= b) {
            int tot = ciclo + dist[atual]*2;
            return tot;
        }
        return INF;
    }
    distdfs[atual] = custo;
    for(auto x : grafo[atual]) {
        if(x.f == ant) continue;
        temp = min(temp, dfs(x.f, atual, x.s+custo));
    }
    return temp;
}

signed main() { op
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        grafo[a].emplace_back(b, c);
        grafo[b].emplace_back(a, c);
    }
    cin >> t;
    for(int i = 0; i < t; i++) {
        int a; cin >> a >> b;
        priority_queue <pii, vector<pii>, greater<pii>> fila;
        fila.emplace(0, mkp(a, a));
        memset(dist, INF, sizeof dist);
        dist[a] = 0;
        while(!fila.empty()) {
            int atual = fila.top().s.f;
            int ant = fila.top().s.s;
            int c = fila.top().f;
            fila.pop();
            if(dist[atual] < c) continue;
            for(auto x : grafo[atual]) {
                if(dist[x.f] > c+x.s) {
                    dist[x.f] = c+x.s;
                    fila.emplace(x.s+c, mkp(x.f, atual));
                }
            }
        }
        memset(distdfs, INF, sizeof distdfs);
        int ans = dfs(a, a, 0);
        if(ans == INF) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
}
/*É um Djkistra com DFS com ciclos. O samuell vai me explicar melhor como isso funciona, com a dfs linear.*/
