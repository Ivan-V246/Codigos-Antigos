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
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 2*(1e5+5);
const int mod = 1e9+7;
const int raiz = 20;
const int MAXL = 20;

vector <int> grafo[MAXN];
int dp[MAXN];
int ponta = 0;
int mai = 0;

void dfs(int atual, int ant, int dist) {
    dp[atual] = max(dp[atual], dist);
    if(dist > mai) {
        mai = dist; 
        ponta = atual;
    }
    for(auto x : grafo[atual]) {
        if(x != ant) {
            dfs(x, atual, dist+1);
        }
    }
}

signed main() {
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        grafo[a].emplace_back(b);
        grafo[b].emplace_back(a);
    }
    dfs(1, 1, 0);
    mai = 0;
    dfs(ponta, ponta, 0);
    dfs(ponta, ponta, 0);
    for(int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
}
//DFs pra achar as pontas do grafo, pq sempre a maior distância de um nó é pra uma das pontas da árvore;
