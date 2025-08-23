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

// #define vi vector <int>
const int MAXN = 1e7+10;
int e, n, m;
vector <pii> nq;
vector <pii> q;
int tam[MAXN];
int pai[MAXN];

int find(int u) {
    if(pai[u] == u) return u;
    return pai[u] = find(pai[u]);
}


void unir(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return;
    if(tam[u] > tam[v]) swap(u, v);
    pai[u] = v;
    tam[v] += tam[u];
}


signed main() { op
    cin >> e >> n >> m;
    for(int i = 1; i <= e; i++) {
        tam[i]= 1;
        pai[i] = i;
    }
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        q.emplace_back(a, b);
    }
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        nq.emplace_back(a, b);
    }
    int par = (e/3);
    for(int i = 1; i <= par; i++) {
        int a, b, c; cin >> a >> b >> c;
        unir(a, b);
        unir(b, c);
    }
    int ans = 0;
    for(auto x : nq) {
        if(find(x.f) == find(x.s)) {
            ans++;
        }
    }
    for(auto x : q) {
        if(find(x.f) != find(x.s)) {
            ans++;
        }
    }
    cout << ans << endl;
}
