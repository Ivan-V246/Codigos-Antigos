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
const int MAXN = 1e6+5;


signed main() { 
    int n, m; cin >> n >> m;
    vector< set<int> > linhas(n+1), colunas(n+1);
    while(m--) {
        int a, b; cin >> a >> b;
        for(auto x: linhas[a]) {
            colunas[x].erase(colunas[x].lower_bound(a));
        }
        for(auto x: colunas[b]) {
            linhas[x].erase(linhas[x].lower_bound(b));
        }
        linhas[a].clear();
        colunas[b].clear();
        linhas[a].insert(b);
        colunas[b].insert(a);
    }
    int ans = 0;
    for(auto x : linhas) {
        ans += x.size();
    }
    cout << ans << endl;
}
