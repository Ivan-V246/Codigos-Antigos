#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 1e18
#define pii pair<int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
// #define vi vector <int>
const int MAXN = 5*(1e4+10);
const int MAXL = 22;
int n, ans;
pii pares[MAXN];
int niv[MAXN];
bool vi[MAXN];
int bl[MAXL][MAXN];
int dist[MAXL][MAXN];
vector <int> grafo[MAXN];

void dfs(int atual) {
    for(auto x : grafo[atual]) {
        if(dist[0][x] == 0) {
            dist[0][x] = 1;
            bl[0][x] = atual;
            niv[x] = niv[atual]+1;
            dfs(x);
        }
    }
}

void lca(int u, int v) {
    if(niv[u] > niv[v]) {
        swap(u, v);
    }

    int k = niv[v] - niv[u];
    for(int i = 31; i >= 0; i--) {
        if((k | (1 << i)) == k) {
            ans += dist[i][v];
            v = bl[i][v];
        }
    }

    if(u == v) return;

    for(int i = MAXL-1; i >= 0; i--) {
        if(bl[i][u] != bl[i][v]) {
            ans += dist[i][u] + dist[i][v];
            u = bl[i][u];
            v = bl[i][v];
        }
    }
    ans+= 2;
}


signed main() { 
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        if(!vi[a]) {
            pares[a].f = i;
            vi[a] = 1;
        } else {
            pares[a].s = i;
        }
    }
    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        grafo[a].emplace_back(b);
        grafo[b].emplace_back(a);
    }
    bl[0][1] = 1;
    niv[1] = 0;
    dist[0][1] = 1;
    dfs(1);
    for(int i = 1; i < MAXL; i++) {
        for(int u = 1; u <= n; u++) {
            int a = bl[i-1][u];
            bl[i][u] = bl[i-1][a];
            dist[i][u] = dist[i-1][a] + dist[i-1][u];
        }
    }
    for(int i = 1; i <= n/2; i++) {
        lca(pares[i].f, pares[i].s);
    }
    cout << ans << endl;
}
