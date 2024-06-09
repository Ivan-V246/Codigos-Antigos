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
const int MAXN = 1e5+10;
const int MAXL = 20;
const int raiz = 318;
int desk[MAXN], moni[MAXN];
vector <int> grafo[MAXN];
struct up {
    int inc;
    string tipo;
    int cara;
};
vector <up> update;
int tot[MAXN][2];
 
 
void calc(int atual) {
    tot[atual][0] = desk[atual];
    tot[atual][1] = moni[atual];
    for(auto x : grafo[atual]) {
        if(x != INF) {
            tot[atual][0] += desk[x];
            tot[atual][1] += moni[x];
        }
    }
}
 
 
signed main() { op
    int n, m, q; cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        cin >> desk[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> moni[i];
    }
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        grafo[a].emplace_back(b);
        grafo[b].emplace_back(a);
    }
    for(int i = 1; i <= n; i++) {
        sort(grafo[i].begin(), grafo[i].end());
        grafo[i].emplace_back(INF);
        calc(i);
    }
    for(int i = 0; i < q; i++) {
        string com; cin >> com;
        if(com == "check") {
            int a; cin >> a;
            int n1 = tot[a][0];
            int n2 = tot[a][1];
            for(auto x : update) {
                if(*(lower_bound(grafo[a].begin(), grafo[a].end(), x.cara)) == x.cara or x.cara == a) {
                    if(x.tipo == "desk") {
                        n1 += x.inc;
                    } else {
                        n2 += x.inc;
                    }
                }
            }
            if(n1 == n2) {
                cout << "same" << endl;
            } else if(n1 > n2) {
                cout << "desks" << endl;
            } else {
                cout << "monitors" << endl;
            }
        } else {
            int a, b;
            string mat; cin >> a >> mat >> b;
            up sla = {a, mat, b};
            update.emplace_back(sla);
            if(update.size() == raiz) {
                for(auto x : update) {
                    if(x.tipo == "desk") {
                        desk[x.cara] += x.inc;
                    } else {
                        moni[x.cara] += x.inc;
                    }
                }
                update.clear();
                for(int i = 1; i <= n; i++) {
                    calc(i);
                }
            }
        }
    }
}
