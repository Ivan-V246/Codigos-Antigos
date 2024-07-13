#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair <int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e6+5;
const int mod = 2*1e5+5;
const int raiz = 20;
const int MAXL = 20;

struct com {
    int a, b, c;
};
int bit[MAXN];
com lista[mod];
int sal[mod];
vector <int> mapa;
vector <int> coord;

int pos(int x) {
    auto pont = lower_bound(coord.begin(), coord.end(), x);
    return distance(coord.begin(), pont);
}

void upd(int x, int v) {
    for(; x <= MAXN; x+=(x&-x)) {
        bit[x] += v;
    }
}

int soma(int x) {
    int ans = 0;
    for(; x >= 1; x -= (x&-x)) {
        ans += bit[x];
    }
    return ans;
}

signed main() { op
    int n, q; cin >> n >> q;
    mapa.emplace_back(0);
    for(int i = 1; i <= n; i++) {
        cin >> sal[i];
        mapa.emplace_back(sal[i]);
    }
    for(int i = 1; i <= q; i++) {
        char sla; cin >> sla;
        int n1, n2; cin >> n1 >> n2;
        com temp;
        if(sla == '!') {
            lista[i].a = 1;
            mapa.emplace_back(n2);
        } else {
            lista[i].a = 2;
            mapa.emplace_back(n1);
            mapa.emplace_back(n2);
        }
        lista[i].b = n1;
        lista[i].c = n2;
    }
    sort(mapa.begin(), mapa.end());
    coord.emplace_back(0);
    for(auto x : mapa) {
        if(x != coord.back()) {
            coord.emplace_back(x);
        }
    }
    for(int i = 1; i <= n; i++) {
        sal[i] = pos(sal[i]);
        upd(sal[i], 1);
    }
    for(int i = 1; i <= q; i++) {
        com x = lista[i];
        if(x.a == 1) {
            upd(sal[x.b], -1);
            sal[x.b] = pos(x.c);
            upd(sal[x.b], 1);
        } else {
            int n1 = soma(pos(x.c));
            int n2 = soma(pos(x.b)-1);
            cout << (n1-n2) << endl;
        }
    }
}
