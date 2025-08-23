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
#define vi vector <int>
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e5+10;
int n, m;
int lista[MAXN];
pii seg[4*MAXN];

void update(int no, int l, int r, int obj) {
    if(obj > r or obj < l) return;
    if(l == r) {
        if(l % 2 == 1) {
            seg[no] = mkp(lista[obj], 0);
        } else {
            seg[no] = mkp(0, lista[obj]);
        }
        return;
    }

    int esq = no*2, dir = esq+1, mid = (l+r)/2;
    update(esq, l, mid, obj);
    update(dir, mid+1, r, obj);

    seg[no] = mkp(seg[esq].f + seg[dir].f,  seg[esq].s + seg[dir].s);
}

pii query(int no, int l , int r, int ini, int fim) {
    if(l >= ini and r <= fim) return seg[no];
    if(l > fim or r < ini) return mkp(0, 0);

    int esq = no*2, dir = esq+1, mid = (l+r)/2;

    pii p1 = query(esq, l, mid, ini, fim);
    pii p2 = query(dir, mid+1, r, ini, fim);

    return mkp(p1.f + p2.f, p1.s + p2.s);

}

signed main() { op
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> lista[i];
        update(1, 1, n, i);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        int a, b ,c; cin >> a >> b >> c;
        if(a) {
            pii resp = query(1, 1, n, b, c);
            int ans = resp.f - resp.s;
            if(b % 2 == 1) {
                cout << ans << endl;
            } else {
                cout << -ans << endl;
            }
        } else {
            lista[b] = c;
            update(1, 1, n, b);
        }
    }
}
/*SegTree em que eu tenho que manter a soma de todos os ímpares e de todos os pares. Depois de perceber isso, ficou simples, mas demorei a inferir isso do problema.*/
