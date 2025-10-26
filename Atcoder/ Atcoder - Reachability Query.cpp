#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

#define ALL(x) x.begin(), x.end()
#define DBG(x) cout << #x << " = " << x << endl;
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f



using namespace std;
// using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int MAXN = 2e5+5;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

bool black[MAXN];
int pai[MAXN];
ii sz[MAXN];

int find(int u) {
    if(pai[u] == u) return u;
    return pai[u] = find(pai[u]);
}

void unir(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(sz[u].F > sz[v].F) swap(u, v);

    sz[v].F += sz[u].F;
    sz[v].S += sz[u].S;
    pai[u] = pai[v];
}


signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        pai[i] = i;
        sz[i].F = 1;
        sz[i].S = 0;
    }
    while(m--) {
        int x; cin >> x;
        if(x == 1) {
            int a, b; cin >> a >> b;
            unir(a, b);
        } else {
            int a; cin >> a;
            if(x == 2) {
                if(black[a]) {
                    black[a] = 0;
                    sz[find(a)].S--;
                } else {
                    black[a] = 1;
                    sz[find(a)].S++;
                }
            } else {
                a = find(a);
                if(sz[a].S > 0) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        }
    }
}