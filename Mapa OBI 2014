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
const int MAXN = 1e5+5;
const int mod = 1e9+7;
const int raiz = 20;
const int MAXL = 20;

vector <pii> grafo[MAXN];
int ans, n; 

int solve(int atual, int ant) {
    int resp = 1;
    for(auto x : grafo[atual]) {
        if(x.f == ant) continue;
        if(x.s == 1) {
            int temp = solve(x.f, atual);
            n -= temp;
            ans += temp*n;
        } else {
            resp += solve(x.f, atual);
        }
    }
    return resp;
}

signed main() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        grafo[a].emplace_back(b, c);
        grafo[b].emplace_back(a, c);
    }
    solve(1, 1);
    cout << ans << endl;
}
