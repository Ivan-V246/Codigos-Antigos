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
const int MAXN = 2*(1e5+10);
int m, n;
vector <int> grafo[MAXN];
vector <map<int, bool>> mapa(MAXN);
bool vi[MAXN];
int resp = 0;

void solve(int atual, int last) {
    mapa[atual][last] = 1;
    mapa[last][atual] = 1;
    vi[atual] = 1;
    for(auto x : grafo[atual]) {
        if (vi[x] and !mapa[atual][x] and !mapa[x][atual]) {
            mapa[atual][x] = 1;
            mapa[x][atual] = 1;
            resp++;
        } else if (!vi[x]){
            solve(x, atual);
        }
    }
}

signed main() { op
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        grafo[a].emplace_back(b);
        grafo[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++) {
        solve(i, i);
    }
    cout << resp << endl;
}
/*Travei um tempo na possibilidade de o grafo ter vários componentes.*/
