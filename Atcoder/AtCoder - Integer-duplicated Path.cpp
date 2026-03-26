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
const int MAXN = 2e5+5;

map <int, int> vis;
int dupli = 0;
vector <int> lista(MAXN);
vector <bool> ans(MAXN);
vector <int> grafo[MAXN];

void dfs(int atual, int pai) {

    vis[lista[atual]]++;
    if(vis[lista[atual]] == 2) dupli++;
    
    ans[atual] = dupli > 0;

    for(auto x : grafo[atual]) {
        if(x != pai) dfs(x, atual);
    }

    vis[lista[atual]]--;
    if(vis[lista[atual]] == 1) dupli--;
}

signed main() { op
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> lista[i+1];
    }
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        grafo[a].emplace_back(b);
        grafo[b].emplace_back(a);
    }
    dfs(1, 1);
    for(int i = 1; i <= n; i++) {
        cout << (ans[i] ? "Yes" : "No") << endl;
    }
}