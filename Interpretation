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
const int MAXN = 1e5+10;
const int mod = 1;
int n, m, l;
int pai[MAXN];
int sz[MAXN];
int lista[MAXN];

int find(int x) {
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void unir(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return;
    if(sz[u] > sz[v]) swap(u, v);
    sz[v] += sz[u];
    pai[u] = v;
}


signed main() { op
    cin >> n >> l;
    for(int i = 0; i <= MAXN; i++) {
        sz[i] = 1;
        pai[i] = i;
    }
    for(int i = 1; i <= n; i++) {
        int m; cin >> m;
        for(int j = 0; j < m; j++) {
            int a; cin >> a;
            if(lista[a] != 0) {
                unir(lista[a], i);
            }
            lista[a] = i;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(sz[i] == n) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
