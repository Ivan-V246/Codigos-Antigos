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
const int MAXN = (1e5+5);
const int mod = 1e9+7;
const int raiz = 20;
const int MAXL = 20;

int bit[MAXN];
vector <int> lista(MAXN);
int n;

void upd(int x, int v) {

    for(; x <= MAXN; x+=(x&-x)) {
        bit[x]+=v;
    }

}

int soma(int x) {

    int sla = 0;
    for(; x >= 1; x-=(x&-x)) {
        sla += bit[x];
    }
    return sla;
}

signed main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        lista[i] = a;
        upd(a, 1);
    }
    int ans = 0;
    for(int i = n; i >= 1; i--) {
        n--;
        upd(lista[i], (-1));
        int temp = soma(lista[i]);
        temp = (n-temp);
        ans += max(0LL, temp);
    }
    cout << ans << endl;
}
