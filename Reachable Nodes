#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair<int, pair<int, int>>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 5*(1e4+10);
int n, m;
vector <int> grafo[MAXN];
int grau[MAXN];
bitset <MAXN> dp[MAXN];

bitset <MAXN> solve(int atual) {
    if(dp[atual][atual]) return dp[atual];
    for (auto x : grafo[atual]) {
        dp[atual] |= solve(x);
    }
    dp[atual][atual] = 1;

    return dp[atual];
}

signed main() {
    op
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        grafo[a].push_back(b);
        grau[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if(grau[i] == 0) {
            solve(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i].count() << " ";
    }
    cout << endl;
}

/* Técnica (leia-se: malandragem) de utilizar um bitset ao invés de uma coletânea de bools, reduzindo a complexidade.*/ 
