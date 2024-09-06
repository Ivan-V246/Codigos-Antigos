#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define inf 0x3f3f3f3f
#define pii pair <int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
#define db cout << "blz" << endl;
const int MAXN = 2*(1e5+5);
const int mod = 1e9+7;
const int raiz = 1000;

int seg[MAXN*4];
int lista[MAXN];

void upd(int atual, int l, int r, int alvo) {
    if(alvo > r or alvo < l) return;
    if(l == r and l == alvo) {
        seg[atual] = lista[alvo];
        return;
    }
    int esq = 2*atual, dir = esq+1, mid = (l+r)/2;
    upd(esq, l, mid, alvo);
    upd(dir, mid+1, r, alvo);
    seg[atual] = max(seg[esq], seg[dir]);
}

int query(int atual, int l, int r, int alvo) {
    if(seg[atual] < alvo) return inf;
    if(l==r) {
        return l;
    }
    int esq = atual*2, dir = esq+1, mid = (l+r)/2;
    if(seg[esq] >= alvo) {
        return query(esq, l, mid, alvo);
    } else {
        return query(dir, mid+1, r, alvo);
    }
}

signed main() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> lista[i];
        upd(1, 1, n, i);
    }
    for(int i = 1; i <= m; i++) {
        int a; cin >> a;
        int ans = query(1, 1, n, a);
        if(ans == inf) {
            cout << 0 << " ";
        } else {
            cout << ans << " ";
            lista[ans]-= a;
            upd(1, 1, n, ans);
        }
    }
}
