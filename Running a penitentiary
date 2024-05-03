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
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int tam = 2*1e5+10;
const int MAXN = 4*(tam);
int n, m;
vector <pii> lista(tam);
vector <pii> seg(MAXN);

void build(int no, int l, int r) {
    if(l == r) {
        seg[no] = lista[l];
        return;
    }

    int dir = no*2, esq = dir+1, mid = (l+r)/2;
    build(dir, l, mid);
    build(esq, mid+1, r);

    seg[no] = mkp(max(seg[dir].f, seg[esq].f), min(seg[dir].s, seg[esq].s));
}

pii query(int no, int l, int r, int ini, int fim) {
    if(l >= ini and r <= fim) return seg[no];
    if(l > fim or r < ini) return mkp(-1e18, 1e18);

    int dir = no*2, esq = dir+1, mid = (l+r)/2;

    pii p1 = query(dir, l, mid, ini, fim);
    pii p2 = query(esq, mid+1, r, ini, fim);

    pii ans = mkp(max(p1.f, p2.f), min(p1.s, p2.s)); 
    return ans;

}

void update(int no, int l, int r, int obj) {
    if(obj > r or obj < l) return;
    if(l == r and obj == l) {
        seg[no] = lista[l];
        return;
    }

    int dir = no*2, esq = dir+1, mid = (l+r)/2;

    update(dir, l, mid, obj);
    update(esq, mid+1, r, obj);

    seg[no] = mkp(max(seg[dir].f, seg[esq].f), min(seg[dir].s, seg[esq].s));
}


signed main() { op
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        lista[i] = mkp(a, b);
    }
    build(1, 1, n);
    for (int i = 0; i < m; i++) {
        char com; cin >> com;
        if(com == '?') {
            int a, b; cin >> a >> b;
            pii resp = query(1, 1, n, a, b);
            int sla = resp.s - resp.f;
            if(sla >= 0) {
                cout << sla+1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else {
            int a, b, c; cin >> a >> b >> c;
            lista[a] = mkp(b, c);
            update(1, 1, n, a);
        }
    }
}
/*SegTree padrão, cuidado com o tamanho e a ordem dos IFs.*/
