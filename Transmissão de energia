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
// #define vi vector <int>
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e2+10;
int n, m;
vector <vector<int>> grafo(MAXN);
bool vis[MAXN];
void dfs(int atual) {
    vis[atual-1] = 1;
    for(auto x : grafo[atual]) {
        if(!vis[x-1]) {
            dfs(x);
        }
    }
}

signed main() { op
    int cont = 1;
    while(1)  {
        cin >> n >> m;
        if(n == 0 and m == 0) return 0;
        cout << "Teste " << cont << endl;
        cont++;
        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            grafo[a].emplace_back(b);
            grafo[b].emplace_back(a);
        }
        dfs(1);
        int lig = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i]) {
                lig++;
                vis[i] = 0;
            }
            grafo[i].clear();
        }
        grafo[n].clear();
        if(lig == n) {
            cout << "normal" << endl;
        } else {
            cout << "falha" << endl;
        }
        cout << endl;
    }
}
/*Dfs tranquila.*/
