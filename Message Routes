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

vector <int> grafo[MAXN];
int dist[MAXN];
vector <int> cam;

void rec(int atual) {
    cam.emplace_back(atual);
    for(auto x : grafo[atual]) {
        if(dist[x] == dist[atual]-1) {
            rec(x);
            return;
        }
    }
}

signed main() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        grafo[a].emplace_back(b);
        grafo[b].emplace_back(a);
    }
    memset(dist, INF, sizeof dist);
    dist[1] = 1;
    priority_queue <pii, vector<pii>, greater<pii>> fila;
    fila.emplace(1, 1);
    while(!fila.empty()) {
        int atual = fila.top().s;
        int custo = fila.top().f;
        fila.pop();
        if(dist[atual] < custo) continue;

        for(auto x : grafo[atual]) {
            if(dist[x] > custo+1) {
                dist[x] = custo+1;
                fila.emplace(custo+1, x);
            }
        }
    }
    if(dist[n] == INF) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << dist[n] << endl;
        rec(n);
        reverse(cam.begin(), cam.end());
        for(auto x : cam) {
            cout << x << " ";
        }
        cout << endl;
    }
}
