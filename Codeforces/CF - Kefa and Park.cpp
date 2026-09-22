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
#define dbg(x) cout << #x << " -> " << x << endl;
#define vi vector<int>
const int MAXN = 1e5+5;

signed main() { op 
    int n, m; cin >> n >> m;

    vi grafo[MAXN], lista(n+1);
    vector<bool> vis(MAXN);

    for(int i = 1; i <= n; i++) cin >> lista[i];
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        grafo[u].emplace_back(v);
        grafo[v].emplace_back(u);
    }

    function<int(int, int)> dfs = [&](int curr, int cats) -> int {
        vis[curr] = 1;
    
        if(lista[curr] == 0) {
            cats = 0;
        } else {
            cats++;
        }

        if(cats > m) return 0;
        
        int cont = 0;
        int ans = 0;
        for(auto x : grafo[curr]) {
            if(!vis[x]) {
                ans += dfs(x, cats);
                cont++;
            }
        }

        if(cont == 0) return 1;

        return ans;
    };


    int res = dfs(1, 0);
    cout << res << endl; 
}
