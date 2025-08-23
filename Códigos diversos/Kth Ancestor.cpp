#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e5+10;
const int MAXL = 20;
int t;
vector <int> grafo[MAXN];
int bl[MAXL][MAXN];
bool vi[MAXN];

void dfs(int atual) {
    for(auto x : grafo[atual]) {
        if(!vi[x]) {
            vi[x] = 1;
            bl[0][x] = atual;
            dfs(x);
        }
    }
}


signed main() { op
    cin >> t;
    for(int j = 0; j < t; j++) {
        int p; cin >> p;
        for(int i = 0; i < MAXN; i++) {
            grafo[i].clear();
        }
        set <int> arv;
        memset(bl, 0, sizeof bl);
        memset(vi, 0, sizeof vi);
        int raiz;
        for(int i = 0; i < p; i++) {
            int a, b; cin >> a >> b;
            if(b == 0) {
                raiz = a;
            }
            arv.insert(a);
            grafo[a].emplace_back(b);
            grafo[b].emplace_back(a);
        }
        dfs(raiz);
        bl[0][0] = 0;
        for(int i = 1; i < MAXL; i++) {
            for(auto u : arv) {
                int a = bl[i-1][u];
                int b = bl[i-1][a];
                bl[i][u] = b;
            }
        }
        int q; cin >> q;
        for(int i = 0; i < q; i++) {
            int com; cin >> com;
            if(com == 1) {
                int x; cin >> x;
                arv.erase(x);
            } else {
                int x, y; cin >> x >> y;
                if(com == 0) {
                    bl[0][y] = x;
                    arv.insert(y);
                    for(int i = 1; i < MAXL; i++) {
                        int a = bl[i-1][y];
                        int b = bl[i-1][a];
                        bl[i][y] = b;
                    }
                } else {
                    if(arv.count(x) == 0) {
                        cout << 0 << endl;
                    } else {
                        for(int i = 20; i >= 0; i--) {
                            if((y | (1 << i)) == y) {
                                x = bl[i][x];
                            }
                        }
                        cout << x << endl;
                    }
                }
            }
        }
    }
}
