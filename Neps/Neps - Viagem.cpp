#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f 
#define pii pair<int, pair<int, int>>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define vi vector <int>
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e4+10;
int v, n, m, ini, fim;
vector <vi> dist(210, vi(MAXN, INF));
struct way{
    int dest, tempo, custo;
};

vector <way> grafo[MAXN];

signed main() { 
    cin >> v >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, t, c;
        cin >> a >> b >> t >> c;
        way temp = {b, t, c};
        grafo[a].emplace_back(temp);
        temp.dest = a;
        grafo[b].emplace_back(temp);
    }
    cin >> ini >> fim;
    priority_queue <pii, vector<pii>, greater<pii>> fila;
    fila.emplace(0, mkp(0, ini));
    dist[0][ini] = 0;
    while(!fila.empty()) {
        int atual = fila.top().s.s;
        int c = fila.top().s.f;
        int t = fila.top().f;
        fila.pop();
        for(auto x : grafo[atual]) {
            if(c+ x.custo <= v) {
                if(t+ x.tempo < dist[c+x.custo][x.dest]) {
                    dist[c+x.custo][x.dest] = t + x.tempo;
                    fila.emplace(dist[c+x.custo][x.dest], mkp(c+x.custo ,x.dest));
                }
            }
        }
    }
    int ans = INF; 
    bool flag = 0;
    for (int i = 0; i <= v; i++) {
        if(dist[i][fim] < ans) {
            flag = 1;
            ans = dist[i][fim];
        }
    }
    if(flag) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}
/*Dp em dijkistra. A ideia é que você pode ter diferentes menores caminhos pra alguma outra característica, então tem que poder testar mais casos, que de outra forma já constariam como calculados.*/
