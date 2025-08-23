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
const int MAXN = (1e6+5);
const int mod = 1e9+7;
const int raiz = 20;
const int MAXL = 20;

int lista[MAXN];
map <int, int> mapa;
int inv[MAXN];
int bit[MAXN];
int maio[MAXN];

void upd(int x, int v) {

    for(;x <= MAXN; x+=(x&-x)) {
        bit[x]+= v;
    }
}

int soma(int x) {
    int ans = 0;
    for(; x > 0; x -=(x&-x)) {
        ans+=bit[x];
    }
    return ans;
}

signed main() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        mapa[a] = i;
    }
    int cont = 1;
    for(auto x : mapa) {
        lista[x.s] = cont;
        cont++;
    }
    for(int i = n; i >= 1; i--) {
        inv[i] = soma(lista[i]);
        upd(lista[i], 1);
    }
    int ans = 0;
    memset(bit, 0, sizeof bit);
    for(int i = 1; i <= n; i++) {
        int temp = soma(lista[i]);
        if(temp < (i-1)) {
            maio[i] = ((i-1) - temp);
        }
        ans += maio[i]*inv[i];
        upd(lista[i], 1);
    }
    cout << ans << endl;
}
