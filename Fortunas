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


int bl[MAXL][MAXN];
int fort[MAXN];
vector <int> lista[MAXN];
int ans[MAXN];
vector <int> grafo[MAXN];
int seg[4*MAXN];


void update(int no, int l , int r, int obj, int valor) {
    if(obj < l or obj > r) return;
    if(l == r) {
        seg[no] = seg[no] + valor;
        return;
    }
    
    int esq = no*2, dir = esq+1, mid = (l+r)/2;

    update(esq, l, mid, obj, valor);
    update(dir, mid+1, r, obj, valor);

    seg[no] = seg[esq] + seg[dir];
}

int query(int no, int l, int r, int ini, int fim) {
    if(l >= ini and r <= fim) return seg[no];
    if(l > fim or r < ini) return 0;

    int esq = no*2, dir = esq+1, mid = (l+r)/2;

    int n1 = query(esq, l, mid, ini, fim);
    int n2 = query(dir, mid+1, r, ini, fim);

    return n1+n2;
}

void dfs(int atual) {
    if(!lista[atual].empty()) {
        for(auto x : lista[atual]) {
            update(1, 1, 100001, x, 1);
        }
    }

    ans[atual] = query(1, 1, 100001, 0, fort[atual]);

    for(auto x : grafo[atual]) {
        dfs(x);
    }

    if(!lista[atual].empty()) {
        for(auto x : lista[atual]) {
            update(1, 1, 100001, x, -1);
        }
    }

}


signed main() { op
    int n, q; cin >> n >> q;    
    for(int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        bl[0][i] = b;
        fort[i] = a;
        if(i != b) {
            grafo[b].emplace_back(i);
        }
    }
    for(int i = 1; i < MAXL; i++) {
        for(int u = 1; u <= n; u++) {
            int a = bl[i-1][u];
            int b = bl[i-1][a];
            bl[i][u] = b;
        }
    }
    for(int i = 0; i < q; i++) {
        int a, b, c; cin >> a >> b >> c;
        for(int j = 19; j >= 0; j--) {
            if(fort[bl[j][a]] <= c) {
                a = bl[j][a];
            }
        }
        lista[a].emplace_back(b);
    }
    dfs(1);
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
