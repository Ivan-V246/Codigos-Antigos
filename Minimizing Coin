#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e6+5;
const int mod = 1e9+7;
const int raiz = 20;
const int MAXL = 20;

vector <int> lista;
int dp[MAXN];

signed main() { op
    int n, x; cin >> n >> x;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        lista.emplace_back(a);
    }
    
    for(int i = 1; i <= x; i++) {
        dp[i] = INF;
        for(auto x : lista) {
            if(x <= i) {
                dp[i] = min(dp[i], dp[i-x]+1);
            }
        }
    }
    cout << dp[x] << endl;
}
