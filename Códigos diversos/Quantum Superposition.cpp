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
const int MAXN = 2*(1e5+10);
int n1, n2, m1, m2;
vector <int> grafo1[MAXN];
vector <int> grafo2[MAXN];
set <int> resp1;
set <int> resp2;
bool vi1[MAXN][1000];
bool vi2[MAXN][1000];

bool solve(int valor) {
    auto x = resp1.begin();
    auto y = resp2.end();
    auto z = resp1.end();
    y--;
    z--;
    if(valor > (*y + *z)  or valor < *resp1.begin() + *resp2.begin()) return 0;
    while(1) {
        if(*y == -INF or x == resp1.end()) return 0;
        int soma = *x + *y;
        if(soma == valor) {
            return 1;
        } else if(soma < valor) {
            x++;
        } else {
            y--;
        }
    }
}

signed main() { op
    cin >> n1 >> n2 >> m1 >> m2;
    for (int i = 0; i < m1; i++) {
        int a, b;
        cin >> a >> b;
        grafo1[a].emplace_back(b);
    }
    for (int i = 0; i < m2; i++) {
        int a, b;
        cin >> a >> b;
        grafo2[a].emplace_back(b);
    }


    queue <pair<int, int>> fila1;
    fila1.emplace(1, 0);
    while(!fila1.empty()) {
        int atual = fila1.front().f;
        int pas = fila1.front().s;
        if (atual == n1) {
            resp1.emplace(pas);
        }
        fila1.pop();
        for (auto x : grafo1[atual]) {
            if (!vi1[x][pas]) {
                fila1.emplace(x, pas+1);
                vi1[x][pas] = 1;
            }
        }
    }


    queue <pair<int, int>> fila2;
    fila2.emplace(1, 0);
    while(!fila2.empty()) {
        int atual = fila2.front().f;
        int pas = fila2.front().s;
        if (atual == n2) {
            resp2.emplace(pas);
        }
        fila2.pop();
        for (auto x : grafo2[atual]) {
            if (!vi2[x][pas]) {
                fila2.emplace(x, pas+1);
                vi2[x][pas] = 1;
            }
        }
    }


    int q;
    resp2.emplace(-INF);
    cin >> q;
    for (int i = 0; i < q; i++) {
        int val;
        cin >> val;
        bool resp = solve(val);
        if (resp) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}

/*Tive que otimizar bastante, tirei o int long long, evitei recalculos, troquei pra iterativo, fiz resp imediata para caso específicos. Enxuguei bit bonito.*/ 
