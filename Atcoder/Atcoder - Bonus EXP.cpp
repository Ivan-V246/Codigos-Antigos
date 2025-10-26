#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

#define ALL(x) x.begin(), x.end()
#define DBG(x) cout << #x << " = " << x << endl;
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define op ios::sync_with_stdio(0); cin.tie(0);


using namespace std;
// using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int MAXN = 2e5+5;
// #define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>

vi lista;
int n;
int dp[MAXN][2];

int solve(int i, int impar) {
    if(i == n) return 0;
    if(dp[i][impar] != -1) return dp[i][impar];
    int resp = 0;
    resp = max(resp, solve(i+1, impar));
    if(impar == 1) { 
        resp = max(resp, solve(i+1, 0)+lista[i]);
    } else {
        resp = max(resp, solve(i+1, 1)+ (lista[i]*2));
    }
    return dp[i][impar] = resp;
}


signed main() { op
    cin >> n;
    for(int i = 0; i <= n; i++) {
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    lista.resize(n);
    for(auto &x : lista) cin >> x;
    cout << solve(0, 1) << endl;
}