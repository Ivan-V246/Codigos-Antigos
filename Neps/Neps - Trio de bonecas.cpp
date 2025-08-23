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
const int MAXN = 1*(1e4+5);
const int MAXM = 3*(1e3+5);
const int mod = 1e9+7;
const int raiz = 1000;

vector <int> lista;
int dp[MAXN][MAXM];
int n, m;

int solve(int atual, int tri) {
    if(tri == m) return 0;
    if(atual >= n) return inf;
    if(~dp[atual][tri]) return dp[atual][tri];
    int pega;
    if((atual-1) - (tri*3) > 0) {
        pega = solve(atual+2, tri+1) + (lista[atual]-lista[atual+1]) * (lista[atual]-lista[atual+1]);
    }
    int nao = solve(atual+1, tri);

    return dp[atual][tri] = min(nao, pega);
}

signed main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        lista.emplace_back(a);
    }
    lista.emplace_back(inf);
    sort(lista.begin(), lista.end());
    reverse(lista.begin(), lista.end());
    int ans = solve(1, 0);
    cout << ans << endl;
}
