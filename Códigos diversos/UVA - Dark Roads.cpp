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
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 2*1e5+10;
int n, m;
vector <int> size(MAXN);
vector <int> id(MAXN);


int find(int x) {
    if(id[x] == x) return x;
    return id[x] = find(id[x]);
}

void uni(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;
    if(size[x] > size[y]) swap(x, y);
    id[x] = y, size[y] += id[x];
}


signed main() { 
    while(1) {
        cin >> n >> m;
        if(n == 0 and m == 0) return 0;
        for (int i = 0; i < n; i++) {
            id[i] = i;
            size[i] = 1;
        }
        vector <pii> arestas;
        int tot = 0;
        for (int i = 0; i < m; i++) {
            int a, b, c; cin >> a >> b >> c;
            arestas.emplace_back(c, mkp(a, b));
            tot += c;
        }
        int ans = 0;
        sort(arestas.begin(), arestas.end());
        for (auto x : arestas) {
            if(find(x.s.f) != find(x.s.s)) {
                ans += x.f;
                uni(x.s.f, x.s.s); 
            }
        }
        cout << tot- ans << endl;
    }
}
/*Uso de DSU e Kruskal, com Path Compression e Small to large.*/
