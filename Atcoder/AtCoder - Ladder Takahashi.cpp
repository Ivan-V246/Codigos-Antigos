#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair<int, pair<int,int>>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e5+10;
int n, resp = 1;
map <int, vector<int>> grafo;
map <int, bool> vi;
signed main() { op
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        grafo[a].emplace_back(b);
        grafo[b].emplace_back(a);
    }
    queue <int> fila;
    fila.emplace(1);
    vi[1] = 1;
    while(!fila.empty()) {
        int atual = fila.front();
        resp = max(resp, atual);
        fila.pop();
        for (auto x : grafo[atual]) {
            if(!vi[x]) {
                fila.emplace(x);
                   vi[x] = 1;
            }
        }
    }
    cout << resp << endl;
}
/*Ao invés de usar um MAXN, deixei maps pra criar automaticamente.*/
