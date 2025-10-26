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
#define vi vector<int>
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e3+5;

int pos[22];
int saltos[MAXN][22];
int dp[MAXN];
int n, l, r; 

int solve(int atual) { //Retorna o maior menor 
    if(atual >= n) return 1e9;
    if(~dp[atual]) return dp[atual];
    int resp = 0;
    int aux = 0;
    for(int i = 0; i < 22; i++) {
        if(saltos[atual][i] == -1) continue;
        for(int j = 0; j <= saltos[atual][i]; j++) {
            aux = min(j+1, solve(atual+j+1));
            resp = max(resp, aux);
        }
    }
    return dp[atual] = resp;
}

signed main() {
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++) {
        dp[i] = -1;
        for(int j = 0; j < 22; j++) {
            saltos[i][j] = -1;
        }
    }
    vi lista(n);
    vector <int> validos[n];
    for(auto &x : lista) cin >> x;
    for(int i = 0; i < n; i++) {
        for(int j = -10; j <= 10; j++) {
            int novo = lista[i] + j*12;
            if(novo >= l and novo <= r) {
                validos[i].emplace_back(j+10);
            }
        }
    }
    for(int i = 0; i < 21; i++) pos[i] = -1;
    for(auto x : validos[n-1]) saltos[n-1][x] = 0;
    for(int i = n-2; i >= 0; i--) {
        for(auto x : validos[i]) saltos[i][x] = saltos[i+1][x]+1;
    }
    cout << solve(0) << endl;
}