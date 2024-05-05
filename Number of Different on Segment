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
const int MAXN = 1e5+10;
int n, m;
int lista[MAXN];
vector <ll> seg(4*(MAXN));

void update(int no, int l , int r, int obj) {
    if(obj > r or obj < l) return;
    if(l == r) {
        ll temp = (1LL << (lista[obj]-1));
        seg[no] = temp;
        return;
    }

    int esq = no*2, dir = esq+1, mid = (l+r)/2;

    update(esq, l, mid, obj);
    update(dir, mid+1, r, obj);

    seg[no] = (seg[dir] | seg[esq]);
}

ll query(int no, int l, int r, int ini, int fim) {
    if(l >= ini and r <= fim) return seg[no];
    if(l > fim or r < ini) return 0;

    int esq = no*2, dir = esq+1, mid = (l+r)/2;

    ll p1 = query(esq, l, mid, ini, fim);
    ll p2 = query(dir, mid+1, r, ini, fim);

    return (p1 | p2);

}

signed main() { op
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> lista[i];
        update(1, 1, n, i);
    }
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 2) {
            lista[b] = c;
            update(1, 1, n, b);
        } else {
            int ans = 0;
            ll temp = query(1, 1, n, b, c);
            for(int i = 0; i < 40; i++) {
                if((temp | (1LL << i)) == temp) {
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
}
/*SegTree com Bitmask. Simples de aplicação e de ideia.*/
