#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair <int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 2*(1e5+5);
const int mod = 1e9+7;
const int raiz = 20;
const int MAXL = 20;

vector <int> grafo[MAXN];
int team[MAXN];
bool flag;

void solve(int atual, int ant, int t) {
    // dbg(atual)
    // dbg(t)
    if(team[atual] != 0) {
        if(team[atual] == t) {
            return;
        } else {
            flag = 1;
            return;
        }
    }
    if(team[atual] == 0) {
        team[atual] = t;
        if(t == 1) {
            for(auto x : grafo[atual]) {
                if(x != ant) {
                    solve(x, atual, 2);
                }
            }
        } else {
            for(auto x : grafo[atual]) {
                if(x != ant) {
                    solve(x, atual, 1);
                }
            }
        }
    } 
}

signed main() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        grafo[a].emplace_back(b);
        grafo[b].emplace_back(a);
    }
    for(int i = 1; i <= n; i++) {
        if(team[i] != 0) continue;
        solve(i, i, 1);
    }
    if(flag) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for(int i = 1; i <= n; i++) {
            cout << team[i] << " ";
        }
        cout << endl;
    }
}
