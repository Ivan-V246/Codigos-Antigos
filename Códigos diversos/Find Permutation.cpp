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
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 2*(1e5+10);
int n, m, cont = 1;
vector <int> grafo[MAXN];
vector <int> grau(MAXN);
vector <int> resp(MAXN);
vector <map <int, bool>> mapa(MAXN);

signed main() { 
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b;
        if (!mapa[a][b]) {
            grafo[a].emplace_back(b);
            grau[b]++;
            mapa[a][b] = 1;
        }
    }
    queue <int> fila;
    for (int i = 1; i <= n; i++) {
        if(grau[i] == 0) {
            fila.emplace(i);
        }
    }
    while(!fila.empty()) {
        if(fila.size() > 1) {
            cout << "No" << endl;
            return 0;
        }
        int atual = fila.front();
        fila.pop();
        resp[atual] = cont;
        cont++;
        for (auto x : grafo[atual]) {
            grau[x]--;
            if (grau[x] == 0) {
                fila.emplace(x);
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++) {
        cout << resp[i] << " ";
    }
    cout << endl;
}

/*Topo Sort simples, mas é um grafo não óbvio.*/
