#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair<long double,int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e6+5;

vector <int> pulo;

struct situ{
    long double pos;
    int mov, resp;
};

signed main() { op
    int n; cin >> n;
    for(int i = 0;  i < n; i++) {
        int a; cin >> a;
        pulo.emplace_back(a);
    }
    queue <situ> fila;
    situ a = {0.5, 0, 0};
    fila.emplace(a);
    int ans = 0;
    while(fila.size()) {
        long double p = fila.front().pos;
        int m = fila.front().mov;
        int r = fila.front().resp;
        fila.pop();
        if(m == n) {
            ans = max(ans, r);
            continue;
        }
        situ b;
        if(p < 0 and p + pulo[m] > 0) {
            b = {p+(long double)pulo[m], m+1, r+1};
        } else {
            b = {p+(long double)pulo[m], m+1, r};
        }
        fila.emplace(b);

        if(p > 0 and p - pulo[m] < 0) {
            b = {p-(long double)pulo[m], m+1, r+1};
        } else {
            b = {p-(long double)pulo[m], m+1, r};
        }
        fila.emplace(b);
    }
    cout << ans << endl;
}