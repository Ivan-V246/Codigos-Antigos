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
const int MAXN = 1e5+5;
const int mod = 1e9+7;
const int raiz = 20;
const int MAXL = 20;

int n, x;
int lista[MAXN];
int dp[MAXN][110];

int solve(int atual, int ant) {
    if(~dp[atual][ant]) return (dp[atual][ant]%mod);
    if(lista[atual] != 0 and abs(lista[atual]-ant) > 1) {
        return 0;
    }
    if(atual > n) {
        return 1;
    }
    int resp = 0;
    if(lista[atual] != 0) {
        resp = solve(atual+1, lista[atual]);
        resp %= mod;
    } else {
        if(ant - 1 > 0) {
            resp += solve(atual+1, ant-1);
            resp %= mod;
        }
        resp += solve(atual+1, ant);
        resp %= mod;
        if(ant + 1 <= x) {
            resp+= solve(atual+1, ant+1);
        }
        resp %= mod;
    }

    return dp[atual][ant] = (resp%mod);
}

signed main() { op
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> lista[i];
    }
    memset(dp, -1, sizeof dp);
    int ans = 0;
    if(lista[1] == 0) {
        for(int i = 1; i <= x; i++) {
            ans+= solve(2, i);
            ans %= mod;
        }
    } else {
        ans += solve(2, lista[1]);
        ans %= mod;
    }
    cout << ans << endl;
}
