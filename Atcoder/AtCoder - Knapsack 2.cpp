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
const int MAXN = 1e5+10;
int n, m;
vector <pii> item(110);
int dp[110][MAXN];

int solve(int atual, int valor) {
    if(~dp[atual][valor]) return dp[atual][valor];
    if(valor == 0) return dp[atual][valor] = 0;
    if(atual > n) return 1e18;

    int pega = INF;
    if(valor-item[atual].s >= 0) {
        pega = solve(atual+1, valor-item[atual].s) + item[atual].f;
    }
    int nao = solve(atual+1, valor);
    int peso = min(pega, nao);

    return dp[atual][valor] = peso;
}


signed main() { op
    memset(dp, -1, sizeof dp); 
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        item[i] = mkp(a,b);
    }
    int resp = 0;
    for (int i = 0; i <= 1e5; i++) {
        int temp = solve(1, i);
        if(temp <= m) {
            resp = i;
        }
    }
    cout << resp << endl;
}
/*Código desgraçado. É uma Dp esquisita da mochila, em que você testa todos os possíveis valores e guarda o peso para "construir" aquele valor. Dica: Se algo parece Dp, mas um dos estado é muito grande, troque ele pelo que tá sendo armazenado.*/
