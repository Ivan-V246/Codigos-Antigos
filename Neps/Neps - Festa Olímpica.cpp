#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define inf 0x3f3f3f3f
#define pii pair <int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
#define db cout << "blz" << endl;
const int MAXN = 1*(1e3+5);
const int mod = 1e9+7;
const int raiz = 1000;

vector <int> lista;

signed main() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a; cin >> a;
        lista.emplace_back(a);
        n -= (n/a);
    }
    reverse(lista.begin(), lista.end());
    for(int i = 1; i <= min(n, 10000LL); i++) {
        int a = i;
        for(auto x : lista) {
            a += ((a-1)/(x-1));
        }
        cout << a << endl;
    }
}
