#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 1e18
#define pii pair<int, pair<int, int>>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define vi vector <int>
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 2*(1e5+10);
int n, m, k;
struct way {
    int dest, tam;
};
int sala[MAXN];
map <int, vector<way>> grafo[MAXN];
map <int, int> dist[MAXN];

signed main() { op
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> sala[i+1];
    }
    for (int i = 0; i < m; i++) {
        int a, b, c, ind; cin >> a >> b >> c >> ind;
        way temp = {b, c};
        grafo[a][ind].emplace_back(temp);
        temp.dest = a;
        grafo[b][ind].emplace_back(temp);
    }
    priority_queue<pii, vector<pii>, greater<pii>> fila;
    fila.emplace(0, mkp(1, sala[1]));
    dist[1][sala[1]] = 0;
    while(!fila.empty()) {
        int atual = fila.top().s.f;
        int cartao = fila.top().s.s;
        int c = fila.top().f;
        fila.pop();
        if(c > dist[atual][cartao]) {
            continue;
        }
        for(auto x : grafo[atual][cartao]) {
            int novo = sala[x.dest];
            if(!dist[x.dest].count(cartao)) {
                dist[x.dest][cartao] = INF;     
                if(novo != 0) {
                    if(!dist[x.dest].count(novo)) {
                        dist[x.dest][novo] = INF;
                    }
                }
            }
            if(dist[x.dest][cartao] > c + x.tam) {
                dist[x.dest][cartao] = c + x.tam;
                fila.emplace(c+x.tam, mkp(x.dest, cartao));
            }
            if(novo != 0) {
                if(dist[x.dest][novo] > c + x.tam) {
                    dist[x.dest][novo] = c + x.tam;
                    fila.emplace(c+x.tam, mkp(x.dest, novo));
                }
            }
        }
    }
    int ans = INF;
    for(auto x : dist[n]) {
        ans = min(x.s, ans);
    }
    if(ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
/*Aprendizados do dia:
1 - Dijkistras tem continue;
2 - Preciso aprender a malinar nas estruturas direito. Elas podem ficar complexas, e consumir tempo se usadas de forma burra;
3 - Array são mais rápidos do que vectors, pq vectors são diferentes por baixo dos panos. Se não vai usar emplace_back ou redefinir o tamanho, usa array;
.*/
