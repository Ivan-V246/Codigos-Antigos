#include <bits/stdc++.h>
#include <functional>
using namespace std;

#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define int long long
#define pii pair<int,int>
#define piii pair<int, pair<int, int> >
#define vi vector<int>
#define mkp make_pair
#define f first
#define s second
#define endl '\n'

#define dbg(x) cout << #x << " -> " << x << endl;
#define dbgv(x) cout << #x << endl; for(auto y : x) cout << y << " "; cout << endl;
#define ALL(x) (x).begin(), (x).end()

const int MAXN = 1e5+5;
const int MAXL = 17;
const int MOD = 1e9+7;

vector<vi> pai(MAXL, vi(MAXN));
vector<vi> grafo(MAXN);
vi level(MAXN), te(MAXN), ts(MAXN);

signed main() { 
    int n; cin >> n; 
    for(int i = 2; i <= n; i++) {
        cin >> pai[0][i];
        grafo[pai[0][i]].emplace_back(i);
    }

    for(int i = 1; i < MAXL; i++) {
        for(int j = 1; j < MAXN; j++) {
            pai[i][j] = pai[i-1][pai[i-1][j]];
        }
    }

    level[1] = 1;
    int cont = 0;
    function<void(int)> dfs = [&](int atual) -> void {
        cont++;
        te[atual] = cont;
        for(auto x : grafo[atual]) {
            level[x] = level[atual]+1;
            dfs(x);
        }
        cont++;
        ts[atual] = cont;
    };
    dfs(1);

    function<int(int, int)> ancestor = [&](int v, int pulo) -> int {
        for(int i = 30; i >= 0; i--) {
            if((pulo | (1 << i)) == pulo) {
                v = pai[i][v];
            }
        }
        return v;
    };
    
    set <piii> res;
    int m; cin >> m;
    while(m--) {
        int com; cin >> com;
        if(com == 2) {
            int a; cin >> a;
            vi ex;
            if(res.size()) {
                for(auto x : res) {
                    // cout << x.s.s << endl;
                    if(x.f > te[a] and x.s.f < ts[a]) ex.emplace_back(x.s.s);
                }
                for(auto x : ex) {
                    res.erase(res.find(mkp(te[x], mkp(ts[x], x))));
                }
            }

            res.insert(mkp(te[a], mkp(ts[a], a)));
        } else {
            int a, b; cin >> a >> b;
            int p = 0;
            for(auto x : res) {
                if(te[a] > x.f and ts[a] < x.s.f) {
                    p = x.s.s;
                    break;
                }
            }
            if(!p) p = pai[0][a];
            cout << ancestor(p, b-1) << endl;
        }
    }
}
