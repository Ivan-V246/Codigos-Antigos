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
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 2*1e5+10;
const int MAXL = 20;
const int raiz = 450;

int tempo = 0;
int valor[MAXN];
int nasceu[MAXN];
int morreu[MAXN];
int seg[4*MAXN];
vector <int> grafo[MAXN];

void tour(int atual) {
    tempo++;
    nasceu[atual] = tempo;
    for(auto x : grafo[atual]) {
        if(nasceu[x] == 0) {
            tour(x);
        }
    }
    morreu[atual] = tempo;
}

void update(int no, int l, int r, int pos, int valor) {
    if(pos > r or pos < l) return;
    if(l == r) {
        seg[no] = valor;
        return;
    }

    int mid = (l+r)/2, esq = no*2, dir = esq+1;

    update(esq, l, mid, pos, valor);
    update(dir, mid+1, r, pos, valor);

    seg[no] = seg[esq] + seg[dir];
}

int query(int no, int l, int r, int obj) {
    if(l >= nasceu[obj] and r <= morreu[obj]) return seg[no];
    if(l > morreu[obj] or r < nasceu[obj]) return 0;

    int esq = no*2, dir = esq+1, mid = (l+r)/2;

    int n1 = query(esq, l, mid, obj);
    int n2 = query(dir, mid+1, r, obj);

    return n1+n2;
}

signed main() { op
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> valor[i];
    }
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        grafo[a].emplace_back(b);
        grafo[b].emplace_back(a);
    }
    tour(1);
    for(int i = 1; i <= n; i++) {
        update(1, 1, n, nasceu[i], valor[i]);
    }
    for(int i = 0; i < m; i++) {
        int com; cin >> com;
        if(com == 1) {
            int a, b; cin >> a >> b;
            update(1, 1, n, nasceu[a], b);
        } else {
            int a; cin >> a;
            cout << query(1, 1, n, a) << endl;
        }
    }

}
