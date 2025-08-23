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
const int MAXN = 2*(1e5+5);
const int mod = 1e17;
const int raiz = 1000;
const int MAXL = 20;

struct pao{
    int recheio, massa, preco;
};

int n, m, c, d;
vector <pao> lista;
int dp[1005][15][105];
int dispo[MAXN];

int solve(int ma, int atual, int est) { 
    if(atual > m) return 0;
    if(~dp[ma][atual][est]) return dp[ma][atual][est];
    if(ma >= lista[atual].massa and est >= lista[atual].recheio) {
        dp[ma][atual][est] = max(dp[ma][atual][est], solve(ma-lista[atual].massa, atual, est - lista[atual].recheio)+lista[atual].preco);
        dp[ma][atual][est] = max(dp[ma][atual][est], solve(ma-lista[atual].massa, atual+1, dispo[atual+1])+lista[atual].preco);
    }
    dp[ma][atual][est] = max(dp[ma][atual][est], solve(ma, atual+1, dispo[atual+1]));

    return dp[ma][atual][est];
}

signed main() {
    dispo[0] = 100;
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> c >> d;
    pao sla = {0, c, d};
    lista.emplace_back(sla);
    for(int i = 1; i <= m; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        dispo[i] = a;
        pao sla = {b, c, d};
        lista.emplace_back(sla);
    }
    sla = {0, 0, 0};
    lista.emplace_back(sla);
    cout << solve(n, 0, dispo[0]) << endl;
}
