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
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 15*1e4+10;
int n, m;
vector <int> grafo[MAXN];
int id[MAXN];
int sz[MAXN];
bool vi[MAXN];

int find(int x) {
    if(id[x] == x) return x;
    return id[x] = find(id[x]);
}

void uni(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;
    if(sz[x] > sz[y]) swap(x, y);
    id[x] = y;
    sz[y] += sz[x];
}

signed main() { op
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        id[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        grafo[a].emplace_back(b);
        grafo[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if(!vi[i]) {
            vi[i] = 1;
            queue <int> fila;
            for (auto x : grafo[i]) {
                fila.emplace(x);
                if(grafo[i].size() != grafo[x].size()) {
                    cout << "NO" << endl;
                    return 0;
                }
                uni(i, x);
                vi[x] = 1;
            }
            int temp = find(i);
            while(!fila.empty()) {
                int atual = fila.front();
                fila.pop();
                for(auto x : grafo[atual]) {
                    if(find(x) != temp) {
                        cout << "NO" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "YES" << endl;
}
/*DFS e DSU, utilizando os conjuntos como uma "marca" de quem o cara tá ligado. Útil. Precisei me atentar nos contracasos em que se o tamanho do cara que eu tava indo, era diferente do cara origem, já tinha dado errado.*/
